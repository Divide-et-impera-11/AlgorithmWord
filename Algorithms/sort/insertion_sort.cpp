#include <iostream>
using namespace std;
//---------------------Insertion Sort Algorithm---------------------
// Analysis
// Time Complexity О(n2) comparisons and swaps
// Worst Time Complexity О(n2) comparisons and swaps
// Avarage Time Complexity О(n2) comparisons and swaps
// Best Time Complexity О(n)comparisons, О(1) swaps
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* insertion_sort(Type* array, size_t size) {
        for (uint32_t offset(1); offset < size; offset++) {
                Type key = *(array + offset);
                for (int32_t walker(offset - 1); walker >= -1; walker--) {
                        if (walker < 0) {
                                *array = key;
                                continue;
                        }
                        if (*(array + walker) > key) {
                                *(array + walker + 1) = *(array + walker);
                        }
                        else {
                                *(array + walker + 1) = key;
                                break;
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
// insertion_sort<int>(new int[2]{2,1},2);
