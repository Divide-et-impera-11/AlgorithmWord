#include <iostream>
using namespace std;
//---------------------Jump Seach Algorithm---------------------
// Analysis
// Time Complexity O(√n)
// Worst Time Complexity O(√n)
// Avarage Time Complexity O(√n)
// Best Time Complexity O(√n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* jump_search(Type *array, size_t size, Type key) {
        size_t block_size = sqrt(size);
        uint32_t block_offset(0);
        while (block_offset < size)
        {
                if (*(array + block_offset) == key) return (array + block_offset);
                else if (*(array + block_offset) > key) {
                        if (!block_offset) return nullptr;
                        else {
                                for (uint32_t index = 1; index < block_size; index++)
                                        if (*(array + (block_offset - index)) == key)
                                                return (array + (block_offset - index));
                                return nullptr;
                        }
                }
                block_offset += block_size;
        }
        if (!(block_offset == ((size - 1) + block_size)))
                for (uint32_t index = 0, block_offset = size - 1; index < block_size; index++)
                        if (*(array + (block_offset - index)) == key) return (array + (block_offset - index));
        return nullptr;

}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array
// Type key = search key

// Return Value Cases:
// pointer to the searched element, if the algorithm found it
// null pointer, if the the algorithm did not found the searched element

// Function Call Example
// jump_search<int>(new int[3]{1,2,3},3,10);
