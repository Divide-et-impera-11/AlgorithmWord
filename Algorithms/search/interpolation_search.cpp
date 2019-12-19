#include <iostream>
using namespace std;
//---------------------Interpolation Seach Algorithm---------------------
// Analysis
// Time Complexity O(n)
// Worst Time Complexity O(n)
// Avarage Time Complexity O(log n)
// Best Time Complexity O(1)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* interpolation_search(Type* array, size_t size, Type key) {
        int32_t x1(0), x2(size - 1),difference_x1,difference_x2,middle_index;
        while (true)
        {
                difference_x1 = (key - *(array + x1));
                if (difference_x1 < 0) return nullptr;
                else if (difference_x1 == 0)return (array + x1);

                difference_x2 = (*(array + x2) - key);
                if (difference_x2 < 0)return nullptr;
                else if (difference_x2 == 0)return (array + x2);

                middle_index = difference_x1 < difference_x2 ? (x1 + ((x1 + x2) / 4)) : difference_x2 < difference_x1 ? (x2 - ((x1 + x2) / 4)) : (x1 + x2) / 2;
                if (*(array + middle_index) == key)
                        return (array + middle_index);
                else if (*(array + middle_index) < key)
                        x1 = middle_index + 1;
                else x2 = middle_index - 1;
        }
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array
// Type key = search key

// Return Value Cases:
// pointer to the searched element, if the algorithm found it
// null pointer, if the the algorithm did not found the searched element

// Function Call Example
// interpolation_search<int>(new int[3]{1,2,3},3,10);
