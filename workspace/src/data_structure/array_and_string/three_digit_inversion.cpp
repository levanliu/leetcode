// Reverse a 3-digit integer: e.g. 123 -> 321
namespace ns_data_structure_array_and_string_three_digit_inversion {

class Solution {
public:
    static int invertThreeDigits(int n) {
        return (n % 10) * 100 + (n / 10 % 10) * 10 + (n / 100);
    }
};

}  // namespace ns_data_structure_array_and_string_three_digit_inversion
