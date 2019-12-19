#include <iostream>
using namespace std;
//---------------------Quick Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)
// Worst Time Complexity O(n^2)
// Avarage Time Complexity O(n log n)
// Best Time Complexity O(n log n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* quick_sort(Type* array, size_t size)
{
        if (size <= 1)
                return array;
        Type swap;
        int16_t key_pos(0);
        for (int16_t offset(1); offset < size; ++offset) {
                if (*(array + offset) <= *(array + key_pos)) {
                        swap = *(array + offset);
                        for (int16_t walker(offset - 1); walker >= key_pos; --walker)
                                *(array + walker + 1) = *(array + walker);
                        *(array + key_pos) = swap;
                        key_pos++;
                }
        }
        quick_sort<int>(array,key_pos);
        quick_sort<int>(array + key_pos + 1, (size - 1) - key_pos );
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// quick_sort<int>(new int[2]{2,1},2);
