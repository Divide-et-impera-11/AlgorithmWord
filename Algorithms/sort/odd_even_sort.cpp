#include <iostream>
using namespace std;
//---------------------Odd Even Sort Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)
// Worst Time Complexity  O(n^2)
// Avarage Time Complexity  O(n^2)
// Best Time Complexity  O(n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* odd_even_sort(Type *array, size_t size) {
        bool swapped = true;;
        while (swapped)
        {
                swapped = false;
                for (uint32_t odd_even(0); odd_even < 2; ++odd_even) {
                        for (uint32_t offset(odd_even); offset < size - 1; offset += 2) {
                                if (*(array + offset) > *(array + offset + 1)) {
                                        swap(*(array + offset), *(array + offset + 1));
                                        swapped = true;
                                }
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
// odd_even_sort<int>(new int[4]{9,7,3,1},4);
