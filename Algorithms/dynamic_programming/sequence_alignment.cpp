using namespace std;
#include <iostream>
#include <string>
//------------Sequence alignment------------
//Top-Down
#define GAP_P 3
#define MISS_P 7
inline int min_p(int x, int y, int z) {
        return min(x, min(y, z));
}
uint32_t seq_ali(string X,string Y) {
        uint32_t pty = 0;
        for (int xi = 0, yi = 0; xi <= X.length() && yi <= Y.length(); ++xi,++yi) {
                if (xi == X.length() || yi == Y.length()) {
                        int diff = abs(int(X.length() - Y.length()));
                        pty += min(diff * GAP_P, diff * MISS_P);
                }
                else if(X[xi] != Y[yi]) {
                         pty += min_p(GAP_P + seq_ali(X.substr(xi,X.length() - xi),Y.substr(yi + 1,Y.length() - yi + 1)),
                         GAP_P + seq_ali(X.substr(xi + 1,X.length() - xi + 1), Y.substr(yi, Y.length() - yi)),
                         MISS_P + seq_ali(X.substr(xi + 1,X.length() - xi + 1), Y.substr(yi + 1,Y.length() - yi + 1)));
                }
        }
        return pty;
}
//Bottom-Up
uint32_t seq_ali(string X, string Y) {
        //Set Up
        int xl = X.length(), yl = Y.length(), av = abs(int(xl - yl)), m = min(xl, yl);
        uint32_t **oss = new uint32_t*[m + 1];
        for (int i = 0; i < m + 1; ++i) {
                oss[i] = new uint32_t[m + 1];
                for (int f = 0; f < (m + 1); ++f)
                        oss[i][f] = 0;
        }
        oss[m][m] = min(av * GAP_P, av * MISS_P);
        //Core
        for (int xi = m - 1, yi = m - 1; xi >= 0 && yi >= 0; xi--,yi--) {
                oss[xi][yi + 1] = oss[xi + 1][yi + 1] + GAP_P;
                oss[xi + 1][yi] = oss[xi + 1][yi + 1] + GAP_P;
                if (X[xi] != Y[yi]) {
           //3XI
                        oss[xi][yi] = min_p(GAP_P + oss[xi + 1][yi],
                                GAP_P + oss[xi][yi + 1],
                                MISS_P + oss[xi + 1][yi + 1]);
                }
                else {
                        oss[xi][yi] = oss[xi + 1][yi + 1];
                }
        }
        return oss[0][0];
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[string X = fist string,string Y = second string]
 *- |
 *  |--Bottom-Up: --->[string X = fist string,string Y = second string]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = minimum penalty to matching two string]
 *- |
 *  |--Bottom-Up: --->[uint32_t = minimum penalty to matching two string]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[seq_ali("CG","CA")]
 *- |
 *  |--Bottom-Up: --->[seq_ali("JL","LJ")]
 *
 */
