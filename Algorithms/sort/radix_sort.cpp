#include <iostream>
#include <numeric>
using namespace std;
//---------------------Radix Sort Algorithm---------------------
// Analysis
// Time Complexity O(nk) where n is the number of input data and k is the maximum element in the input data
// Worst Time Complexity  O(nk)
// Avarage Time Complexity  O(nk)
// Best Time Complexity  O(nk)
// Space Complexity O(n+k)
// Auxiliary Space Complexity O(1)
template<class Type> Type* radix_sort(Type *array, size_t size) {
        uint32_t step = 0,E(1);
        uint32_t max = accumulate(array + 1, array + size, *array, [](Type &e, Type &max) -> Type {return e > max ? e : max;});
        max = log10(max) + 1;
        while (step < max) {
                for (int32_t offset(1); offset < size; offset++) {
                        Type key = *(array + offset);
                        for (int32_t walker(offset - 1); walker >= -1; --walker) {
                                if (walker == -1) {
                                        *array = key;
                                        continue;
                                }
                                if ((*(array + walker) / E) % 10 > (key / E) % 10) {
                                        *(array + walker + 1) = *(array + walker);
                                }
                                else {
                                        *(array + walker + 1) = key;
                                        break;
                                }
                        }
                }
                E *= 1e1;
                step++;
        }
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// radix_sort<int>(new int[4]{1,20,300,4000},4);
