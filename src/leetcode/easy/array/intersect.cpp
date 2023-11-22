#include<iostream>
using namespace std;
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1,vector<int>& nums2)
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int m = nums1.size();
        int n = nums2.size();

        int p1 = 0, p2 = 0;
        vector<int> res;
        while(p1<m && p2<n){
            if(nums1[p1] < nums2[p2]){
                p1++;
            }else if(nums1[p1] > nums2[p2]){
                p2++;
            }else{
                res.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return res;
    }
};