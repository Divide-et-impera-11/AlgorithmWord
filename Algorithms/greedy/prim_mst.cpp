using namespace std;
#include <iostream>
#include <string>
#include <vector>
//---------------------Prim Minimum Spanning Tree---------------------
template<class Type>
inline pair<int, int> find_first_of(Type graph[][4], int line, int column, bool marked[]) {
        pair<int, int> edge(-1, -1);
        for (int offset(0); offset < column; ++offset) {
                if (graph[line][offset] != 0 && !marked[offset]) {
                        if (edge.first == -1 || graph[edge.first][edge.second] > graph[line][offset]) {
                                edge = make_pair(line, offset);
                        }
                }
        }
        return edge;
}
template<class Type>
inline void to_zero(Type* graph,size_t len) {
        for (uint32_t offset(0); offset < len; ++offset)
                *(graph + offset) = NULL;
}
template<class Type>
Type* prim_MST(Type graph[4][4]) {
        int32_t nodes = sizeof(graph);
        Type* mst = new Type[pow(nodes, 2)];
        pair<int, int> edge;
        bool *marked = new bool[nodes];
        to_zero<Type>(mst,pow(nodes, 2));
        to_zero<bool>(marked, nodes);

        for (int32_t line(0); line < nodes; ++line) {
                for (int32_t column(0); column < nodes; ++column) {
                    edge = find_first_of<Type>(graph, line, nodes, marked);
                        if (edge.first != -1) {
                                *(mst + (edge.first * nodes) + edge.second) = graph[edge.first][edge.second];
                                *(mst + (edge.second * nodes) + edge.first) = graph[edge.first][edge.second];
                                 marked[line] = true;
                        }
                }
        }
        return mst;
}
// Parameter List:
// (Type graph[x][y] where x = line and y = column) = graph

// Return Value Cases:
// Type* where Tpye = user defined tpye) = pointer to minimum spanning tree

// Function Call Example
/*int graph[4][4]{
{0,30,0,5},
{30,0,10,0},
{0,10,0,10},
{5,0,10,0}};
prim_MST(graph);
*/
