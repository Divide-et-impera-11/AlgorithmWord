using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
//---------------Word Wrap---------------
//Top-Down
uint32_t wrap(string *wrd, size_t len, size_t limit, size_t plnl,uint32_t*rec,size_t li) {
        uint32_t cd, lnl(0),sv;
        cd = !len ? 0 : UINT32_MAX;
        for (uint32_t i(0); i < len; ++i) {
                if (wrd[i].length() + lnl <= limit) {
                        lnl += wrd[i].length();
                        sv = abs(int(lnl - plnl)) + wrap(wrd + (i + 1), len - (i + 1), limit, lnl, rec, li + 1);
                        if (sv < cd) {
                                cd = sv;
                                rec[li] = lnl;
                        }
                }
                else break;
        }
        return cd;
}
void word_line_wrap(string *wrd,size_t len,size_t limit) {
        uint32_t *rec = new uint32_t[len];
        uint32_t sum(0);
        memset(rec, 0, sizeof(uint32_t)*len);
        sum = accumulate(wrd, wrd + len, sum, [](uint32_t s, string w) {return s += w.length();});
        wrap(wrd, len, limit, sum, rec, 0);
        //recontstruction
        int wi = 0, li = 0;
        while (wi < len)
        {
                sum = 0;
                sum = wrd[wi].length();
                while (sum <= rec[li])
                {
                        cout << wrd[wi] << " ";
                        sum += wrd[++wi].length();
                }
                cout << endl;
                ++li;
        }
}
//Bottom-Up
inline uint32_t sum(string *wrd,size_t f,size_t t) {
        uint32_t sum = 0;
        for (int i = f; i < t; ++i)
                sum += wrd[i].length();
        return sum;
}
void word_line_wrap_bu(string *wrd, size_t len, size_t limit) {
        uint32_t *lin, *cd,lnl,vl;
        lin = new uint32_t[len + 1];
        cd = new uint32_t[len + 1];
        memset(cd, UINT32_MAX, sizeof(uint32_t) * (len + 1));
        memset(lin, 0, sizeof(uint32_t) * (len + 1));
        cd[len] = 0;
        for (int32_t si = len - 1; si >= 0; si--) {
                lnl = 0;
                lin[len] = sum(wrd, si, len);//sum
                for (int32_t wi = si; wi < len; wi++) {
                        lnl += wrd[wi].length();
                        if (lnl <= limit) {
                                vl = abs(int(lnl - lin[wi + 1])) + cd[wi + 1];
                                if (vl < cd[si]) {
                                        cd[si] = vl;
                                        lin[si] = lnl;
                                }
                        }
                        else break;
                }
        }
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string *wrd = array of words,size_t len = length of array,size_t limit = line limit]
 *- |
 *  |--Bottom-Up: --->[string *wrd = array of words,size_t len = length of array,size_t limit = line limit]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[void]
 *- |
 *  |--Bottom-Up: --->[void]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[word_line_wrap(wrd,3,7) wrd = wrd = new string[3]{"apple","samsung","sheep"}]
 *- |
 *  |--Bottom-Up: --->[word_line_wrap_bu(wrd,3,7) wrd = wrd = new string[3]{"apple","samsung","sheep"}]
 *
 */
