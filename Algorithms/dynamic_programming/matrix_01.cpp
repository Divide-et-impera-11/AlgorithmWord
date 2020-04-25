using namespace std;
#include <iostream>
#include <string>
#include <vector>
#define MLIN 4
#define MCOL 4
//----------------------Matrix_01----------------------
struct Matrix {
public:
        Matrix() = default;
        ~Matrix() = default;
        pair<uint32_t, uint32_t> p0;
        pair<uint32_t, uint32_t> p1;
};
//Top-Down
Matrix local_opt(bool m[MLIN][MCOL],uint32_t lin_p,uint32_t col_p) {
        Matrix sub;
        uint32_t min_l(MCOL + 1);
        sub.p0 = make_pair(lin_p, col_p);
        sub.p1 = make_pair(lin_p, col_p);
        while (lin_p < MLIN && m[lin_p][col_p])
        {
                uint32_t counter = 1;
                while (col_p + counter < MCOL && m[lin_p][col_p + counter]){
                        ++counter;
                }
                min_l = min(min_l, counter);
                if ((lin_p - sub.p0.first + 1) * min_l > (sub.p1.first - sub.p0.first + 1) * (sub.p1.second - sub.p0.second + 1)) {
                        sub.p1.first = lin_p;
                        sub.p1.second = col_p + min_l - 1;
                }
                ++lin_p;
        }
        return sub;
}
Matrix matrix_01(bool m[MLIN][MCOL]) {
        vector<Matrix> opt_str;
        for (uint32_t lin(0); lin < MLIN; lin++) {
                for (uint32_t col(0); col < MCOL; col++) {
                        if (m[lin][col]) {
                                opt_str.push_back(local_opt(m,lin,col));
                        }
                }
        }
        auto global_opt = opt_str.begin();
        for (auto itr = opt_str.begin() + 1; itr != opt_str.end(); ++itr) {
                if ((itr->p1.first - itr->p0.first + 1) * (itr->p1.second - itr->p0.second + 1) < (global_opt->p1.first - global_opt->p0.first) * (global_opt->p1.second - global_opt->p0.second))
                        global_opt = itr;
        }
        return *global_opt;
}
//Bottom-Up
void matrix_10(bool m[MLIN][MCOL]) {
        bool s[MLIN][MCOL];
        uint32_t lin, col;
        for (col = 0; col < MCOL; ++col)
                s[0][col] = m[0][col];

        for (lin = 0; lin < MLIN; ++lin)
                s[lin][0] = m[lin][0];

        for (lin = 1; lin < MLIN; ++lin) {
                for (col = 1; col < MCOL; ++col) {
                        if (m[lin][col]) {
                                s[lin][col] = min(m[lin][col - 1], m[lin - 1][col], m[lin - 1][col - 1]) + 1;
                        }
                }
        }
        uint32_t max_l, max_c,max_v = 0;
        for (lin = 0; lin < MLIN; ++lin) {
                for (col = 0; col < MCOL; ++col) {
                        if (s[lin][col] > max_v) {
                                max_v = s[lin][col];
                                max_l = lin;
                                max_c = col;
                        }
                }
        }
        cout << "The biggest square sub-matrix is: " << max_v << " on line:" << max_l << " and column:" << max_c << endl;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[bool m[MLIN][MCOL] = boolean 2D array]
 *- |
 *  |--Bottom-Up: --->[bool m[MLIN][MCOL] = boolean 2D array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[Matrix obj = Largest Sum Submatrix]
 *- |
 *  |--Bottom-Up: --->[void]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[matrix_01(m) m = m[MLIN][MCOL]{1,0,1...}]
 *- |
 *  |--Bottom-Up: --->[matrix_10(m) m = m[MLIN][MCOL]{1,0,1...}]
 *
 */
