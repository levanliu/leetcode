#include <iostream>
using namespace std;
namespace ns_skills_string_algorithm_reverse_string {

class Solution
{
public:
    void reverseString(vector<char>& s){
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[s.size()-i-1]);
        }
    }
};
} // namespace ns_skills_string_algorithm_reverse_string
