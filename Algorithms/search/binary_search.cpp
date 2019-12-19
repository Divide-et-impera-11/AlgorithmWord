#include <iostream>
using namespace std;
//---------------------Binary Seach Algorithm---------------------
// Analysis
// Time Complexity O(log n)
// Worst Time Complexity O(log n)
// Avarage Time Complexity O(log n)
// Best Time Complexity O(1)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> inline Type* binary_search(Type *array, size_t size, Type key) {
        int32_t lower_index(0), upper_index(size - 1),middle_index;
        while (lower_index <= upper_index)
        {
                middle_index = floor((lower_index + upper_index) / 2);
                if (*(array + middle_index) < key) lower_index = (middle_index + 1);
                else if (*(array + middle_index) > key) upper_index = (middle_index - 1);
                else return (array + middle_index);
        }
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
// binary_search<int>(new int[2]{1,2},2,2);
