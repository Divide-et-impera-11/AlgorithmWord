using namespace std;
#include <iostream>
#include <string>
#define MROW 4
#define MCOL 3
//------------N Digit Number Mobile Keypad------------
//Top-Down
uint32_t _lco(uint32_t mobile[MROW][MCOL], int32_t**mem, uint32_t y, uint32_t x, const uint32_t N) {
        if (mobile[y][x] == UINT32_MAX)
                return 0;
        else if (N == 1)
                return 1;
        if (mem[mobile[y][x]][N - 1] != -1)
                return mem[mobile[y][x]][N - 1];//State (Number of the Mobile)
        uint32_t max_vl = 0;
        //Up
        if (y > 0) max_vl += _lco(mobile, mem, y - 1, x, N - 1);
        //Left
        if (x > 0) max_vl += _lco(mobile, mem, y, x - 1, N - 1);
        //Right
        if (x < MCOL - 1) max_vl += _lco(mobile, mem, y, x + 1, N - 1);
        //Bottom
        if (y < MROW - 1) max_vl += _lco(mobile, mem, y + 1, x, N - 1);
        //Itself
        max_vl += _lco(mobile, mem, y, x, N - 1);
        return mem[mobile[y][x]][N - 1] = max_vl;
}
uint32_t mobile_num(const uint32_t N) {
        int32_t **mem = new int32_t*[10];
        for (int i = 0; i < 10; ++i) {
                mem[i] = new int32_t[N];
                memset(mem[i], -1, sizeof(int32_t) * N);
        }
        uint32_t mobile[MROW][MCOL];
        for (int i = 0,c = 1; i < MROW - 1; ++i)
                for (int i2 = 0; i2 < MCOL; i2++,c++)
                        mobile[i][i2] = c;

        mobile[MROW - 1][0] = mobile[MROW - 1][MCOL - 1] = UINT32_MAX;
        mobile[MROW - 1][1] = 0;
        uint32_t max_vl = 0;;
        for (int i = 0; i < MROW; ++i)
                for (int i2 = 0; i2 < MCOL; i2++)
                        max_vl += _lco(mobile, mem,i, i2, N);
        return max_vl;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[const uint32_t N = length of combiation]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = number of combinations to press 'N' buttons]
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[mobile_num(3)]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
