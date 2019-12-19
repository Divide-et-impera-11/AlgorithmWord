#include <iostream>
using namespace std;
//---------------------Bubble Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)comparisons, O(n^2) swaps
// Worst Time Complexity O(n^2)comparisons, O(n^2) swaps
// Avarage Time Complexity O(n^2)comparisons, O(n^2) swaps
// Best Time Complexity О(n)comparisons, О(1) swaps
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* bubble_sort(Type *array, size_t size) {
        for (uint32_t offset(0); offset < size - 1; offset++) {
                for (uint32_t bubble_offset(0); bubble_offset < (size - offset) - 1; bubble_offset++) {
                        if (*(array + bubble_offset) > *(array + bubble_offset + 1)) {
                                uint32_t swap(*(array + bubble_offset + 1));
                                *(array + bubble_offset + 1) = *(array + bubble_offset);
                                *(array + bubble_offset) = swap;
                        }
                }
        }
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// bubble_sort<int>(new int[2]{2,1},2);
