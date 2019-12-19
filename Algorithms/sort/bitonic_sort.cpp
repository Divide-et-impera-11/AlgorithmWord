#include <iostream>
using namespace std;
//---------------------Used by Bitonic Sort Algorithm---------------------
template<class Type> bool is_sorted_(Type* array, size_t size) {
        for (uint32_t offset(0); offset < size - 1; ++offset) {
                if (*(array + offset) > *(array + offset + 1))
                        return false;
        }
        return true;
}
//---------------------Used by Bitonic Sort Algorithm---------------------
template<class Type> Type* bitonic(Type* array, size_t size) {
        uint32_t depht = 0;
        while (!is_sorted_<Type>(array, size) && ++depht)
                bitonic_sort<Type>(array, size, depht);
        return array;
}
//---------------------Bitonic Sort Algorithm---------------------
// Analysis
// Time Complexity O(log^2 (n)) parallel time
// Worst Time Complexity  O(log^2 (n)) parallel time
// Avarage Time Complexity  O(log^2 (n)) parallel time
// Best Time Complexity O(log^2 (n)) parallel time
// Space Complexity O(n log^2 (n)) non parallel time
// Auxiliary Space Complexity O(1)
template<class Type> Type* bitonic_sort(Type* array, size_t size,uint32_t depth) {
        if (depth == 0)
                return array;
        for (uint32_t offset(0),tik_tok(0); offset + depth < size; offset += 2,tik_tok++) {
                if (tik_tok % 2 == 0 && min(*(array + offset), *(array + offset + depth)) != *(array + offset)) {
                        swap(*(array + offset), *(array + offset + depth));
                }
                else if(tik_tok % 2 != 0 && max(*(array + offset), *(array + offset + depth)) != *(array + offset))
                        swap(*(array + offset), *(array + offset + depth));
        }
        bitonic_sort<Type>(array, size, --depth);
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array
// uint32_t depth = depth of sort

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// bitonic_sort<int>(new int[6]{93,71,34,167,3,44},6);
