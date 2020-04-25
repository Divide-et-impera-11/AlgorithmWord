using namespace std;
#include <iostream>
#include <string>
//------------Longest Palindromic Subsequence------------
uint32_t lps(string str,uint32_t x0,uint32_t x1) {
        uint32_t lc_opt = x0 == x1;
        for (uint32_t i0 = x0; i0 <= x1; ++i0) {
                for (uint32_t i1 = x1; i1 >= x0;--i1) {
                        if (str.at(x0) == str.at(i1)) {
                                lc_opt = max(lps(str, i0 + 1, i1 - 1) + (i0 == i1 ? 1 : 2), lc_opt);
                                break;
                        }
                }
        }
        return lc_opt;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string str = string,x0 = substring begin index,x1 = substring end index]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = longest palindromic subsequence]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[lps("abcba",0,4)]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
