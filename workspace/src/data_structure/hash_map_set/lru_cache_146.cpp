// LeetCode 146 - LRU Cache
// Difficulty: Medium | Category: Hash Map/Set + Linked List
// https://leetcode.com/problems/lru-cache/

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

namespace ns_hash_lru_cache {

class Solution
{
public:
    int capacity;
    int size;

    map<int, DlinkedNode *> cache;
    DlinkedNode *head;
    DlinkedNode *tail;
    Solution(int capacity)
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
    Solution* cache = new Solution(2);
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
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

} // namespace ns_hash_lru_cache
