#include <iostream>

/*
 *acwing 5276
给定一个正整数 n
，请你计算[1,n]
 范围内一共有多少个正整数满足能被 2
 整除，但不能被 3
 整除。*/
using namespace std;

int solve(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0 && i % 3 != 0) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  cout << solve(n);
  return 0;
}
