using namespace std;
#include <iostream>
#include <string>
//--------------Matrix Chain Multiplication--------------
//Top-Down
uint32_t matrix_chain(uint32_t *mtx,size_t siz) {
        uint32_t min_op = (siz == 1 ? 0 : UINT32_MAX);
        for (uint32_t offset(1); offset < siz; ++offset) {
                //Set of A ROW mtx[0] COL mtx[offset]
                //Set of B ROW mtx[offset] COL mtx[siz - 1]
                min_op = min(matrix_chain(mtx,offset) + matrix_chain(mtx + offset,siz - offset) + (mtx[0] * mtx[offset] * mtx[siz]),min_op);

        }
        return min_op;
}
//Bottom-Up
uint32_t matrix_chain(uint32_t *mtx, size_t len) {
        uint32_t **oss = new uint32_t*[len];
        for (uint32_t offset(0); offset < len; ++offset) {
                oss[offset] = new uint32_t[len];
                memset(oss[offset], 0, sizeof(uint32_t) * len);
        }
        uint32_t lco, A, B, A2, B2;
        for (uint32_t tmtx(1); tmtx < len; ++tmtx) {
                lco = oss[tmtx - 1][tmtx - 1] + (mtx[0] * mtx[tmtx] * mtx[tmtx + 1]);
                for (uint32_t bmtx(tmtx - 1), offset(0); bmtx >= 1; --bmtx) {
                        A = oss[bmtx - 1][bmtx - 1];
                        A2 = oss[tmtx - 1][offset];
                        B2 = 0;
                        B = A2 + B2 + (mtx[bmtx] * mtx[tmtx] * mtx[tmtx + 1]);
                        lco = min(A + B + (mtx[0] * mtx[bmtx] * mtx[tmtx + 1]), lco);
                        oss[tmtx][offset + 1] = B;
                        ++offset;
                }
                oss[tmtx][tmtx] = lco;
        }
        return oss[len - 1][len - 1];
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t *mtx = array of matrixes,size_t siz = size of array(matrix)]
 *- |
 *  |--Bottom-Up: --->[uint32_t *mtx = array of matrixes,size_t siz = size of array(matrix)]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = Maximum Multiplication of Matrixes]
 *- |
 *  |--Bottom-Up: --->[uint32_t = Maximum Multiplication of Matrixes]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[matrix_chain(mtx,3) mtx = mtx = new uint32_t[4]{5,3,7,2}]
 *- |
 *  |--Bottom-Up: --->[matrix_chain(mtx,3) mtx = mtx = new uint32_t[4]{4,3,20,14}]
 *
 */
