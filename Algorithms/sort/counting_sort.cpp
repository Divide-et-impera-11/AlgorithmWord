#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
//---------------------Counting Sort Algorithm---------------------
// Analysis
// Time Complexity O(n+k)
// Worst Time Complexity O(n+k)
// Avarage Time Complexity O(n+k)
// Best Time Complexity O(n+k)
// Space Complexity O(n+k)
// Auxiliary Space Complexity O(n+k)
int* counting_sort(int* array, size_t size) {
        if (size <= 1) return array;
        map<int, uint16_t> hash;
        uint32_t offset(0);
        for (; offset < size; ++offset) {
                auto iter = find_if(hash.begin(), hash.end(), [&](pair<const int, uint16_t>& pair_) -> bool { return pair_.first >= *(array + offset) ? true : false;});
                if (iter == hash.end()) {
                        hash.insert(hash.end(),pair<const int, uint16_t>(*(array + offset), 1));
                        continue;
                }
                if ((*iter).first == *(array + offset)) {
                        iter->second++;
                }
                else {
                        hash.insert(iter,pair<int, uint16_t>(*(array + offset), 1));
                }
        }
        auto iter_f = hash.begin();
        auto iter_l = ++iter_f;
        iter_f--;
        while (iter_l != hash.end())
        {
                iter_l->second += iter_f->second;
                iter_f++;
                iter_l++;
        }
        int*result = new int[size];
        for (uint32_t offset(0); offset < size; ++offset) {
                *(result + --hash.at(*(array + offset))) = *(array + offset);
        }
        return result;
}
// Parameter List:
// Type* array = pointer to an array
// size_t size = size of elements in array

// Return Value Cases:
// pointer to sorted array

// Function Call Example
// counting_sort<int>(new int[2]{2,1},2);
