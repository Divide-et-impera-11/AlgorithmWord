using namespace std;
#include <iostream>
#include <string>
//--------------All Possible Decoding--------------
inline uint32_t _dc(string c) {
        return atoi(c.c_str()) > 0 && atoi(c.c_str()) < 27;
}
uint32_t decoing(string seq) {
        if (seq.empty())
                return 1;
        return  (_dc(seq.substr(0, 1)) * decoing(seq.substr(1, seq.length() - 1))) + (seq.length() > 1 ? _dc(seq.substr(0, 2)) * decoing(seq.substr(2, seq.length() - 2)) : 0);
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string seq = digit sequence]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = number of combination to decoding the sequence]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[decoing(string("121"))]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
