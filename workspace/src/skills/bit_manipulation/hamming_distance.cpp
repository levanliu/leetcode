#include<iostream>
using namespace std;
namespace ns_skills_bit_manipulation_hamming_distance {


class Solution {
public:
    int lowbit(int x){
        return x&(-x);
    }
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int res = x^y;
        while(res){
            res -= lowbit(res);
            cnt++;
        }
        return cnt;
    }
};
} // namespace ns_skills_bit_manipulation_hamming_distance
