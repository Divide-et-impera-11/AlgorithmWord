#include <iostream>
using namespace std;
//---------------------Merge Sort Algorithm---------------------
// Analysis
// Time Complexity O(n log n)
// Worst Time Complexity O(n log n)
// Avarage Time Complexity O(n log n)
// Best Time Complexity О(n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* merge_sort(Type* array, size_t size) {

        uint16_t block_size(1);
        while (block_size < size)
        {
                for (uint32_t block_offset(0); block_offset < size; block_offset += (2 * block_size)) {
                        int32_t first_arr_offset(block_offset), second_array_offset(first_arr_offset + block_size), first_arr_size(first_arr_offset + block_size), second_arr_size = second_array_offset + block_size > size ? size : second_array_offset + block_size;
                        while (first_arr_offset < first_arr_size && second_array_offset < second_arr_size)
                        {
                                if (*(array + second_array_offset) <= *(array + first_arr_offset)) {
                                        int swap = *(array + second_array_offset);
                                        for (int32_t offset = second_array_offset - 1; offset >= first_arr_offset; offset--)
                                                *(array + offset + 1) = *(array + offset);
                                        *(array + first_arr_offset) = swap;
                                        second_array_offset++;
                                        first_arr_size++;
                                }
                                first_arr_offset++;
                        }
                }
                block_size *= 2;
        }
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// merge_sort<int>(new int[4]{43,11,24,3},4);
