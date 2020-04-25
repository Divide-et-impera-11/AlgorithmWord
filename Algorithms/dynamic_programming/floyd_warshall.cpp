using namespace std;
#include <iostream>
#include <string>
//---------------Floyd Warshall---------------
//Top-Down
void shr_ps(uint32_t **mtx,const size_t len,uint32_t **pth,const uint32_t src, uint32_t trg,size_t path) {
        if (path < pth[src][trg])
                pth[src][trg] = path;
        for (uint32_t ni(0); ni < len; ++ni) {
                if (ni != trg && mtx[trg][ni] != UINT32_MAX)
                        shr_ps(mtx,len,pth,src,ni,path + mtx[trg][ni]);
        }
}
void fw_shrt_pth(uint32_t**mtx,const size_t len) {
        uint32_t**pth = new uint32_t*[len];
        for (uint32_t i(0); i < len; ++i) {
                pth[i] = new uint32_t[len];
                memset(pth[i], UINT32_MAX, sizeof(uint32_t) * len);
                shr_ps(mtx, len, pth, i, i, 0);
                for (uint32_t ni(0); ni < len; ++ni)
                        if (pth[i][ni] != UINT32_MAX)
                                cout << "Shortest Path From:" << i << " to:" << ni << " = " << pth[i][ni] << endl;
        }
}
//Bottom-Up
#define V 2
#define INF 99999
void floydWarshall(int graph[][V])
{
        int dist[V][V], i, j, k;
        for (i = 0; i < V; i++)
                for (j = 0; j < V; j++)
                        dist[i][j] = graph[i][j];
        for (k = 0; k < V; k++)
        {
                for (i = 0; i < V; i++)
                {
                        for (j = 0; j < V; j++)
                        {
                                if (dist[i][k] + dist[k][j] < dist[i][j])
                                        dist[i][j] = dist[i][k] + dist[k][j];
                        }
                }
        }
}

/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t **mtx = matrix(graph),const size_t len = length of matrix]
 *- |
 *  |--Bottom-Up: --->[int graph[][V] = graph]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[void]
 *- |
 *  |--Bottom-Up: --->[void]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[fw_shrt_pth(mtx,2) mtx = mtx[2][2]{{0,2}{2,0}}]
 *- |
 *  |--Bottom-Up: --->[floydWarshall(graph) graph = graph[V][V]{{0,2}{2,0}}]
 *
 */
