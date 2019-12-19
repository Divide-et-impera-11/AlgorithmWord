#include <iostream>
using namespace std;
//---------------------Used by Pancake Sort Algorithm---------------------
template<class Type> void pancake_rotate(Type* pancake_tower, size_t size) {
        int32_t from(0), to(size - 1);
        while (from < to)
        {
                Type key = *(pancake_tower + to);
                *(pancake_tower + to) = *(pancake_tower + from);
                *(pancake_tower + from) = key;
                from++;
                to--;
        }
}

//---------------------Pancake Sort Algorithm---------------------
// Analysis
// Time Complexity O(n^2)
// Worst Time Complexity  O(n^2)
// Avarage Time Complexity  O(n^2)
// Best Time Complexity  O(n)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* pancake_sort(Type* pancake_tower, size_t size) {
        int32_t offset(size - 1),counter(div(18,11) * size);
        while (counter)
        {
                if (*(pancake_tower + offset) < *(pancake_tower + offset - 1)) {
                        //Do wrong  offset ~ size
                        pancake_rotate<Type>(pancake_tower + offset, size - offset);
                        //Rotate from offset ~ size
                        pancake_rotate<Type>(pancake_tower + offset - 1, (size - offset) + 1);
                }
                offset = offset == 1 ? size - 1 : offset - 1;
                counter--;
        }
        return pancake_tower;
}
// Parameter List:
// Type* pancake_tower = pointer to the "Pancake Tower"
// size_t size = size of pancakes in the"Pancake Tower"

// Return Value Cases:
// pointer to sorted "Pancake Tower"

// Function Call Example
// pancake_sort<int>(new int[4]{9,7,3,1},4);
