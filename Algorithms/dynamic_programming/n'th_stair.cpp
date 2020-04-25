using namespace std;
#include <iostream>
#include <string>
//-------------Count ways to reach the n’th stair-------------
uint32_t n_stair(uint32_t p,uint32_t n) {
        return p == n ? 1 : p > n ? 0 : n_stair(p + 1,n) + n_stair(p + 2,n);
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t p = actual stair,uint32_t n = final stair]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = number of ways to reach the n'th stair]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[n_stair(1,10)]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
