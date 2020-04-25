using namespace std;
#include <iostream>
#include <string>
//---------------Rod Cutting---------------
//Top-Down
uint32_t rod_cut(uint32_t *price,size_t len,int32_t* mem) {
        if (mem[len] != -1) {
                return mem[len];
        }
        uint32_t max_vl = 0;
        for (uint32_t offset(0); offset < len; ++offset) {

                max_vl = max(price[offset] + rod_cut(price, len - (offset + 1), mem), max_vl);
        }
        mem[len] = max_vl;
        return max_vl;
}
uint32_t rod_cutting(uint32_t* price,size_t len) {
        int32_t *mem = new int32_t[len + 1];
        memset(mem, -1, sizeof(int32_t) * (len + 1));
        return rod_cut(price, len, mem);
}
//Bottom-Up
int32_t rod_cut(int32_t *price,size_t len) {
        int32_t* oss = new int32_t[len + 1];
        memset(oss, -1, sizeof(int32_t) * (len + 1));
        *oss = 0;
        for (uint32_t piece(0); piece < len; ++piece) {
                for (uint32_t lco(0); lco <= piece; ++lco) {
                        oss[piece + 1] = max(price[lco] + oss[piece - lco], oss[piece + 1]);
                }
        }
        return oss[len];
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t *price = array of prices,size_t len = length of array]
 *- |
 *  |--Bottom-Up: --->[uint32_t *price = array of prices,size_t len = length of array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = maximum money to sell the rod]
 *- |
 *  |--Bottom-Up: --->[uint32_t = maximum money to sell the rod]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[rod_cutting(price,3) price = price = new uint32_t[3]{2,5,6}]
 *- |
 *  |--Bottom-Up: --->[rod_cut(price,5) price = price = new uint32_t[5]{2,5,6,10,18}]
 *
 */
