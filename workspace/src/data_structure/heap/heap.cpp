#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>

// Generic binary heap / priority queue.
// Default: max-heap.  Pass std::greater<T> for min-heap.
//
// Common use-cases:
//   MaxHeap<int>                      heap;   // max-heap
//   MinHeap<int>                      heap;   // min-heap (alias below)
//   MinHeap<int>                      heap;   heap.push(v); heap.top(); heap.pop();
//
// Top-K patterns:
//   - K largest  → min-heap of size K; discard if top < new element
//   - K smallest → max-heap of size K; discard if top > new element
namespace ns_data_structure_heap {

template <typename T, typename Compare = std::less<T>>
class Solution {
private:
    std::vector<T> data_;
    Compare cmp_;

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (cmp_(data_[parent], data_[i])) {
                std::swap(data_[parent], data_[i]);
                i = parent;
            } else
                break;
        }
    }

    void siftDown(int i) {
        int n = static_cast<int>(data_.size());
        while (true) {
            int best = i, l = 2 * i + 1, r = 2 * i + 2;
            if (l < n && cmp_(data_[best], data_[l]))
                best = l;
            if (r < n && cmp_(data_[best], data_[r]))
                best = r;
            if (best == i)
                break;
            std::swap(data_[i], data_[best]);
            i = best;
        }
    }

public:
    Solution() = default;

    // Build from existing data in O(n)
    explicit Solution(std::vector<T> data) : data_(std::move(data)) {
        for (int i = static_cast<int>(data_.size()) / 2 - 1; i >= 0; --i)
            siftDown(i);
    }

    void push(const T& val) {
        data_.push_back(val);
        siftUp(static_cast<int>(data_.size()) - 1);
    }

    void pop() {
        if (data_.empty())
            throw std::underflow_error("heap is empty");
        data_[0] = data_.back();
        data_.pop_back();
        if (!data_.empty())
            siftDown(0);
    }

    const T& top() const {
        if (data_.empty())
            throw std::underflow_error("heap is empty");
        return data_[0];
    }

    bool empty() const { return data_.empty(); }
    int size() const { return static_cast<int>(data_.size()); }

    // Returns the K largest elements (unsorted) using a min-heap of size K
    static std::vector<T> topK(const std::vector<T>& arr, int k) {
        Solution<T, std::greater<T>> minH;
        for (const T& v : arr) {
            minH.push(v);
            if (minH.size() > k)
                minH.pop();
        }
        std::vector<T> result;
        result.reserve(minH.size());
        while (!minH.empty()) {
            result.push_back(minH.top());
            minH.pop();
        }
        return result;
    }
};

// Convenience aliases
template <typename T>
using MaxHeap = Solution<T, std::less<T>>;
template <typename T>
using MinHeap = Solution<T, std::greater<T>>;

}  // namespace ns_data_structure_heap
