#include <iostream>
#define BLOCK_SIZE 32
using namespace std;
//---------------------Used by Tim Sort Algorithm---------------------
template<class Type> Type* merge_sort_for_tim_sort(Type* array, size_t size) {

        uint16_t block_size(BLOCK_SIZE);
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
//---------------------Used by Tim Sort Algorithm---------------------
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
//---------------------Tim Sort Algorithm---------------------
// Analysis
// Time Complexity O(n log n)
// Worst Time Complexity  O(n log n)
// Avarage Time Complexity  O(n log n)
// Best Time Complexity  O(n)
// Space Complexity O(n)
// Auxiliary Space Complexity O(1)
template<class Type> Type* tim_sort(Type* array, size_t size) {
   uint32_t block_front(0), block_size(BLOCK_SIZE);
   while (block_front < size)
   {
           block_size = block_front + block_size <= size ? block_size : size - block_front;
           insertion_sort<Type>(array + block_front, block_size);
           block_front = block_size + 1;
   }
   merge_sort_for_tim_sort<Type>(array, size);
   return array;

}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// tim_sort<int>(new int[4]{9,7,3,1},4);
