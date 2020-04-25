using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
#define SIZ 3
//----------------Word Break----------------
bool word_break(string str,string words[SIZ]) {
        if(find_if(&words[0], &words[SIZ], [&](string w) -> bool {return w == str;}) < &words[SIZ])
                return true;
        for (uint32_t count(1); count < str.length(); ++count) {
                if (word_break(str.substr(0,count),words) && word_break(str.substr(count,str.length() - count),words))
                        return true;
        }
        return false;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string str = string to seperate,string words[SIZ] = dictionary  of words]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[bool -> 'true' if 'str' can seperate to the words of dictionary else 'false']
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[word_break("applevssamsung",words) words = words[SIZ]{"apple","vs","samsung"}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
