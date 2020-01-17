#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//---------------------Kruskal---------------------
#define SIZ 4
template<class Type>
void Kruskal(Type graph[SIZ][SIZ]) {
        int set[SIZ];
        vector<pair<int, int>> edges;
        for (uint32_t line(0); line < SIZ; ++line) {
                set[line] = line;
                for (uint32_t column(0); column < SIZ; ++column) {
                        if (graph[line][column] && line < column) {
                                edges.push_back(make_pair(line, column));
                        }
                }
        }
        sort(edges.begin(), edges.end(), [&](pair<int, int> &p0, pair<int, int> &p1) -> bool {return graph[p0.first][p0.second] < graph[p1.first][p1.second];});
        uint32_t idx = 0;
        while (idx < edges.size())
        {
                if (set[edges.at(idx).first] != set[edges.at(idx).second]) {
                        uint32_t set_id = set[edges.at(idx).second];
                        for (uint32_t offset(0); offset < SIZ; ++offset) {
                                if (set[offset] == set_id)
                                        set[offset] = set[edges.at(idx).first];
                        }
                }
                else {
                        edges.erase(edges.begin() + idx);
                        continue;
                }
                ++idx;
        }
        for (vector<pair<int, int>>::iterator iter = edges.begin(); iter != edges.end(); ++iter) {
                cout << iter->first << " " << iter->second << endl;
        }
}
// Parameter List:
//(Type graph[x][y] where x = line and y = column) = graph

// Return Value Cases:
// void

// Function Call Example
/*int graph[4][4]{
{0,30,0,5},
{30,0,10,0},
{0,10,0,10},
{5,0,10,0}};
Kruskal(graph);
*/
