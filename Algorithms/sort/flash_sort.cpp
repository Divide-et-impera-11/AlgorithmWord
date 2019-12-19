#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
//---------------------Flash Sort Algorithm---------------------
// Analysis
// Time Complexity O(n)
// Worst Time Complexity  O(n)
// Avarage Time Complexity  O(n)
// Best Time Complexity  O(1)
// Space Complexity O(n)
// Auxiliary Space Complexity O(1)
template<class Type> Type* flash_sort(Type* array, size_t size) {
        if (size <= 1) return nullptr;
        int32_t min = accumulate(array + 1, array + size, *array, [](Type &e, Type &min) -> Type {return e < min ? e : min;});
        int32_t max = accumulate(array + 1, array + size, *array, [](Type &e, Type &max) -> Type {return e > max ? e : max;});
        vector<uint32_t> classes(size,0);
        for (uint32_t offset(0); offset < size; ++offset) {
                classes.at((size - 1)*(*(array + offset) - min) / (max - min))++;
        }
        for (vector<uint32_t>::iterator iter = classes.begin(); iter != classes.end() - 1; ++iter) {
                *(iter + 1) += *(iter);
        }
        int32_t from(0), ramain_elements(size + 1);
        Type key = *array,swap;
        while (--ramain_elements)
        {
                size_t to = --classes.at((size - 1)*(key - min) / (max - min));
                if (to == from) {
                        for (uint32_t offset(0); offset < size; ++offset) {
                                if (offset != from && classes.at((size - 1)*(*(array + offset) - min) / (max - min)) - 1 != offset) {
                                        key = *(array + offset);
                                        from = offset;
                                        break;
                                }
                   }
                }
                else {
                        swap = *(array + to);
                        *(array + to) = key;
                        key = swap;
                        from = to;
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
// flash_sort<int>(new int[4]{9,7,3,1},4);
