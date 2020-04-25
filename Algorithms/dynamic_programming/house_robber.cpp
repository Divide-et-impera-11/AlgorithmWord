using namespace std;
#include <iostream>
#include <string>
//--------------House Robber--------------
//Top-Down
uint32_t house_robber(uint32_t *houses, size_t len,int32_t *mem) {
        if (*mem != -1)
                return *mem;
        uint32_t max_vl = len == 0 ? 0 : *houses;
        for (uint32_t offset(2); offset < len; ++offset) {
                max_vl = max(houses[0] + house_robber(houses + offset, len - offset, mem + offset), max_vl);
        }
        *mem = max_vl;
        return max_vl;
}
uint32_t house_robber_setup(uint32_t *houses, size_t len) {
        int32_t *mem = new int32_t[len];
        memset(mem, -1, sizeof(int32_t) * len);
        return house_robber(houses, len, mem);
}
//Bottom-Up
uint32_t house_robber(uint32_t* houses, size_t len) {
        uint32_t *oss = new uint32_t[len];
        for (int32_t hs = len - 1; hs >= 0; --hs) {
                oss[hs] = houses[hs];
                for (uint32_t lco = hs + 2; lco < len; ++lco) {
                        oss[hs] = max(houses[hs] + houses[lco], oss[hs]);
                }
        }
        return oss[0];
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t *houses = array of houses, size_t len = lenght of array]
 *- |
 *  |--Bottom-Up: --->[uint32_t *houses = array of houses, size_t len = lenght of array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = maximum prey robber can collect]
 *- |
 *  |--Bottom-Up: --->[uint32_t = maximum prey robber can collect]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[house_robber_setup(houses,3) houses = houses = new uint32_t[3]{34,100,32}]
 *- |
 *  |--Bottom-Up: --->[house_robber_setup(houses,3) houses = houses = new uint32_t[3]{34,100,32}]
 *
 */
