/**
 * Copyright 2024 by ADVANTEST CORPORATION
 *
 * Convert `bazel aquery` protobuf output into a JSON compilation database.
 * See bzl_tools/bazel/bin/bazel-compile-cmds for more context.
 *
 * Return codes:
 * - 0: success
 * - 1: generic error
 * - 2: CLI usage error
 * - 3: failed to parse protobuf message
 */

#include "CompileCommandsWriter.hpp"

#include "analysis_v2.pb.h"

#include <exception>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <utility>

namespace bazelcc {

  struct Paths
  {
    std::string out_base;
    std::string exec_root;
    std::string src_root;
  };

  auto parse_cli_args(int argc, const char* argv[]) -> Paths;

  auto ensure_trailing_slash(std::string path) -> std::string;

  void skip_input();

  void write_database(const analysis::ActionGraphContainer& action_graph, const Paths& paths);

  auto parse_arguments(const analysis::Action& action) -> std::pair<const std::string*, bool>;

  void write_entry(
      CompileCommandsWriter& writer,
      const Paths& paths,
      const analysis::Action& action,
      std::string_view file
  );

  auto is_external(std::string_view file) -> bool;

  auto is_generated(std::string_view file) -> bool;

}  // namespace bazelcc

auto main(int argc, const char* argv[]) -> int
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  const auto paths = bazelcc::parse_cli_args(argc, argv);

  try {
    analysis::ActionGraphContainer action_graph;
    if (not action_graph.ParseFromIstream(&std::cin)) {
      std::cerr << "WARNING: Failed to parse Protocol Buffer message." << std::endl;
      bazelcc::skip_input();
      return 3;
    }
    if (action_graph.actions_size() > 0) {
      bazelcc::write_database(action_graph, paths);
    }
  } catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}

namespace bazelcc {

  auto parse_cli_args(int argc, const char* argv[]) -> Paths
  {
    if (argc != 4 or argv[1][0] == '\0' or argv[2][0] == '\0' or argv[3][0] == '\0') {
      std::cerr << "Usage: " << (argc > 0 ? argv[0] : "bazelcc")
          << "OUTPUT_BASE EXECUTION_ROOT SOURCE_ROOT\n";
      std::exit(2);
    }

    return {
      ensure_trailing_slash(argv[1]),
      ensure_trailing_slash(argv[2]),
      ensure_trailing_slash(argv[3]),
    };
  }

  auto ensure_trailing_slash(std::string path) -> std::string
  {
    if (path.empty() or path.back() != '/') {
      path += '/';
    }
    return path;
  }

  void skip_input()
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  }

  void write_database(const analysis::ActionGraphContainer& action_graph, const Paths& paths)
  {
    using namespace std::string_view_literals;

    bazelcc::CompileCommandsWriter writer{std::cout};

    // Bazel currently emits two entries per source file, one with and one without `-fPIC`.
    // We are only interested in the `-fPIC` version which seems to always come first
    // (although not necessarily directly before the second entry).
    // Filtering out the second entry cuts the size of the compilation database in half.
    std::unordered_set<std::string_view> fpic_files;

    for (const auto& action : action_graph.actions()) {
      if (action.mnemonic() != "CppCompile"sv) {
        continue;
      }

      // We could use the action.primary_output_id to find the Artifact,
      // lookup the corresponding PathFragment via artifact.path_fragment_id,
      // and finally build the output file path via fragment.label and fragment.parent_id.
      // This, however, is a lot more complicated than just extracting the file from the command.
      const auto [file, has_fpic] = parse_arguments(action);
      if (not file) {
        continue;
      }

      if (has_fpic) {
        fpic_files.emplace(*file);
      } else if (fpic_files.find(*file) != fpic_files.end()) {
        continue;
      }

      write_entry(writer, paths, action, *file);
    }
  }

  auto parse_arguments(const analysis::Action& action) -> std::pair<const std::string*, bool>
  {
    using namespace std::string_view_literals;

    const std::string* file = nullptr;
    bool has_fpic = false;

    const auto end = action.arguments().end();
    for (auto argument = action.arguments().begin(); argument != end; ++argument) {
      if (*argument == "-fPIC"sv) {
        has_fpic = true;
      } else if (*argument == "-c"sv) {
        if (++argument == end) {
          break;
        }
        file = &*argument;
      }
    }

    return {file, has_fpic};
  }

  void write_entry(
      CompileCommandsWriter& writer,
      const Paths& paths,
      const analysis::Action& action,
      std::string_view file
  )
  {
    using namespace std::string_view_literals;

    // clangd does not find all references (incl. call hierarchies)
    // if the compilation database does not point to the actual file.
    writer.next_entry(paths.exec_root, is_generated(file) ? ""sv : paths.src_root, file);

    const auto end = action.arguments().end();
    for (auto argument = action.arguments().begin(); argument != end; ++argument) {
      writer.add_argument("", *argument);

      // Bazel sometimes deletes symlinks to external dependencies,
      // so we resolve these include paths manually.
      if (*argument == "-iquote"sv or *argument == "-isystem"sv) {
        if (++argument == end) {
          break;
        }
        writer.add_argument(is_external(*argument) ? paths.out_base : ""sv, *argument);
      }
    }
  }

  auto is_external(std::string_view file) -> bool
  {
    static constexpr std::string_view prefix{"external/"};
    return file.substr(0, prefix.size()) == prefix;

  }

  auto is_generated(std::string_view file) -> bool
  {
    static constexpr std::string_view prefix = "bazel-out/";
    return file.substr(0, prefix.size()) == prefix;
  }

}  // namespace bazelcc
