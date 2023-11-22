#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * f(n) = f(1) + f(n-1)
 *
 * f(n) : A -> C use B;
 * f(1) : A -> C;
 * f(n-1) : B -> C  use A
 *
 * 0: n A->C
 * 1: n-1 A->B;
 * * 2: 1 A->C;
 * * 3: n-1 B->C;
 */
void move(vector<int> &src, vector<int> &tar) {
  // 从 src 顶部拿出一个圆盘
  int pan = src.back();
  src.pop_back();
  // 将圆盘放入 tar 顶部
  tar.push_back(pan);
}
/* 求解汉诺塔：问题 f(i) */
void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar) {
  // 若 src 只剩下一个圆盘，则直接将其移到 tar
  if (i == 1) {
    move(src, tar);
    return;
  }
  // 子问题 f(i-1) ：将 src 顶部 i-1 个圆盘借助 tar 移到 buf
  dfs(i - 1, src, tar, buf);
  // 子问题 f(1) ：将 src 剩余一个圆盘移到 tar
  move(src, tar);
  // 子问题 f(i-1) ：将 buf 顶部 i-1 个圆盘借助 src 移到 tar
  dfs(i - 1, buf, src, tar);
}
/* 求解汉诺塔 */
void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C) {
  int n = A.size();
  // 将 A 顶部 n 个圆盘借助 B 移到 C
  dfs(n, A, B, C);
}

int main(){
  vector<int> A = {10,22,3,4,5};
  vector<int> B;
  vector<int> C;
  solveHanota(A,B,C);

  for(int n:C){
    cout << n << endl;
  }
  return 0;
}
