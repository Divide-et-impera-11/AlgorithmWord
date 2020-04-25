using namespace std;
#include <iostream>
#include <string>
#define SIZ 4
//-------------Balanced Partition-------------
void lco_(int set[SIZ],int opt_str[SIZ],unsigned int idx,const int sum) {
        if (idx == SIZ - 1) {
                opt_str[idx] = set[idx];
                return;
        }
        lco_(set,opt_str,idx + 1,sum);
        opt_str[idx] = set[idx];
        unsigned int diff = abs(set[idx] - (sum - set[idx])),diff_n;
        for (unsigned int off = idx + 1; off < SIZ; ++off) {
            diff_n = abs(set[idx] + opt_str[off] - (sum - (set[idx] + opt_str[off])));
                if (diff_n < diff) {
                        diff = diff_n;
                        opt_str[idx] = set[idx] + opt_str[off];
                }
        }
}
bool partion_subset(int set[SIZ]) {
        int opt_str[SIZ];
        lco_(set,opt_str,0,22);
        for (uint32_t off0(0); off0 < SIZ; ++off0) {
                for (uint32_t off1(off0 + 1);off1 < SIZ; ++off1)
                        if (opt_str[off0] == opt_str[off1])
                                return true;
        }
        return false;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[int set[SIZ] = integer 1D array]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[bool -> 'true' if (A subset & B subset -> sum of A equal sum of B) else 'false' ]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[partion_subset(set) set = set[SIZ]{3,7,10,0}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
