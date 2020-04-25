using namespace std;
#include <iostream>
#include <string>
#define SIM 3
#define OPE SIM - 1
//-----------Boolean Parenthesization-----------
uint32_t bp(char s[SIM],char o[OPE],size_t off,bool flag) {
        bool v = s[off] == 'T';
        if (off == SIM - 1)
                return v == flag;
        uint32_t var = 0;
        while (off < SIM - 1) {
                if (o[off] == '&')
                        var += v && flag ? bp(s, o, off + 1, true) :
                        v && !flag ? bp(s, o, off + 1, false) :
                        !v && flag ? 0 :
                        !v && !flag ? bp(s, o, off + 1, true) + bp(s, o, off + 1, false) :
                        NULL;
                else if (o[off] == '|')
                        var += v && flag ? bp(s, o, off + 1, true) + bp(s, o, off + 1, false) :
                        v && !flag ? 0 :
                        !v && flag ? bp(s, o, off + 1, true) :
                        !v && !flag ? bp(s, o, off + 1, false) :
                        NULL;
                else if (o[off] == '^')
                        var += v && flag ? bp(s, o, off + 1, false) :
                        v && !flag ? bp(s, o, off + 1, true) :
                        !v && flag ? bp(s, o, off + 1, true) :
                        !v && !flag ? bp(s, o, off + 1, false) :
                        NULL;
                bool n = s[off + 1] == 'T';
                v = o[off] == '&' ? v && n :
                        o[off] == '|' ? v || n :
                        o[off] == '^' ? v ^ n : NULL;
                ++off;
        }
        return var;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[char s[SIM] = sequence of boolean values,char o[OPE] = operators between boolean values,size_t off = offset,bool flag = boolean status]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = number of combinations to set 'true' the equation]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[bp(s,o,0,true) s = s[SIM]{'T','F','T'} o = o[OPE]{'^','&'}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
