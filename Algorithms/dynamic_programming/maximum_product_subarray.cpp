using namespace std;
#include <iostream>
#include <string>
//--------------Maximum Product Subarray--------------
//Top-Down
int32_t max_product(int32_t* num, size_t len) {
        int32_t max_v, min_v, max_p;
        max_p = min_v  = max_v = num[len - 1];
        for (int32_t offset(len - 2); offset >= 0; --offset) {
                if (num[offset] >= 0) {
                        max_v = max(num[offset], num[offset] * max_v);
                        min_v = min(num[offset], num[offset] * min_v);
                }
                else {
                        max_v = max(num[offset], num[offset] * min_v);
                        min_v = min(num[offset], num[offset] * max_v);
                }
                max_p = max(max_p, max_v);
        }
        return max_p;
}
//Bottom-Up
int32_t max_product(int32_t* num, size_t len) {
        int32_t max_v = 0;
        int32_t** oss = new int32_t*[len];
        for (auto i = 0; i < len; i++)
                *(oss + i) = new int32_t[2];
        oss[len - 1][1] = oss[len - 1][0] = num[len - 1];
        for (int32_t offset(len - 2); offset >= 0; --offset) {
                if (num[offset] >= 0) {
                        oss[offset][0] = max(num[offset], num[offset] * oss[offset + 1][0]);
                        oss[offset][1] = min(num[offset], num[offset] * oss[offset + 1][1]);
                }
                else {
                        oss[offset][0] = max(num[offset], num[offset] * oss[offset + 1][1]);
                        oss[offset][1] = min(num[offset], num[offset] * oss[offset + 1][0]);
                }
        }
        for (uint32_t offset(0); offset < len; ++offset) {
                if (oss[offset][0] > max_v)
                        max_v = oss[offset][0];
        }
        return max_v;
}

/*Parameter List:
 *
 *  |--Top-Down:  --->[int32_t* num = array of numbers, size_t len = lenght of array]
 *- |
 *  |--Bottom-Up: --->[int32_t* num = array of numbers, size_t len = lenght of array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[int32_t = maximum product subarray]
 *- |
 *  |--Bottom-Up: --->[int32_t = maximum product subarray]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[max_product(num,len) num = num = new int32_t[3]{-10,-10,0}]
 *- |
 *  |--Bottom-Up: --->[max_product(num,len) num = num = new int32_t[3]{-10,-10,0}]
 *
 */
