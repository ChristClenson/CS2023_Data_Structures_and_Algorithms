#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
using namespace std;

// Recursive Quick Sort Algorithm
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;
        quickSortRecursive(arr, low, partitionIndex - 1);
        quickSortRecursive(arr, partitionIndex + 1, high);
    }
}

// Non-Recursive Quick Sort Algorithm
void quickSortNonRecursive(int arr[], int low, int high) {
    stack<pair<int, int>> stack;
    stack.push(make_pair(low, high));

    while (!stack.empty()) {
        pair<int, int> curr = stack.top();
        stack.pop();
        int start = curr.first;
        int end = curr.second;

        int pivot = arr[end];
        int i = start - 1;

        for (int j = start; j <= end - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[end]);
        int partitionIndex = i + 1;

        if (partitionIndex - 1 > start) {
            stack.push(make_pair(start, partitionIndex - 1));
        }

        if (partitionIndex + 1 < end) {
            stack.push(make_pair(partitionIndex + 1, end));
        }
    }
}

int main() {
    srand(time(nullptr));

    // Test for different array sizes
    for (int size = 10000; size <= 100000; size += 10000) {
        int arr[size];

        // Initialize the array with random integers
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100000;
        }

        // Measure the time taken for recursive quick sort
        auto startTime = chrono::high_resolution_clock::now();
        quickSortRecursive(arr, 0, size - 1);
        auto endTime = chrono::high_resolution_clock::now();
        auto durationRecursive = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

        // Shuffle the array and measure the time taken for non-recursive quick sort
        random_shuffle(arr, arr + size);
        startTime = chrono::high_resolution_clock::now();
        quickSortNonRecursive(arr, 0, size - 1);
        endTime = chrono::high_resolution_clock::now();
        auto durationNonRecursive = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

        cout << "Array Length: " << size << endl;
        cout << "Recursive Quick Sort took " << durationRecursive.count() << " milliseconds." << endl;
        cout << "Non-Recursive Quick Sort took " << durationNonRecursive.count() << " milliseconds." << endl;
    }

    return 0;
}
