#include <iostream>
using namespace std;
//---------------------Gnome Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)
// Worst Time Complexity  O(n^2)
// Avarage Time Complexity  O(n^2)
// Best Time Complexity  O(n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* gnome_sort(Type *array, size_t size) {
        for (uint32_t offset(1);offset < size; ++offset) {
                for (uint32_t walker(offset); walker >= 1; walker--) {
                        if (*(array + walker) < *(array + walker - 1))
                                swap(*(array + walker), *(array + walker - 1));
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
// gnome_sort<int>(new int[4]{9,7,3,1},4);
