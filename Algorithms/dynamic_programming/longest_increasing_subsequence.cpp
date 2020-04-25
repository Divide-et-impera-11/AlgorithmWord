using namespace std;
#include <iostream>
#include <string>
#define SIZ 5
//----------Longest Increasing Subsequence----------
//Bottom-Up
void LIS(int num[SIZ]) {
        unsigned int opt_str[SIZ];
        for (int offset = SIZ - 1; offset >= 0; --offset) {
                opt_str[offset] = 1;
                for (unsigned int lc_opt = offset + 1; lc_opt < SIZ; lc_opt++) {
                        if (num[lc_opt] >= num[offset]) {
                                opt_str[offset] = max(opt_str[offset], opt_str[lc_opt] + 1);
                        }
                }
        }
        uint32_t max_ = 0;
        for (uint32_t i = 1; i < SIZ; ++i) {
                if (opt_str[i] > opt_str[max_])
                        max_ = i;
        }
        cout << "Longest Increasing Sequeane is:" << opt_str[max_] << " from index:" << max_ << endl;
        uint32_t state_id = max_,seq = opt_str[max_];
        while (seq){
                if (num[state_id] >= num[max_]) {
                        --seq;
                        max_ = state_id;
                        cout << num[state_id] << endl;
                }
                ++state_id;
        }

}
/*Parameter List:
 *
 *  |--Top-Down:  --->[]
 *- |
 *  |--Bottom-Up: --->[int num[SIZ] = integer 1D array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[]
 *- |
 *  |--Bottom-Up: --->[void]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[]
 *- |
 *  |--Bottom-Up: --->[LIS(num) num = num[SIZ]{3,6,7,4,3}]
 *
 */
