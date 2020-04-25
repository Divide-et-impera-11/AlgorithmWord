using namespace std;
#include <iostream>
#include <string>
//------------Build Bridge------------
inline bool find_cross(uint32_t **cty, const uint32_t &len,uint32_t trg) {
        for (uint32_t crs(0); crs < len; ++crs)
                if (cty[2][crs] && (cty[0][crs] < cty[0][trg] && cty[1][crs] > cty[1][trg] || cty[0][crs] > cty[0][trg] && cty[1][crs] < cty[1][trg]))
                        return true;
                return false;
}
//Top-Down
uint32_t bld_brg(uint32_t **cty, const uint32_t len,uint32_t **mem,size_t end) {
        for (uint32_t st(0); st < end; ++st)
                if (equal(cty[2], cty[2] + len, mem[st], mem[st] + len))
                        return mem[st][len];
        //get new state
        for (uint32_t nst(0); nst < len; ++nst)
                mem[end][nst] = cty[2][nst];

        uint32_t max_vl(0);
        for (uint32_t offset(0); offset < len; ++offset) {
                if (!cty[2][offset] && !find_cross(cty, len, offset)) {
                        cty[2][offset] = 1;
                        max_vl = max(1 + bld_brg(cty, len, mem, end + 1), max_vl);
                        cty[2][offset] = 0;
                }
        }
        return mem[end][len] = max_vl;
}
//Bottom-Up
struct CP {
public:
        uint32_t n, s, max;
};
uint32_t bld_brg(CP *cty, const uint32_t len) {
        CP **oss = new CP*[len];
        for (uint32_t i(0); i < len; ++i) {
                oss[i] = new CP[len];
                oss[0][i] = cty[i];
                oss[0][i].max = 1;
        }
        for (uint32_t n(1); n < len; ++n) {
                for (uint32_t c(0); c < len; c++) {
                        if (n != len - 1)
                                oss[n + 1][c] = oss[n][c];
                        for (uint32_t ct(0);ct < len; ++ct) {
                                for (uint32_t i = 0; i < n; i++) {
                                        if (!(oss[i][c].n > cty[i].n && oss[i][c].s < cty[i].s) || (oss[i][c].n < cty[i].n && oss[i][c].s > cty[i].s)) {
                                                oss[n][c].max = oss[n - 1][c].max + 1;
                                                oss[n][c].n = cty[i].n;
                                                oss[n][c].s = cty[i].s;
                                                break;
                                        }
                                }
                        }
                }
        }
        CP*max = &oss[len - 1][0];
        for (uint32_t i = 1; i < len; i++) {
                if (oss[len - 1][i].max > max->max)
                        max = &oss[len - 1][i];
        }
        return max->max;

}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t **cty = 2D array of cities, const uint32_t len = length of array,uint32_t **mem = 2D memorization array,size_t end = end of memorization array]
 *- |
 *  |--Bottom-Up: --->[CP *cty = array of CP, const uint32_t len = length of array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = maximum number of bridges to can build between east and north]
 *- |
 *  |--Bottom-Up: --->[uint32_t = maximum number of bridges to can build between east and north]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[bld_brg(cty,3,mem,0) cty = cty = new uint32_t[2][3]{{2,6,10}{3,8,2}}]
 *- |
 *  |--Bottom-Up: --->[bld_brg(cty,3) cty = new CP[3]{CP(2,3),CP(6,8),CP(10,2)}]
 *
 */
