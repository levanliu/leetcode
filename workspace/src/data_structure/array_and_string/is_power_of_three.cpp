#include<iostream>
using namespace std;
namespace ns_data_structure_array_and_string_is_power_of_three {


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n>1){
            while(n%3 == 0){
                n /= 3;
            }
        }
        return n==1;
    }
};
} // namespace ns_data_structure_array_and_string_is_power_of_three
