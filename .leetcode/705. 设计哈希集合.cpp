class MyHashSet
{
public:
    MyHashSet() : hashSet(base)
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
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */