#include <iostream>
using namespace std;
//---------------------Shell Sort Algorithm---------------------
// Analysis
// Time Complexity O(n (log n)^2)
// Worst Time Complexity  O(n (log n)^2)
// Avarage Time Complexity  O(n (log n)^2)
// Best Time Complexity  O(n log n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* shell_short(Type* array, size_t size) {
        int32_t shell = size;
        while ((shell /= 2) != 0)
        {
                for (int32_t offset = shell; offset < size; ++offset) {
                        for (int32_t jumper = offset - shell,swapper = offset; jumper >= 0; jumper -= shell,swapper -= shell) {
                                if (*(array + swapper) < *(array + jumper))
                                        swap(*(array + swapper), *(array + jumper));
                                else break;
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
// shell_short<int>(new int[4]{1,20,300,4000},4);
