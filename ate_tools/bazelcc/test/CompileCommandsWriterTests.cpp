#include "CompileCommandsWriter.hpp"

#include <catch2/catch_test_macros.hpp>

#include <sstream>

// NOTE: With C++20, we could properly indent the expected raw string literals
//     and dedent them at compile time using a user-defined literal operator
//     (see https://stackoverflow.com/a/75104910).

TEST_CASE("Compile commands can be serialized properly.", "[CompileCommandsWriter]")
{
  std::string_view expected;
  std::ostringstream actual;

  {
    bazelcc::CompileCommandsWriter writer{actual};

    SECTION("Not adding any entries is valid.")
    {
      expected = "[\n]\n";
    }

    SECTION("An entry without any arguments is valid.")
    {
      writer.next_entry("wdir/", "src/", "file");
      expected = R"([
  {
    "directory": "wdir/",
    "file": "src/file",
    "arguments": [
    ]
  }
]
)";
    }

    SECTION("A single entry with a single argument is valid.")
    {
      writer.next_entry("wdir/", "src/", "file");
      writer.add_argument("", "arg");
      expected = R"([
  {
    "directory": "wdir/",
    "file": "src/file",
    "arguments": [
      "arg"
    ]
  }
]
)";
    }

    SECTION("Multiple entries are valid.")
    {
      writer.next_entry("wdir1/", "src/", "file1");
      writer.next_entry("wdir2/", "src/", "file2");
      writer.add_argument("", "arg2");
      writer.next_entry("wdir3/", "src/", "file3");
      writer.add_argument("", "arg3.1");
      writer.add_argument("", "arg3.2");
      writer.add_argument("", "arg3.3");
      expected = R"([
  {
    "directory": "wdir1/",
    "file": "src/file1",
    "arguments": [
    ]
  },
  {
    "directory": "wdir2/",
    "file": "src/file2",
    "arguments": [
      "arg2"
    ]
  },
  {
    "directory": "wdir3/",
    "file": "src/file3",
    "arguments": [
      "arg3.1",
      "arg3.2",
      "arg3.3"
    ]
  }
]
)";
    }
  }

  CHECK(actual.str() == expected);
}


TEST_CASE("Characters are properly escaped while serializing.", "[CompileCommandsWriter]")
{
  using namespace std::string_view_literals;
  std::string_view expected;
  std::ostringstream actual;

  {
    bazelcc::CompileCommandsWriter writer{actual};

    SECTION("Control characters are escaped.")
    {
      writer.next_entry("evil\ndirec\tory/", "evilp\refix/", "evil\file\b");
      writer.add_argument("evil\0a\rgument"sv, "");  // embedded NULL
      writer.add_argument("\x01\x02\x03\x04\x05\x06\x07", "\x0B\x0E\x0F");
      writer.add_argument("", "\x10\x11\x12\x13\x14\x15\x16\x17");
      writer.add_argument("\x18\x19\x1A\x1B\x1C\x1D\x1E\x1F", "");
      expected = R"([
  {
    "directory": "evil\ndirec\tory/",
    "file": "evilp\refix/evil\file\b",
    "arguments": [
      "evil\u0000a\rgument",
      "\u0001\u0002\u0003\u0004\u0005\u0006\u0007\u000B\u000E\u000F",
      "\u0010\u0011\u0012\u0013\u0014\u0015\u0016\u0017",
      "\u0018\u0019\u001A\u001B\u001C\u001D\u001E\u001F"
    ]
  }
]
)";
    }

    SECTION("Double-quotes and backslashes are escaped.")
    {
      writer.next_entry("evil\"directory\\/", "evil\"prefix\\/", "evil\"file\\");
      writer.add_argument("evil\"argument\\", "");
      expected = R"([
  {
    "directory": "evil\"directory\\/",
    "file": "evil\"prefix\\/evil\"file\\",
    "arguments": [
      "evil\"argument\\"
    ]
  }
]
)";
    }
  }

  CHECK(actual.str() == expected);
}
