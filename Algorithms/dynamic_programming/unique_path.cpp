using namespace std;
#include <iostream>
#include <string>
//------------Unique Path------------
//Top-Down
uint32_t uq_pth(const size_t &lin, const size_t &row, uint32_t y,uint32_t x) {
        if (y == lin || x == row)
                return 0;
        if (y == lin - 1 && x == row - 1)
                return 1;
        return uq_pth(lin, row, y + 1, x) + uq_pth(lin, row, y, x + 1);
}
//Bottom-Up
uint32_t uq_pth(const size_t &lin, const size_t &row) {
        uint32_t**mtx = new uint32_t*[lin];
        for (uint32_t i(0); i < lin; i++) {
                mtx[i] = new uint32_t[row];
                memset(mtx[i], 0, sizeof(uint32_t)*row);
        }
        mtx[lin - 1][row - 1] = 1;
        for (uint32_t l(lin - 1); l >= 1; --l) {
                for (uint32_t r(row - 1); r >= 1; r--) {
                        mtx[l][r - 1] += mtx[l][r];
                        mtx[l - 1][r] += mtx[l][r];

                }
        }
        return (mtx[0][1] + mtx[1][0]);
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[const size_t &lin = matrix line, const size_t &row = matrix row, uint32_t y = line position,uint32_t x = row position]
 *- |
 *  |--Bottom-Up: --->[const size_t &lin = matrix line, const size_t &row = matrix row]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = all unique path from matrix[0][0] to matrix[LINE - 1][ROW - 1]]
 *- |
 *  |--Bottom-Up: --->[uint32_t = all unique path from matrix[0][0] to matrix[LINE - 1][ROW - 1]]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[uq_pth(size_t(5),size_t(5),0,0)]
 *- |
 *  |--Bottom-Up: --->[uq_pth(size_t(5),size_t(5))]
 *
 */
