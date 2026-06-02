#pragma once
#include <vector>
#include <algorithm>

// -------------------------------------------------------------------
// Quick Sort  (in-place, O(n log n) average)
// -------------------------------------------------------------------
inline void quickSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int pivot = arr[l + (r - l) / 2], i = l - 1, j = r + 1;
    while (i < j) {
        do { ++i; } while (arr[i] < pivot);
        do { --j; } while (arr[j] > pivot);
        if (i < j) std::swap(arr[i], arr[j]);
    }
    quickSort(arr, l, j);
    quickSort(arr, j + 1, r);
}

// -------------------------------------------------------------------
// Merge Sort  (stable, O(n log n))
// -------------------------------------------------------------------
inline void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    std::vector<int> tmp;
    tmp.reserve(r - l + 1);
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
        tmp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r)   tmp.push_back(arr[j++]);
    for (int k = l; k <= r; ++k) arr[k] = tmp[k - l];
}

// -------------------------------------------------------------------
// Heap Sort  (in-place, O(n log n))
// -------------------------------------------------------------------
inline void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

inline void heapSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// -------------------------------------------------------------------
// k-th Smallest (quick-select, O(n) average)
// -------------------------------------------------------------------
inline int kthSmallest(std::vector<int> arr, int k) {
    // k is 1-indexed
    int l = 0, r = static_cast<int>(arr.size()) - 1;
    while (l < r) {
        int pivot = arr[l + (r - l) / 2], i = l - 1, j = r + 1;
        while (i < j) {
            do { ++i; } while (arr[i] < pivot);
            do { --j; } while (arr[j] > pivot);
            if (i < j) std::swap(arr[i], arr[j]);
        }
        if (j - l + 1 >= k) r = j;
        else { k -= j - l + 1; l = j + 1; }
    }
    return arr[l];
}
