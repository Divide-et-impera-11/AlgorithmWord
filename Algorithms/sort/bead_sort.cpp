#include <iostream>
using namespace std;
//---------------------Bead Sort Algorithm---------------------
// Analysis
// Time Complexity O(n)
// Worst Time Complexity  O(n)
// Avarage Time Complexity  O(n)
// Best Time Complexity  O(1)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* bead_sort(Type *array, size_t size) {
        for (uint32_t offset(size - 1); offset >= 1; offset--) {
                for (uint32_t bead_fall(offset - 1); bead_fall < (size - 1); bead_fall++) {
                        uint32_t fall_down = *(array + bead_fall) - *(array + bead_fall + 1) > 0 ? *(array + bead_fall) - *(array + bead_fall + 1) : 0;
                        *(array + bead_fall + 1) += fall_down;
                        *(array + bead_fall) -= fall_down;
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
// bead_sort<int>(new int[4]{4,3,2,1},4);
