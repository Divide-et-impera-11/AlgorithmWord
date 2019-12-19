#include <iostream>
#include <vector>
using namespace std;
//---------------------Fibonacci Seach Algorithm---------------------
// Analysis
// Time Complexity O(log n)
// Worst Time Complexity O(log n)
// Avarage Time Complexity O(log n)
// Best Time Complexity O(1)
// Space Complexity O(f) where 'f' is the size of fibonacci fibonacci sequence
// Auxiliary Space Complexity O(f) where 'f' is the size of fibonacci fibonacci sequence
template<class Type> Type* fibonacci_search(Type* array, size_t size, Type key) {
        vector<uint32_t> fibonacci_numbers(1, 1);
        uint32_t *fibonacci_range;
        int a(0), b(1);
        do {
                fibonacci_numbers.push_back(a + b);
        } while ((a = (b = (a + b)) - a) && b != size);
        fibonacci_range = &fibonacci_numbers.back();
        while (*fibonacci_range != 1)
        {
                if (*(array + *(fibonacci_range - 2) - 1) > key) {
                        fibonacci_range -= 2;
                }
                else if (*(array + *(fibonacci_range - 2) - 1) < key) {
                        array += *(fibonacci_range - 2);
                        fibonacci_range -= 1;
                }
                else {
                        return (array + *(fibonacci_range - 2) - 1);
                }
        }
        return *array == key ? array : nullptr;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array
// Type key = search key

// Return Value Cases:
// pointer to the searched element, if the algorithm found it
// null pointer, if the the algorithm did not found the searched element

// Function Call Example
// fibonacci_search<int>(new int[5]{54,32,44,101,342},5,32);
