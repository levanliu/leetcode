#include <catch2/catch_test_macros.hpp>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include <fstream>
#include <cstdlib>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace {

bool IsDirectory(const std::string& path) {
    struct stat st {};
    if (stat(path.c_str(), &st) != 0) {
        return false;
    }
    return S_ISDIR(st.st_mode);
}

std::vector<std::string> ListCppFilesRecursive(const std::string& root) {
    std::vector<std::string> files;
    DIR* dir = opendir(root.c_str());
    if (!dir) {
        return files;
    }

    struct dirent* entry = nullptr;
    while ((entry = readdir(dir)) != nullptr) {
        std::string name = entry->d_name;
        if (name == "." || name == "..") {
            continue;
        }

        std::string path = root + "/" + name;
        if (IsDirectory(path)) {
            std::vector<std::string> nested = ListCppFilesRecursive(path);
            files.insert(files.end(), nested.begin(), nested.end());
            continue;
        }

        if (name.size() > 4 && name.substr(name.size() - 4) == ".cpp") {
            files.push_back(path);
        }
    }

    closedir(dir);
    return files;
}

std::string ReadAll(const std::string& path) {
    std::ifstream in(path.c_str());
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

std::string ResolveSrcRoot() {
    const char* testSrcDir = std::getenv("TEST_SRCDIR");
    const char* testWorkspace = std::getenv("TEST_WORKSPACE");
    std::vector<std::string> candidates;
    candidates.push_back("/workspaces/atslxws68/levanliu/leetcode/workspace/src");
    candidates.push_back("workspace/src");
    candidates.push_back("./workspace/src");
    if (testSrcDir != nullptr) {
        std::string base(testSrcDir);
        if (testWorkspace != nullptr) {
            candidates.push_back(base + "/" + std::string(testWorkspace) + "/workspace/src");
        }
        candidates.push_back(base + "/_main/workspace/src");
        candidates.push_back(base + "/workspace/src");
    }

    char cwd[4096];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::string cur(cwd);
        while (!cur.empty()) {
            candidates.push_back(cur + "/workspace/src");
            candidates.push_back(cur + "/_main/workspace/src");

            std::size_t pos = cur.find_last_of('/');
            if (pos == std::string::npos) {
                break;
            }
            if (pos == 0) {
                cur = "/";
                candidates.push_back(cur + "workspace/src");
                break;
            }
            cur = cur.substr(0, pos);
        }
    }

    for (const std::string& candidate : candidates) {
        if (IsDirectory(candidate)) {
            return candidate;
        }
    }
    return "";
}

}  // namespace

TEST_CASE("All solution files follow naming and namespace conventions", "[conventions][solution_files]") {
    const std::string srcRoot = ResolveSrcRoot();
    REQUIRE_FALSE(srcRoot.empty());

    std::vector<std::string> cppFiles = ListCppFilesRecursive(srcRoot);
    REQUIRE(!cppFiles.empty());

    const std::regex filenamePattern(".*/[a-z][a-z0-9_]*\\.cpp$");
    const std::regex namespacePattern("namespace\\s+ns_[a-z0-9_]+\\s*\\{");
    const std::regex solutionPattern("\\bclass\\s+Solution\\b");
    const std::regex headerIncludePattern("#include\\s*\"[^\"]+\\.h\"");
    const std::regex badHeadPattern(".*/(lc_|p_|problem_|[0-9])[a-z0-9_]*\\.cpp$");

    for (const std::string& path : cppFiles) {
        INFO(path);
        REQUIRE_FALSE(std::regex_match(path, badHeadPattern));
        REQUIRE(std::regex_match(path, filenamePattern));

        const std::string content = ReadAll(path);
        REQUIRE_FALSE(content.empty());

        if (std::regex_search(content, solutionPattern)) {
            REQUIRE(std::regex_search(content, namespacePattern));
        }
        REQUIRE_FALSE(std::regex_search(content, headerIncludePattern));
    }
}
