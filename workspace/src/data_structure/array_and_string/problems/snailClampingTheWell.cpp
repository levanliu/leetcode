#include <iostream>

using namespace std;

/*
 acwing 5279
蜗牛在 n
 米深的井底往上爬，每天清晨到傍晚向上爬 5
 米，夜间又滑下来 4
 米，请问像这样从某天清晨开始，第几天爬到井口？*/

int main() {
  int n;
  cin >> n;
  cout << max(1, n - 4);
  return 0;
}
