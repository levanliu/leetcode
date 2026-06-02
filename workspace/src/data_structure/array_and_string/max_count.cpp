#include <algorithm>
#include <iostream>
//
// Created by le on 3/1/2023.
//
namespace ns_array_max_count {

class Solution {
private:
    int n;
    static const int N = 100010;
    int a[N][2];

public:
    int maxCountMain() {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i][0] >> a[i][1];
        }
        int res = 1, ans = 1;
        for (int i = 0, j = 1; j < n; j++) {
            if (a[i][0] == a[j][0] && a[i][1] == a[j][1]) {
                res++;
                ans = std::max(ans, res);
            } else {
                res = 1;
                i = j;
            }
        }
        std::cout << ans;
        return 0;
    }
};

}  // namespace ns_array_max_count
