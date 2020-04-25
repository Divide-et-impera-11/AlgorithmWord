using namespace std;
#include <iostream>
#include <string>
//--------------Dice Throw--------------
uint32_t dice(uint32_t n,uint32_t m,uint32_t x) {
        if (!n)
                return 1;
        uint32_t var = 0,thrw = 1;
        while (thrw <= m)
        {
                if((n - 1) * m >= (x - thrw) && (n - 1) <= (x - thrw))
                var += dice(n - 1, m, x - thrw);
                ++thrw;
        }
        return var;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t n = number of dices,uint32_t m = face of dice,uint32_t x = sum]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = number of combinations to throw the (x) (m) (n) x = sum,m = face, n = dices]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[dice(2,6,12)]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
