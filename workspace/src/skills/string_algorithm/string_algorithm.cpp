#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

namespace ns_skills_string_algorithm {

// ---- String Hashing (polynomial rolling hash) ---------------------------
// Compute polynomial hash for fast substring comparison.
// hash(s[l..r]) computable in O(1) after O(n) preprocessing.
struct StringHash {
    static const long long MOD = 1e9 + 7, BASE = 131;
    std::vector<long long> h, pw;
    explicit StringHash(const std::string& s)
        : h(s.size() + 1, 0), pw(s.size() + 1, 1) {
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            h[i + 1] = (h[i] * BASE + s[i]) % MOD;
            pw[i + 1] = pw[i] * BASE % MOD;
        }
    }
    // Hash of s[l..r] (0-indexed, inclusive)
    long long get(int l, int r) const {
        return (h[r + 1] - h[l] * pw[r - l + 1] % MOD + MOD * 2) % MOD;
    }
};

class Solution {
public:
    // ---- KMP String Matching --------------------------------------------
    // Find all starting positions (0-indexed) of pattern p in text s.  O(n+m)
    static std::vector<int> kmpSearch(const std::string& s,
                                      const std::string& p) {
        std::vector<int> result;
        if (p.empty())
            return result;
        int m = static_cast<int>(p.size());
        int n = static_cast<int>(s.size());
        // Build failure function
        std::vector<int> ne(m, -1);
        for (int i = 1, j = -1; i < m; ++i) {
            while (j != -1 && p[i] != p[j + 1])
                j = ne[j];
            if (p[i] == p[j + 1])
                ++j;
            ne[i] = j;
        }
        // Search
        for (int i = 0, j = -1; i < n; ++i) {
            while (j != -1 && s[i] != p[j + 1])
                j = ne[j];
            if (s[i] == p[j + 1])
                ++j;
            if (j == m - 1) {
                result.push_back(i - j);
                j = ne[j];
            }
        }
        return result;
    }

    // ---- Longest Palindromic Substring (Manacher's) ---------------------
    // Returns the longest palindromic substring.  O(n)
    static std::string longestPalindrome(const std::string& s) {
        if (s.empty())
            return "";
        // Transform: "abc" → "#a#b#c#"
        std::string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }
        int n = static_cast<int>(t.size());
        std::vector<int> p(n, 0);
        int center = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (i < right)
                p[i] = std::min(right - i, p[2 * center - i]);
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
                   t[i - p[i] - 1] == t[i + p[i] + 1])
                ++p[i];
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
        int maxLen = *std::max_element(p.begin(), p.end());
        int maxIdx =
            static_cast<int>(std::max_element(p.begin(), p.end()) - p.begin());
        // Convert back to original indices
        int start = (maxIdx - maxLen) / 2;
        return s.substr(start, maxLen);
    }

    // Check if a string is a palindrome.  O(n)
    static bool isPalindrome(const std::string& s) {
        int l = 0, r = static_cast<int>(s.size()) - 1;
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }

    // ---- Anagram Grouping -----------------------------------------------
    // Group strings that are anagrams of each other.  O(n * k log k)
    static std::vector<std::vector<std::string>> groupAnagrams(
        const std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const auto& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto& [k, v] : map)
            result.push_back(std::move(v));
        return result;
    }

    // ---- Longest Substring Without Repeating Characters ----------------
    // Sliding window.  O(n)
    static int lengthOfLongestSubstring(const std::string& s) {
        std::vector<int> last(256, -1);
        int maxLen = 0, start = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (last[(unsigned char)s[i]] >= start)
                start = last[(unsigned char)s[i]] + 1;
            last[(unsigned char)s[i]] = i;
            maxLen = std::max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

}  // namespace ns_skills_string_algorithm
