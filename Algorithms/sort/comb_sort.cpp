#include <iostream>
using namespace std;
//---------------------Comb Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)
// Worst Time Complexity  O(n^2)
// Avarage Time Complexity  O(n^2 /2^p) where p is the number of increments
// Best Time Complexity  O(n log n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* comb_sort(Type* array, size_t size) {
        constexpr float div = 1.3;
        int32_t gap = size;
        bool swap = false;
        while (!(gap == 1 && !swap))
        {
                swap = false;
                gap = gap == 1 ? gap : gap / div;
                for (int32_t offset(0);(offset + gap) < size; offset += gap) {
                        if (*(array + offset) > *(array + offset + gap)) {
                                Type switch_ = *(array + offset + gap);
                                *(array + offset + gap) = *(array + offset);
                                *(array + offset) = switch_;
                                swap = true;
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
// comb_sort<int>(new int[3]{3,23,3},3);
