using namespace std;
#include <iostream>
#include <string>
//---------------N Step To Die In Island---------------
//Top-Down
float island(const uint32_t R, const uint32_t C, int32_t x, int32_t y, uint32_t n,float ***mem) {
        if (x < 0 || x == C || y < 0 || y == R)
                return 0;
        if (!n)
                return 1;
        return  mem[y][x][n - 1] != 0 ? mem[y][x][n - 1] : mem[y][x][n - 1] = (float)((island(R, C, x, y - 1, n - 1,mem) +
                island(R, C, x + 1, y, n - 1,mem) +
                island(R, C, x, y + 1, n - 1,mem) +
                island(R, C, x - 1, y, n - 1,mem)) / (float)4);
}
//Bottom-Up
float island(const uint32_t R, const uint32_t C, const int32_t Y, const int32_t X,const uint32_t N) {
        float ***oss = new float**[R];
        for (int r(0); r < R; ++r) {
                oss[r] = new float*[C];
                for (int c(0); c < C; ++c) {
                        oss[r][c] = new float[N + 1];
                        for (int i = 0; i < N + 1; ++i)
                                oss[r][c][i] = 1.0;
                        //memset(oss[r][c], int(1), sizeof(float) * (N + 1)); ???
                }
        }
        float sum;
        for (uint32_t n = 1; n <= N; ++n) {
                for (uint32_t r = 0; r < R; ++r) {
                        for (uint32_t c = 0; c < C; ++c) {
                                sum = 0.0;
                                //up
                                sum += r == 0 ? 0 : oss[r - 1][c][n - 1];
                                //right
                                sum += c == C - 1 ? 0 : oss[r][c + 1][n - 1];
                                //bottom
                                sum += r == R - 1 ? 0 : oss[r + 1][c][n - 1];
                                //left
                                sum += c == 0 ? 0 : oss[r][c - 1][n - 1];
                                oss[r][c][n] = sum / 4;
                        }
                }
        }
        return oss[Y][X][N];
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[const uint32_t R = Row, const uint32_t C = Column, int32_t x = column position, int32_t y = row position, uint32_t n = steps,float ***mem = memorization array]
 *- |
 *  |--Bottom-Up: --->[const uint32_t R = Row, const uint32_t C = Column, const int32_t Y = row position, const int32_t X = row position,const uint32_t N = steps]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[float = chance to survive]
 *- |
 *  |--Bottom-Up: --->[float = chance to survive]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[island(5,5,2,1,4,mem)]
 *- |
 *  |--Bottom-Up: --->[island(5,5,2,1,4)]
 *
 */
