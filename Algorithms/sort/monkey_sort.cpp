#include <iostream>
using namespace std;
//---------------------Used by Monkey Sort---------------------
unsigned get_variation(unsigned long_) {
        unsigned variation_ = 1;
        while (long_)
                variation_ *= long_--;
        return variation_;
}
//---------------------Used by Monkey Sort---------------------
template<class Type> bool is_sorted_(Type* array, size_t size) {
        for (uint32_t offset(0); offset < size - 1; ++offset) {
                if (*(array + offset) > *(array + offset + 1))
                        return false;
        }
        return true;
}
//---------------------Monkey Sort Algorithm---------------------
// Analysis
// Time Complexity O(n!)
// Worst Time Complexity  O(n!)
// Avarage Time Complexity  O(n!)
// Best Time Complexity  O(1)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* monkey_sort(Type* array, size_t size) {
        unsigned variation = get_variation(size);
        for (uint32_t loop(0); loop < (variation) / (size - 1); loop++) {
                for (uint32_t loop_inside(0); loop_inside < (size - 1); loop_inside++) {
                        Type swap = *(array + loop_inside);
                        *(array + loop_inside) = *(array + loop_inside + 1);
                        *(array + loop_inside + 1) = swap;
                        if (is_sorted(array, size))
                                return array;
                }
        }
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// monkey_sort<int>(new int[10]{43,23,5,52,100,43,77,3224,5342,8},10);
