#include <functional>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>

namespace ns_data_structure_hash_map_set {

template <typename K, typename V>
class Solution {
private:
    static constexpr std::size_t BUCKET_SIZE = 1024;
    std::vector<std::list<std::pair<K, V>>> buckets;
    std::size_t _size = 0;

    std::size_t getBucket(const K& key) const {
        return std::hash<K>{}(key) % BUCKET_SIZE;
    }

public:
    Solution() : buckets(BUCKET_SIZE) {}

    void insert(const K& key, const V& val) {
        auto idx = getBucket(key);
        for (auto& p : buckets[idx]) {
            if (p.first == key) {
                p.second = val;
                return;
            }
        }
        buckets[idx].emplace_back(key, val);
        _size++;
    }

    bool contains(const K& key) const {
        auto idx = getBucket(key);
        for (const auto& p : buckets[idx])
            if (p.first == key)
                return true;
        return false;
    }

    V& get(const K& key) {
        auto idx = getBucket(key);
        for (auto& p : buckets[idx])
            if (p.first == key)
                return p.second;
        throw std::out_of_range("key not found");
    }

    void remove(const K& key) {
        auto idx = getBucket(key);
        auto& bucket = buckets[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                _size--;
                return;
            }
        }
    }

    std::size_t size() const { return _size; }
    bool empty() const { return _size == 0; }
};

}  // namespace ns_data_structure_hash_map_set
