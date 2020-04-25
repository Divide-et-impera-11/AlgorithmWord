using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
//------------Bellman Ford------------
//Top-Down
#define ROW 4
#define COL 4
int32_t bellm_ford(int32_t g[ROW][COL],uint32_t path[ROW],size_t plen,uint32_t state,uint32_t trg) {
        if (state == trg)
                return 0;
        int32_t max_vl = INFINITY;
        for (uint32_t offset(0); offset < COL;++offset) {
                if (g[state][offset] != INFINITY && find(path,path + plen + 1,offset) == (path + ROW)) {
                        path[plen] = offset;
                        max_vl = min(g[state][offset] + bellm_ford(g,path,plen + 1,offset, trg), max_vl);
                }
        }
        path[plen] = INFINITY;
        return max_vl;
}
//Bottom-Up
void bellman_ford(int g[ROW][COL]) {
        int vrtx = COL;
        int dist[ROW][COL];
        for (int i = 0; i < ROW; i++) {
                for (int i2 = 0; i2 < COL; i2++)
                        dist[i][i2] = INT_MAX;
        }
        for (int src = 0; src < vrtx; ++src) {
                dist[src][src] = 0;
                        for (int trg = 0; trg < vrtx; ++trg) {
                                for (int d = 0; d < vrtx; ++d) {
                                        if(dist[src][d] != INT_MAX && g[d][trg] != INT_MAX)
                                    dist[src][trg] = min(dist[src][trg],dist[src][d] + g[d][trg]);
                        }
                }
        }
        for (int i = 0; i < ROW; i++) {
                for (int i2 = 0; i2 < COL; i2++)
                        cout << dist[i][i2] << " ";
                cout << endl;
        }
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[int32_t g[ROW][COL] = graph,uint32_t path[ROW] = paths,size_t plen = length of path array,uint32_t state = state,uint32_t trg = target]
 *- |
 *  |--Bottom-Up: --->[int g[ROW][COL] = graph]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[int32_t = shortest path from source to target]
 *- |
 *  |--Bottom-Up: --->[void]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[bellm_ford(g,path,0,0,0,0)]
 *- |
 *  |--Bottom-Up: --->[bellman_ford(g) g = g[ROW][COL]{{0,5,INT32_MAX,10},{INT32_MAX,0,3,INT32_MAX},{INT32_MAX,INT32_MAX,0,1},{INT32_MAX,INT32_MAX,INT32_MAX,0}}]
 *
 */
