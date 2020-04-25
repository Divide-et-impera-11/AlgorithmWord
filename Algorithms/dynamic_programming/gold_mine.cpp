using namespace std;
#include <iostream>
#include <string>
#define ROW 2
#define COL 2
//------------Gold Mine------------
uint32_t _max(uint32_t x, uint32_t y, uint32_t z) {
        return max(max(x, y), z);
}
uint32_t _lco(uint32_t mine[ROW][COL],int32_t y,int32_t x) {
        return _max(mine[y][x] + (x + 1 < COL && y - 1 >= 0 ? _lco(mine, y - 1, x + 1) : 0),
                           mine[y][x] + (x + 1 < COL ? _lco(mine, y, x + 1) : 0),
                           mine[y][x] + (x + 1 < COL && y + 1 < ROW ? _lco(mine, y + 1, x + 1) : 0));
}
uint32_t gold_miner(uint32_t mine[ROW][COL]) {
        uint32_t global_o = 0;
        for (uint32_t offset(0); offset < COL; ++offset)
                global_o = max(_lco(mine, offset, 0), global_o);
        return global_o;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t mine[ROW][COL] = mine]
 *- |
 *  |--Bottom-Up: --->[]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t max gold to collect only move to 'right','right-up','right-down']
 *- |
 *  |--Bottom-Up: --->[]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[gold_miner(mine) mine = mine[ROW][COL]{{0,1}{0,1}}]
 *- |
 *  |--Bottom-Up: --->[]
 *
 */
