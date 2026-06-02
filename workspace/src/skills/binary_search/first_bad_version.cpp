#include<iostream>
using namespace std;

bool isBadVersion(int val){
    return false;
}
namespace ns_skills_binary_search_first_bad_version {


class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int r=n;
        while(l<r){
            int mid = l + (r-l)/2;
            if( !isBadVersion(mid) ) l = mid+1; 
            else r = mid;
        }
        return l;
    }
};
} // namespace ns_skills_binary_search_first_bad_version
