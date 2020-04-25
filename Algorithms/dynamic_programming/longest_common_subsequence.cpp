using namespace std;
#include <iostream>
#include <string>
//-----------Longest Common Subsequence-----------
void lc_opt(string &srt,string &lng,uint16_t*opt_str,uint16_t n) {
        if (n == srt.length())
                return;
        lc_opt(srt, lng, opt_str, n + 1);
        opt_str[n] = lng.find(srt[n]) < lng.length() ? 1 : 0;
        if (opt_str[n]) {
                uint16_t lcs = 1;
                for (uint16_t off(n + 1); off < srt.length(); ++off) {
                        if (opt_str[off] && (lng.find(srt[off], lng.find(srt[n])) < lng.length()) && (1 + opt_str[off]) > lcs)
                                lcs = 1 + opt_str[off];
                }
                opt_str[n] = lcs;
        }
}
void longest_common_subsequence(string str0,string str1) {
        uint16_t *opt_str = nullptr;
        str0.length() <= str1.length() ?
                lc_opt(str0, str1, opt_str = new uint16_t[str0.length()], 0) :
                lc_opt(str1, str0, opt_str = new uint16_t[str1.length()], 0);
        cout << opt_str[0];
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string str0 = first string,string str1 = second string]
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
 *  |--Top-Down:  --->[longest_common_subsequence(string("alma"),string("addlfmxy"))]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
