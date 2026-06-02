#include <vector>
namespace ns_complicated_dynamic_programming_generate {


class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> tri(numRows);
        tri.at(0).push_back(1);
        for(int i = 1; i < numRows; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(j==0 || j==i){
                    tri.at(i).push_back(1);
                }else{
                    tri.at(i).push_back(tri.at(i-1).at(j-1) + tri.at(i-1).at(j));
                }
            }
        }
        return tri;
    }
};
} // namespace ns_complicated_dynamic_programming_generate
