// LeetCode 146 - LRU Cache
// Difficulty: Medium | Category: Hash Map/Set + Linked List
// https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <map>
#include <memory>
using namespace std;

struct DlinkedNode
{
public:
    int val;
    int key;
    DlinkedNode *pre;
    DlinkedNode *ne;
    DlinkedNode() : val(0), key(0), pre(nullptr), ne(nullptr) {}
    DlinkedNode(int _key, int _val)
        : val(_val),
          key(_key),
          pre(nullptr),
          ne(nullptr) {}
};

namespace ns_hash_lru_cache {

class Solution
{
public:
    int capacity;
    int size = 0;

    map<int, unique_ptr<DlinkedNode>> cache;
    unique_ptr<DlinkedNode> head;
    unique_ptr<DlinkedNode> tail;

    explicit Solution(int capacity)
        : capacity(capacity),
          head(make_unique<DlinkedNode>()),
          tail(make_unique<DlinkedNode>())
    {
        head->ne = tail.get();
        tail->pre = head.get();
    }

    Solution(const Solution&) = delete;
    Solution& operator=(const Solution&) = delete;
    Solution(Solution&&) = delete;
    Solution& operator=(Solution&&) = delete;
    ~Solution() = default;

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        DlinkedNode *cur = cache[key].get();
        int val = cur->val;
        moveToHead(cur);
        return val;
    }

    void moveToHead(DlinkedNode *cur)
    {
        deleteCur(cur);
        addToHead(cur);
    }

    static void deleteCur(DlinkedNode *cur)
    {
        cur->pre->ne = cur->ne;
        cur->ne->pre = cur->pre;
    }

    void addToHead(DlinkedNode *cur) const
    {
        cur->ne = head->ne;
        cur->pre = head.get();
        head->ne->pre = cur;
        head->ne = cur;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            auto node = make_unique<DlinkedNode>(key, value);
            DlinkedNode *cur = node.get();
            cache[key] = std::move(node);
            addToHead(cur);
            size++;
            if (size > capacity)
            {
                DlinkedNode *tailNode = tail->pre;
                int evictKey = tailNode->key;
                deleteCur(tailNode);
                cache.erase(evictKey);
                --size;
            }
        }
        else
        {
            DlinkedNode *cur = cache[key].get();
            cur->val = value;
            moveToHead(cur);
        }
    }
};

int main()
{
        Solution cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        cout << cache.get(1) << endl;
        cache.put(3, 3);
        cout << cache.get(2) << endl;
        cache.put(4, 4);
        cout << cache.get(1) << endl;
        cout << cache.get(3) << endl;
        cout << cache.get(4) << endl;
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
