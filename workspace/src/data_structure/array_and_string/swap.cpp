// Swap two integers in-place without using std::swap
namespace ns_data_structure_array_and_string_swap {

class Solution {
public:
    static void swapInts(int& a, int& b) {
        int t = a;
        a = b;
        b = t;
    }
};

}  // namespace ns_data_structure_array_and_string_swap
