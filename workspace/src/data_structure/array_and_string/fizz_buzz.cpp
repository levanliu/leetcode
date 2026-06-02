#include<iostream>
using namespace std;
namespace ns_data_structure_array_and_string_fizz_buzz {


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0)
                res.push_back("FizzBuzz");
            if(i%3==0 && i%5!=0)
                res.push_back("Fizz");
            if(i%3!=0 && i%5==0)
                res.push_back("Buzz");
            if(i%3!=0 && i%5!=0)
                res.push_back(to_string(i));
        }
        return res;
    }
};
} // namespace ns_data_structure_array_and_string_fizz_buzz
