/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * https://leetcode.cn/problems/lru-cache/description/
 *
 * algorithms
 * Medium (53.46%)
 * Likes:    2785
 * Dislikes: 0
 * Total Accepted:    504.4K
 * Total Submissions: 943.5K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
 *
 * 实现 LRUCache 类：
 *
 *
 *
 *
 * LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
 * int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
 * void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组
 * key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
 *
 *
 * 函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
 *
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10000
 * 0 <= value <= 10^5
 * 最多调用 2 * 10^5 次 get 和 put
 *
 *
 */

// @lc code=start
#include <iostream>
#include <map>
using namespace std;

class DlinkedNode
{
public:
    int val;
    int key;
    DlinkedNode *pre;
    DlinkedNode *ne;
    DlinkedNode() : key(0), val(0), pre(nullptr), ne(nullptr) {}
    DlinkedNode(int _key, int _val)
        : key(_key),
          val(_val),
          pre(nullptr),
          ne(nullptr) {}
};

class LRUCache
{
public:
    int capacity;
    int size;

    map<int, DlinkedNode *> cache;
    DlinkedNode *head;
    DlinkedNode *tail;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        head = new DlinkedNode();
        tail = new DlinkedNode();
        head->ne = tail;
        tail->pre = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        DlinkedNode *cur = cache[key];
        int val = cur->val;
        moveToHead(cur);
        return val;
    }

    void moveToHead(DlinkedNode *cur)
    {
        deleteCur(cur);
        addToHead(cur);
    }

    void deleteCur(DlinkedNode *cur)
    {
        cur->pre->ne = cur->ne;
        cur->ne->pre = cur->pre;
        // delete cur;
    }

    void addToHead(DlinkedNode *cur)
    {
        cur->ne = head->ne;
        cur->pre = head;
        head->ne->pre = cur;
        head->ne = cur;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            DlinkedNode *cur = new DlinkedNode(key, value);
            cache[key] = cur;
            addToHead(cur);
            size++;
            if (size > capacity)
            {
                DlinkedNode *tailNode = tail->pre;
                cache.erase(tailNode->key);
                deleteCur(tailNode);
                delete tailNode;
                --size;
            }
        }
        else
        {
            DlinkedNode *cur = cache[key];
            cur->val = value;
            moveToHead(cur);
        }
    }
};

int main()
{
  LRUCache* cache = new LRUCache(2);
  cache->put(1, 1); 
  cache->put(2, 2); 
  cout << cache->get(1) << endl;     
  cache->put(3, 3); 
  cout << cache->get(2) << endl;     
  cache->put(4, 4); 
  cout << cache->get(1) << endl;   
  cout << cache->get(3) << endl;  
  cout << cache->get(4) << endl; 
  return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
