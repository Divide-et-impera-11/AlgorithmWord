using namespace std;
#include <iostream>
#include <string>
#define SIZ 5
//------------Jump Game------------
uint32_t min_jp(uint32_t arr[SIZ],uint32_t jmp_idx) {
        if (arr[jmp_idx] + jmp_idx >= SIZ - 1)
                return 1;
        uint32_t jmp = UINT32_MAX,offset = arr[jmp_idx];
        while (offset) {
                jmp = min(min_jp(arr,jmp_idx + offset) + 1,jmp);
                --offset;
        }
        return jmp;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t arr[SIZ] = unsigned integer 1D array,uint32_t jmp_idx = index of the jump]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = minimum number of jumps from index 0 to index SIZ - 1]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[min_jp(arr,0) arr = arr[SIZ]{3,1,4,5,2}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
