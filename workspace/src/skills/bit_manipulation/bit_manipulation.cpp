#pragma once
#include <utility>
#include <vector>

// Common bit manipulation patterns used in LeetCode problems.
//
// Reference:
//   n & (n-1)      — clear lowest set bit
//   n & (-n)       — isolate lowest set bit (lowbit)
//   n ^ n == 0     — cancel duplicates
//   a ^ b ^ b == a — XOR self-inverse

// ---- Single-number tricks ------------------------------------------------

// Returns the only element that appears once (all others appear twice)
inline int singleNumber(const std::vector<int>& nums) {
    int result = 0;
    for (int x : nums)
        result ^= x;
    return result;
}

// Returns two elements that each appear once (all others appear twice)
inline std::pair<int, int> singleNumberII(const std::vector<int>& nums) {
    int xorAll = 0;
    for (int x : nums)
        xorAll ^= x;
    // Find any differing bit between the two unique numbers
    int bit = xorAll & (-xorAll);
    int a = 0, b = 0;
    for (int x : nums) {
        if (x & bit)
            a ^= x;
        else
            b ^= x;
    }
    return {a, b};
}

// ---- Bit counting --------------------------------------------------------

// Count set bits (Brian Kernighan's algorithm)
inline int countBits(unsigned int n) {
    int count = 0;
    while (n) {
        n &= n - 1;
        ++count;
    }
    return count;
}

// Returns vector where result[i] = number of set bits in i, for i in [0,n]
inline std::vector<int> countBitsRange(int n) {
    std::vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        dp[i] = dp[i >> 1] + (i & 1);
    return dp;
}

// ---- Misc ----------------------------------------------------------------

// True if n is a power of two
inline bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Reverse all bits of a 32-bit unsigned integer
inline unsigned int reverseBits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; ++i) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

// Returns the Hamming distance between two integers
inline int hammingDistance(int x, int y) {
    return countBits(static_cast<unsigned int>(x ^ y));
}

namespace ns_skills_bit_manipulation {

class Solution {
public:
    static int singleNumber(const std::vector<int>& nums) {
        return ::singleNumber(nums);
    }
    static std::pair<int, int> singleNumberII(const std::vector<int>& nums) {
        return ::singleNumberII(nums);
    }
    static int countBits(unsigned int n) { return ::countBits(n); }
    static std::vector<int> countBitsRange(int n) {
        return ::countBitsRange(n);
    }
    static bool isPowerOfTwo(int n) { return ::isPowerOfTwo(n); }
    static unsigned int reverseBits(unsigned int n) { return ::reverseBits(n); }
    static int hammingDistance(int x, int y) { return ::hammingDistance(x, y); }
};

}  // namespace ns_skills_bit_manipulation
