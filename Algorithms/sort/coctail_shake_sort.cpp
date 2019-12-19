#include <iostream>
using namespace std;
//---------------------Coctail Shake Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)
// Worst Time Complexity  O(n^2)
// Avarage Time Complexity  O(n^2)
// Best Time Complexity  O(n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* coctail_shake_sort(Type*array, size_t size) {
        uint32_t shakes = size - 1,counter;
        int32_t from(0), add(1);
        while (shakes)
        {
                counter = 0;
                while (counter != shakes)
                {
                        if (add == 1 && max(*(array + from), *(array + from + add)) == *(array + from) || add == -1 && min(*(array + from), *(array + from + add)) == *(array + from))
                                swap(*(array + from), *(array + from + add));
                        from += add;
                        counter++;
                }
                shakes--;
                add *= -1;
                from += add;
        }
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// coctail_shake_sort<int>(new int[4]{9,7,3,1},4);
