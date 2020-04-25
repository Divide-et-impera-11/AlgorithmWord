using namespace std;
#include <iostream>
#include <string>
#include <vector>
//-----------------Combination Sum-----------------
typedef vector<uint32_t> V32;
typedef vector<vector<uint32_t>> VV32;
//Top-Down
VV32 com_sum(uint32_t* arr,size_t len,uint32_t num) {
        if (!num)
                return VV32(1, V32(1, 0));
        VV32 comb;
        for (uint32_t offset(0); offset < len; ++offset) {
                if (arr[offset] <= num) {
                        VV32& num_group = com_sum(arr + offset, len - offset, num - arr[offset]);
                        if (!num_group.empty()) {
                                for (auto itr = num_group.begin(); itr != num_group.end(); ++itr) {
                                        itr->push_back(arr[offset]);
                                        comb.push_back(*itr);
                                }
                        }
                }
        }
        return comb;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t* arr = array of numbers,size_t len = length of array,uint32_t num = number to sum]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[VV23 = vector of subarray sum equal to 'num']
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[com_sum(arr,3,9) arr = arr = new uint32_t[3]{3,3,3}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
