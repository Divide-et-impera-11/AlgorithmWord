#include <iostream>
using namespace std;
//---------------------Linear Search Algorithm---------------------
// Analysis
// Time Complexity O(n)
// Worst Time Complexity O(n)
// Avarage Time Complexity O(1)
// Best Time Complexity O(1)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* linear_search(Type* array, size_t size,Type element) {
        for (size_t offset(0); offset < size; offset++)
                if (*(array + offset) == element) return (array + offset);
        return nullptr;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array
// Type element = search key

// Return Value Cases:
// pointer to the searched element, if the algorithm found it
// null pointer, if the the algorithm did not found the searched element

// Function Call Example
// linear_search<int>(new int[2]{1,2},2,2);
