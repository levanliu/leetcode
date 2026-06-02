// Convert a non-negative integer to its English word representation.
#include <array>
#include <cassert>
#include <cstdint>
#include <stdexcept>
#include <string>

namespace ns_data_structure_array_and_string_say {

class Solution {
public:
    static std::string inEnglish(unsigned long long n) {
        if (n >= 1000000000000ULL) {
            throw std::domain_error{"invalid number"};
        }
        if (n == 0) {
            return "zero";
        }
        const std::array<std::pair<unsigned long long, const char*>, 4>
            sections = {{{1000000000ULL, "billion "},
                         {1000000ULL, "million "},
                         {1000ULL, "thousand "},
                         {1ULL, ""}}};
        std::string result;
        for (auto [divisor, suffix] : sections) {
            if (n >= divisor) {
                result += inEnglish1To999(static_cast<int>(n / divisor));
                result += suffix;
                n %= divisor;
            }
        }
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

private:
    static std::string word(int n) {
        switch (n) {
            case 1:
                return "one";
            case 2:
                return "two";
            case 3:
                return "three";
            case 4:
                return "four";
            case 5:
                return "five";
            case 6:
                return "six";
            case 7:
                return "seven";
            case 8:
                return "eight";
            case 9:
                return "nine";
            case 10:
                return "ten";
            case 11:
                return "eleven";
            case 12:
                return "twelve";
            case 13:
                return "thirteen";
            case 14:
                return "fourteen";
            case 15:
                return "fifteen";
            case 16:
                return "sixteen";
            case 17:
                return "seventeen";
            case 18:
                return "eighteen";
            case 19:
                return "nineteen";
            case 20:
                return "twenty";
            case 30:
                return "thirty";
            case 40:
                return "forty";
            case 50:
                return "fifty";
            case 60:
                return "sixty";
            case 70:
                return "seventy";
            case 80:
                return "eighty";
            case 90:
                return "ninety";
            case 100:
                return "hundred";
            default:
                return "";
        }
    }

    static std::string inEnglish1To999(int n) {
        assert(0 < n && n <= 999);
        std::string result;
        if (n >= 100) {
            result = word(n / 100) + " hundred ";
            n %= 100;
        }
        if (n > 20) {
            result += word(n - n % 10);
            n %= 10;
            result += (n != 0) ? '-' : ' ';
        }
        if (n > 0) {
            result += word(n) + ' ';
        }
        return result;
    }
};

}  // namespace ns_data_structure_array_and_string_say
