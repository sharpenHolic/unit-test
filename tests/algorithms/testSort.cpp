//
// Created by gqxiong on 2023/10/19.
//

#include <gtest/gtest.h>
#include <vector>
#include <iostream>

#define SWAP(a, b)          \
    do {                    \
        typeof(a) temp = a; \
        a = b;              \
        b = temp;           \
    } while (0)
std::vector<int> vec{2, 4, 0, 1, 23, 9, 5, 12, 15, 3, 100, 200, 23, 88};
static void PrintVec(const std::vector<int>& vec)
{
    for (const auto& v : vec) {
        std::cout << v << ", ";
    }
    std::cout << std::endl;
}

TEST(SORT, Data) { PrintVec(vec); }

TEST(SORT, Bubble)  // O(n^2)
{
    std::cout << "----test Bubble----\n";
    std::vector<int> res = vec;
    for (int i = 0; i < res.size() - 1; ++i) {
        for (int j = 0; j < res.size() - 1; ++j) {
            if (res[j] > res[j + 1]) {
                SWAP(res[j], res[j + 1]);
            }
        }
    }
    PrintVec(res);
}

TEST(SORT, Select)  // O(n^2)
{
    std::cout << "----test Select----\n";
    std::vector<int> res = vec;
    for (int i = 0; i < res.size(); ++i) {
        int min = i;
        for (int j = i + 1; j < res.size(); ++j) {
            if (res[j] < res[min]) {
                min = j;
            }
        }
        if (min != i) {
            SWAP(res[min], res[i]);
        }
    }
    PrintVec(res);
}

TEST(SORT, Insert)  // O(n^2)
{
    std::cout << "----test Insert----\n";
    std::vector<int> res = vec;
    for (int i = 1; i < res.size(); ++i) {
        int j = i - 1;
        auto key = res[i];
        while ((j >= 0) && (key < res[j])) {
            res[j + 1] = res[j];
            j--;
        }
        res[j + 1] = key;
    }
    PrintVec(res);
}

static int Partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            SWAP(arr[i], arr[j]);
        }
    }
    SWAP(arr[i + 1], arr[high]);
    return i + 1;
}

static void QuickSortHelper(std::vector<int>& arr, int low, int high)
{
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSortHelper(arr, low, pi - 1);
        QuickSortHelper(arr, pi + 1, high);
    }
}

TEST(SORT, Quick)  // O(n log n)
{
    std::cout << "----test Quick----\n";
    std::vector<int> res = vec;
    QuickSortHelper(res, 0, res.size() - 1);
    PrintVec(res);
}

static void Merge(std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

static void MergeSortHelper(std::vector<int>& arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSortHelper(arr, left, mid);
        MergeSortHelper(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

TEST(SORT, Merge)  // O(n log n)
{
    std::cout << "----test Merge----\n";
    std::vector<int> res = vec;
    MergeSortHelper(res, 0, res.size() - 1);
    PrintVec(res);
}

static void Heapify(std::vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        SWAP(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

TEST(SORT, Heap)  // O(n log n)
{
    std::cout << "----test Heap----\n";
    std::vector<int> res = vec;
    int n = res.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        Heapify(res, n, i);
    for (int i = n - 1; i > 0; --i) {
        SWAP(res[0], res[i]);
        Heapify(res, i, 0);
    }
    PrintVec(res);
}
