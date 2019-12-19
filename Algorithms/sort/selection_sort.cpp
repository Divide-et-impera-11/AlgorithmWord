#include <iostream>
using namespace std;
//---------------------Selection Sort Algorithm---------------------
// Analysis
// Time Complexity О(n2) comparisons, О(n) swaps
// Worst Time Complexity О(n2) comparisons, О(n) swaps
// Avarage Time Complexity О(n2) comparisons, О(n) swaps
// Best Time Complexity О(n2) comparisons, О(n) swaps
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* selection_sort(Type*array, size_t size) {
        for (uint32_t smallest_pos(0), min, offset;smallest_pos < size - 1; smallest_pos++) {
                for (min = smallest_pos, offset = smallest_pos + 1; offset < size; offset++) {
                        if (*(array + offset) < *(array + min))
                                min = offset;
                }
                uint32_t swap = *(array + smallest_pos);
                *(array + smallest_pos) = *(array + min);
                *(array + min) = swap;
        }
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// selection_sort<int>(new int[2]{2,1},2);
