#pragma once
#include <vector>
#include <algorithm>

namespace ns_complicated_divide_and_conquer {

class Solution {
public:
    void quickSort(std::vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int pivot = arr[l + ((r - l) / 2)];
        int i = l - 1;
        int j = r + 1;
        while (i < j) {
            do {
                i++;
            } while (arr[i] < pivot);
            do {
                j--;
            } while (arr[j] > pivot);
            if (i < j) {
                std::swap(arr[i], arr[j]);
            }
        }
        quickSort(arr, l, j);
        quickSort(arr, j + 1, r);
    }

    void mergeSort(std::vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + ((r - l) / 2);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        std::vector<int> tmp(r - l + 1);
        int i = l;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            tmp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        }
        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= r) {
            tmp[k++] = arr[j++];
        }
        for (int x = l; x <= r; x++) {
            arr[x] = tmp[x - l];
        }
    }

    long long countInversions(std::vector<int>& arr, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = l + ((r - l) / 2);
        long long cnt = countInversions(arr, l, mid) + countInversions(arr, mid + 1, r);
        std::vector<int> tmp(r - l + 1);
        int i = l;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) {
                tmp[k++] = arr[i++];
            } else {
                cnt += mid - i + 1;
                tmp[k++] = arr[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= r) {
            tmp[k++] = arr[j++];
        }
        for (int x = l; x <= r; x++) {
            arr[x] = tmp[x - l];
        }
        return cnt;
    }
};

}  // namespace ns_complicated_divide_and_conquer
