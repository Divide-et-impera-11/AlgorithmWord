using namespace std;
#include <iostream>
#include <string>
//-------------Wildcard Pattern Matching-------------
uint32_t _lco(string &ptr,string &str,size_t i0,size_t i1,uint32_t SV) {
        if (i0 != ptr.length() && i1 != str.length()) {
                if (ptr[i0] == '*')
                        for (uint32_t hold(0); hold <= (str.length() - i1); ++hold)
                                SV = min(_lco(ptr, str, i0 + 1, i1 + hold, SV - hold), SV);
                else if (ptr[i0] == '?')
                        SV = _lco(ptr, str, i0 + 1, i1 + 1, SV - 1);
                else if (ptr[i0] == str[i1])
                        SV = _lco(ptr, str, i0 + 1, i1 + 1, SV - 2);
        }
        return SV;
}
bool wildcard_p(string ptr,string str) {
        size_t count(0);
        for (auto itr = ptr.begin(); itr != ptr.end(); itr++)
                if (*itr != '?' && *itr != '*')
                        ++count;
        return !static_cast<bool>(_lco(ptr,str,0,0,count + str.length())); //if zero state -> yes | else -> no
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string ptr = pattern,string str = string]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[bool -> true if 'string' can matching on 'pattern' else false]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[wildcard_p(string("a*l?"),string("apple"))]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
