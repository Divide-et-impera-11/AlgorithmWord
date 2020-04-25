using namespace std;
#include <iostream>
#include <string>
//--------------Shortest Common Supersequence--------------
inline string add_ssq(string seq,const char c) {
        return seq.empty() ? seq = c : seq.back() == c ? seq : seq += c;
}
uint32_t shrt_seq(string seq,string &str1,string &str2,size_t ins1,size_t ins2) {
        if (ins1 == str1.length() && ins2 == str2.length()) {
                return seq.length();
        }
        return min(ins1 < str1.length() ? shrt_seq(add_ssq(seq,str1[ins1]),str1,str2,ins1 + 1,ins2) : UINT32_MAX,
                ins2 < str2.length() ? shrt_seq(add_ssq(seq, str2[ins2]), str1, str2, ins1, ins2 + 1) : UINT32_MAX);
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string seq = sequence,string &str1 = first string,string &str2 = second string,size_t ins1 = size of first string inside sequence,size_t ins2 = size of second string inside sequence]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = lenght of shortest common supersequence]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[shrt_seq(string(""),string("apple"),string("appleX"),0,0)]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
