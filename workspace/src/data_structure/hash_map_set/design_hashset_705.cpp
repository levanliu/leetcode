// LeetCode 705 - Design HashSet
// Difficulty: Easy | Category: Hash Map/Set
// https://leetcode.com/problems/design-hashset/

namespace ns_hash_design_hashset {

class Solution
{
public:
    Solution() : hashSet(base)
    {
    }

    void add(int key)
    {
        int h = hashCode(key);
        for (auto it : hashSet[h])
        {
            if (it == key)
            {
                return;
            }
        }
        hashSet[h].push_back(key);
    }

    void remove(int key)
    {
        int h = hashCode(key);
        for (auto it = hashSet[h].begin(); it != hashSet[h].end(); it++)
        {
            if ((*it) == key)
            {
                hashSet[h].erase(it);
                return;
            }
        }
    }

    bool contains(int key)
    {
        int h = hashCode(key);
        for (auto it : hashSet[h])
        {
            if (it == key)
            {
                return true;
            }
        }
        return false;
    }

private:
    vector<list<int>> hashSet;
    static const int base = 769;
    int hashCode(int key)
    {
        return key % base;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new Solution();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
} // namespace ns_hash_design_hashset
