#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
//---------------------Insertion Sort Used by Bucket Sort---------------------
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
//---------------------Bucket Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)
// Worst Time Complexity  O(n^2)
// Avarage Time Complexity  O(n+k)
// Best Time Complexity  O(n+k)
// Space Complexity O(n+k)
// Auxiliary Space Complexity O(1)
template<class Type> Type* bucket_sort(Type* array, size_t size) {
        vector<vector<int32_t>> buckets(9, vector<int32_t>(0, 0));
        int32_t max = accumulate(array + 1, array + size, *array, [](Type &e, Type &max) -> Type {return e > max ? e : max;});
        const uint8_t E = log10(max);
        for (int32_t offset(0); offset < size; ++offset) {
                buckets.at(*(array + offset) / pow(10,E)).push_back(*(array + offset));
        }
        uint32_t counter(0);
        for (vector<vector<int32_t>>::iterator iter = buckets.begin(); iter != buckets.end(); ++iter) {
                const int* bucket = insertion_sort<int>(iter->data(), iter->size());
                for (uint32_t index(0); index < iter->size();++index, ++counter)
                        *(array + counter) = *(bucket + index);
        }
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// bucket_sort<int>(new int[9]{9,8,7,6,5,4,3,2,1},9);
