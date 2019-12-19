#include <iostream>
#include <algorithm>
using namespace std;
//---------------------Used by Quick Sort Algorithm---------------------
int *median_of_three(int * a, int * b, int * c)
{
        if (*a < *b && *b < *c)
                return (b);

        if (*a < *c && *c <= *b)
                return (c);

        if (*b <= *a && *a < *c)
                return (a);

        if (*b < *c && *c <= *a)
                return (c);

        if (*c <= *a && *a < *b)
                return (a);

        if (*c <= *b && *b <= *a)
                return (b);
}
//---------------------Used by Intro Sort Algorithm---------------------
template<class Type> inline int32_t quick_sort_for_intro_sort(Type* array, size_t size)
{
        if (size <= 1)
                return array;
        Type swap;
        swap(*median_of_three(array, array + (size / 2), array + (size - 1)),*array);
        int32_t pivot(0);
        for (int32_t offset(1); offset < size; ++offset) {
                if (*(array + offset) <= *(array + pivot)) {
                        swap = *(array + offset);
                        for (int32_t walker(offset - 1); walker >= pivot; --walker)
                                *(array + walker + 1) = *(array + walker);
                        *(array + pivot) = swap;
                        pivot++;
                }
        }
        return pivot;
}
//---------------------Used by Intro Sort Algorithm---------------------
template<class Type> Type* insertion_sort(Type* array, size_t size) {
        for (uint32_t offset(1); offset < size; offset++) {
                Type key = *(array + offset);
                for (int32_t walker(offset - 1); walker >= -1; walker--) {
                        if (walker < 0) {
                                *array = key;
                                continue;
                        }
                        if (*(array + walker) > key) {
                                *(array + walker + 1) = *(array + walker);
                        }
                        else {
                                *(array + walker + 1) = key;
                                break;
                        }
                }
        }
        return array;
}
//---------------------Intro Sort Algorithm---------------------
// Analysis
// Time Complexity O(n log n)
// Worst Time Complexity  O(n log n)
// Avarage Time Complexity  O(n log n)
// Best Time Complexity  O(1)
// Space Complexity O(1)
// Auxiliary Space Complexity O(1)
template<class Type> Type* intro_sort(Type* array, size_t size, uint32_t depth) {
        if (size <= 16) { //insertion Sort
                insertion_sort<Type>(array, size);
                return;
        }
        if (depth == 0) { //heap sort
                make_heap(array, array + size);
                sort_heap(array, array + size);
                return;
        }
        //quick sort
        int32_t pivot_pos = quick_sort_for_intro_sort<Type>(array, size);
        intro_sort(array,pivot_pos,--depth);
        intro_sort(array + pivot_pos + 1,(size - 1) - pivot_pos,--depth);
        return array;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array
// uint32_t depth = depth of sort

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// intro_sort<int>(new int[4]{9,7,3,1},4);
