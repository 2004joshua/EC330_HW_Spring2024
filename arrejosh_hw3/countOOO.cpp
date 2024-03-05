/*
 * COLE KNUTSEN EC330_HW_3
 *
 * This C++ code utilizes information from the following sources:
 *
 * 1. ChatGPT:
 *    - Author: OpenAI (corporation)
 *    - Availability: https://www.openai.com/
 *
 * 2. Geeks for Geeks:
 *    - Last Updated: 28 Nov, 2023
 *    - Title: Merge Sort – Data Structure and Algorithms Tutorials
 *    - Type: Forum post
 *    - Availability: https://www.geeksforgeeks.org/merge-sort/
*/
#include "countOOO.h"
#include <unordered_map>
#include <algorithm> // For std::min (returns the smaller of its two arguments)

// MergeCount function merges two sorted subarrays and counts the out-of-order pairs
int MergeCount(std::vector<int>& mergesort, std::vector<int>& temp, int left, int mid, int right) {
    int count = 0; // Initialize count of out-of-order pairs
    int i = left, j = mid + 1, k = left; // Initialize pointers for subarrays and merged array

    // Merge the two subarrays and count out-of-order pairs (This is done for left/right and then back in through the while loops)
    while (i <= mid && j <= right) {
        if (mergesort[i] <= mergesort[j]) {
            temp[k++] = mergesort[i++];
        } else {
            count += (mid - i + 1); // Count out-of-order pairs
            temp[k++] = mergesort[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = mergesort[i++];
    }

    while (j <= right) {
        temp[k++] = mergesort[j++];
    }

    for (int i = left; i <= right; ++i) {
        mergesort[i] = temp[i];
    }
    return count;
}

// MergeSort_CountIterative function sorts the array using iterative merge sort and counts out-of-order pairs
int MergeSort_CountIterative(std::vector<int>& mergesort, std::vector<int>& temp) {
    int n = mergesort.size(); // Size of the array
    int count = 0; // Initialize count of out-of-order pairs
    // Iterate over subarray sizes
    for (int size = 1; size < n; size *= 2) {
        // Iterate over subarrays to merge
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);
            count += MergeCount(mergesort, temp, left, mid, right); // Merge subarrays and count out-of-order pairs
        }
    }
    return count;
}

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB) {
    std::unordered_map<std::string, int> IndexMap; // Map to store indices of elements in rankedListB
    // Populate indexMap with indices of elements in rankedListB
    for (int i = 0; i < rankedListB.size(); ++i) {
        IndexMap[rankedListB[i]] = i;
    }

    std::vector<int> mergesort(rankedListA.size()); // Array to store indices of elements in rankedListA as per their order in rankedListB
    // Populate mergesort array with indices from indexMap
    for (int i = 0; i < rankedListA.size(); ++i) {
        mergesort[i] = IndexMap[rankedListA[i]];
    }

    std::vector<int> temp(mergesort.size()); // Temporary array for merge sort
    return MergeSort_CountIterative(mergesort, temp); // Sort the array and count out-of-order pairs
}
