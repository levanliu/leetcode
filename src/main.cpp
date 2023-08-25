#include <cstdio>
#include <iostream>
#include <memory>

#include "dataStructure/doubleLinkedList.h"
#include "dataStructure/kmp.h"
#include "leetcode/weekOne/LongestPalindrome.h"
#include "leetcode/weekOne/LongestSubstring.h"
#include "leetcode/weekOne/MaxCount.h"
#include "leetcode/weekOne/TwoSum.h"
#include "leetcode/weekTwo/ThreeSum.h"
#include "search/dfsSearch.h"
#include "search/nQueen.h"
#include "search/weightCenterTree.h"
#include "sort/VectorSort.h"
#include "dataStructure/hashTableSim.h"
using namespace std;

int main()
{
  //    string a = "babad"
  //    LongestSubstring l = LongestSubstring();
  //    cout << l.lengthOfLongestSubstring(a) << endl;
  //
  //    LongestPalindrome l2 = LongestPalindrome();
  //    cout << l2.longestPalindrome(a) << endl;

  //    std::unique_ptr<dfsSearch> d(new dfsSearch());
  //    d->dfsMain();'
  // unique_ptr<weightCenterTree> n(new weightCenterTree());
  // n->weightCenterTreeMain();
  //    unique_ptr<MaxCount> d(new MaxCount());
  //    d->maxCountMain();
  // unique_ptr<VectorSort> v(new VectorSort());
  // v->vectorSortMain();
  // cout << "hello" << endl;
  // cout << "hi" << endl;
  unique_ptr<kmp> k(new kmp());
  k->KmpMain();
  // unique_ptr<HashTableSim> h(new HashTableSim());
  // h->hashTableSimMain();
  return 0;
}
