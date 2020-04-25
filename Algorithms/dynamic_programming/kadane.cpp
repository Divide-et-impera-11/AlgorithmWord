using namespace std;
#include <iostream>
#include <string>
#define SIZ 5
//---------------Kadane---------------
//Top-Down
int lc_opt(int num[SIZ],int opt_str[SIZ],unsigned int idx) {
        return idx == SIZ - 1 ? opt_str[idx] = num[idx] : opt_str[idx] = max(num[idx], lc_opt(num,opt_str,idx + 1) + num[idx]);
}
void Kadane(int num[SIZ]) {
        int opt_str[SIZ];
        lc_opt(num, opt_str, 0);
        unsigned max_idx = 0;
        int max_subarr,sum = 0;
        for (auto i = 0; i < SIZ; i++){
                if (opt_str[max_idx] < opt_str[i])
                        max_idx = i;
        }
        max_subarr = opt_str[max_idx];
        cout << "The biggest subarray is:" << max_subarr << endl << "From:" << endl;
        do {
                sum += num[max_idx];
                cout << num[max_idx] << endl;
                max_idx++;
        } while (sum != max_subarr);
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[int num[SIZ] = integer 1D array]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[void]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[Kadane(num) num = num[SIZ]{34,2,-100,200,-10}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
