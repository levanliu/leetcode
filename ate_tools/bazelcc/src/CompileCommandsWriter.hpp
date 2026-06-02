#pragma once

#include <algorithm>
#include <array>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string_view>

namespace bazelcc {

  /**
   * The first 32 Unicode codepoints U+0000 to U+001F are control characters
   * that need to be encoded in JSON strings (same as in ASCII).
   */
  inline constexpr std::array<std::string_view, 32> JSON_CONTROL_CHARACTERS = {
    "\\u0000", "\\u0001", "\\u0002", "\\u0003", "\\u0004", "\\u0005", "\\u0006", "\\u0007",
    "\\b"    , "\\t"    , "\\n"    , "\\u000B", "\\f"    , "\\r"    , "\\u000E", "\\u000F",
    "\\u0010", "\\u0011", "\\u0012", "\\u0013", "\\u0014", "\\u0015", "\\u0016", "\\u0017",
    "\\u0018", "\\u0019", "\\u001A", "\\u001B", "\\u001C", "\\u001D", "\\u001E", "\\u001F",
  };


  /**
   * Specialized JSON serializer for Clang-compatible compile commands.
   *
   * The compile commands are serialized as an array of objects in JSON format.
   * Each entry has to be started by `next_entry()`,
   * followed by an arbitrary number (including none) of `add_argument()` calls.
   * The written array is complete once the writer's destructor has run.
   */
  class CompileCommandsWriter
  {
  private:

    // Manual buffering improves performance significantly.
    static constexpr std::size_t BufferSize = 1024u * 1024u;
    using Buffer = std::array<char, BufferSize>;

    bool is_first_entry_{true};
    bool is_first_argument_{true};

    // Call `new` manually to prevent initialization.
    std::unique_ptr<Buffer> buffer_{new Buffer};
    char* cursor_{buffer_->data()};
    std::ostream& output_;

  public:

    /**
     * @param os The output stream to write the compile commands to.
     */
    CompileCommandsWriter(std::ostream& os)
      : output_{os}
    {
      write("[");
    }

    ~CompileCommandsWriter()
    {
      if (not is_first_entry_) {
        write("\n    ]\n  }");
      }
      write("\n]\n");
      flush();
    }

    CompileCommandsWriter(const CompileCommandsWriter&) = delete;
    auto operator=(const CompileCommandsWriter&) -> CompileCommandsWriter& = delete;

    /**
     * Start a new compile commands entry.
     *
     * @param exec_root The execution root/working directory
     *     from which relative paths are to be interpreted.
     * @param file_prefix A prefix to prepend to the `file`.
     * @param file The relative source path of the file for which to record compile commands.
     */
    void next_entry(std::string_view exec_root, std::string_view file_prefix, std::string_view file)
    {
      if (is_first_entry_) {
        is_first_entry_ = false;
      } else {
        write("\n    ]\n  },");
      }
      write("\n  {\n    \"directory\": \"");
      write_quoted(exec_root);
      write("\",\n    \"file\": \"");
      write_quoted(file_prefix);
      write_quoted(file);
      write("\",\n    \"arguments\": [");
      is_first_argument_ = true;
    }

    /**
     * Add a new command line argument to the current entry.
     *
     * Must be called after calling `next_entry()` at least once.
     *
     * @param prefix A prefix to prepend to the `argument`.
     * @param argument The element to append to the `"arguments"` array.
     */
    void add_argument(std::string_view prefix, std::string_view argument)
    {
      if (is_first_argument_) {
        is_first_argument_ = false;
        write("\n      \"");
      } else {
        write(",\n      \"");
      }
      write_quoted(prefix);
      write_quoted(argument);
      write("\"");
    }

  private:

    void write(std::string_view str)
    {
      check_available_buffer(str.size());
      std::copy(str.begin(), str.end(), cursor_);
      cursor_ += str.size();
    }

    void write_quoted(std::string_view str)
    {
      // Every input character will emit at most 6 output characters.
      check_available_buffer(6 * str.size());
      for (auto c : str) {
        if (static_cast<unsigned char>(c) < JSON_CONTROL_CHARACTERS.size()) {
          const auto replacement = JSON_CONTROL_CHARACTERS[c];
          std::copy(replacement.begin(), replacement.end(), cursor_);
          cursor_ += replacement.size();
        } else {
          if ((c == '\"') or (c == '\\')) {
            *cursor_++ = '\\';
          }
          *cursor_++ = c;
        }
      }
    }

    void check_available_buffer(std::size_t required)
    {
      if (required > buffer_->size()) {
        throw std::length_error{"Excessively long string received."};
      }
      if (cursor_ - buffer_->data() + required > buffer_->size()) {
        flush();
      }
    }

    void flush()
    {
      output_.write(buffer_->data(), cursor_ - buffer_->data());
      cursor_ = buffer_->data();
    }
  };

}  // namespace bazelcc
