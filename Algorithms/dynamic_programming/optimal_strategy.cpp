using namespace std;
#include <iostream>
#include <string>
#define SIZ 4
//------------Optimal Strategy------------
uint32_t opt_str(int coins[SIZ],int srt,int end) {

        if (srt <= end && (srt != 0 || end != SIZ - 1))
                coins[srt] > coins[end] ? srt += 1 : end =- 1;
        if (srt > end)
                return 0;
        return max(coins[srt] + opt_str(coins,srt + 1,end),coins[end] + opt_str(coins,srt, end - 1));
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[int coins[SIZ] = coin sequence,int srt = start of coin sequence,int end = end of coin sequence]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = max coin to collect]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[opt_str(coins,0,3) coins = coins[SIZ]{4,45,23,3}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
