#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;
//---------------------Pigeonhole Sort Algorithm---------------------
// Analysis
// Time Complexity O(n + N) where 'n' is the number of elements in list and 'N' is the holes
// Worst Time Complexity  O(n + N)
// Avarage Time Complexity  O(n + N)
// Best Time Complexity  O(n + N)
// Space Complexity O(n + N)
// Auxiliary Space Complexity O(n + N)
template<class Type> Type* pigeon_hole(Type *array, size_t size) {
        int32_t min = accumulate(array + 1, array + size, *array, [](Type &e, Type &min) -> Type {return e < min ? e : min;});
        int32_t max = accumulate(array + 1, array + size, *array, [](Type &e, Type &max) -> Type {return e > max ? e : max;});
        vector<queue<Type>> pigeon_holes(max - min + 1,queue<int32_t>());
        for (int32_t offset(0); offset < size; ++offset) {
                pigeon_holes.at(*(array + offset) - min).push(*(array + offset));
        }
        uint32_t counter(0);
        for (vector<queue<Type>>::iterator iter = pigeon_holes.begin(); iter != pigeon_holes.end(); ++iter) {
                while (!iter->empty())
                {
                        *(array + counter++) = iter->front();
                        iter->pop();
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
// pigeon_hole<int>(new int[2]{1,1000},2);
