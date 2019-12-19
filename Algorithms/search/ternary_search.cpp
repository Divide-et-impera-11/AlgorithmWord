#include <iostream>
using namespace std;
//---------------------Ternary Seach Algorithm---------------------
// Analysis
// Time Complexity O(log n)
// Worst Time Complexity O(log n)
// Avarage Time Complexity O(log n)
// Best Time Complexity O(1)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* ternary_search(Type* array,size_t size,Type key) {
        int32_t block_start(0), block_end(size - 1),checking_area(0),divide;
        while (block_start <= block_end)
        {
                divide = 4;
                while (true)
                {
                        block_end = (checking_area + ceil((double)(size - checking_area) / (double)divide)) - 1;
                        checking_area = block_end + 1;
                        if (size == block_start) return nullptr;
                        if (*(array + block_end) < key) {
                                block_start = block_end + 1;
                                continue;
                        }
                        else if (*(array + block_end) > key) {
                                block_end--;
                                break;
                        }
                        else return (array + block_end);
                }
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
// ternary_search<int>(new int[4]{1,2,3,4},4,2);
