using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stack>
//---------------------Dijkstra---------------------
#define SIZ 3
template<class Type>
bool sortest_path(Type graph[SIZ][SIZ],stack<int>& stack,uint32_t end_pt,uint32_t srt_ph,uint32_t way) {
        if (stack.top() == end_pt && srt_ph == way)
                return true;
        for (uint32_t offset(0); offset < SIZ; ++offset) {
                if (graph[stack.top()][offset] && (graph[stack.top()][offset] + way) <= srt_ph) {
                        way += graph[stack.top()][offset];
                        stack.push(offset);
                        if (sortest_path<Type>(graph, stack, end_pt, srt_ph, way))
                                return true;
                        way -= graph[stack.top()][offset];
                }
        }
        stack.pop();
        return false;
}
template<class Type>
void Dijkstra(Type graph[SIZ][SIZ],uint32_t str) {
        int key[SIZ];
        bool set[SIZ];
        int min_idx;
        stack<int> stack;
        stack.push(str);
        for (uint32_t offset(0); offset < SIZ; ++offset) {
                key[offset] = INT_MAX;
                set[offset] = false;
        }
        key[str] = 0;
        while (!stack.empty())
        {
                min_idx = -1;
                for (uint32_t offset(0); offset < SIZ; ++offset) {
                        if (graph[stack.top()][offset] && !set[offset]) {
                           //Sortest Path
                                key[offset] = min(key[stack.top()] + graph[stack.top()][offset],key[offset]);
                           //Min
                                if (min_idx == -1 || key[offset] < key[min_idx])
                                        min_idx = offset;
                        }
                }
                set[stack.top()] = true;
                if (min_idx == -1)
                        stack.pop();
                else
                        stack.push(min_idx);
        }
        //Srt Path
        uint32_t end_pt = 2;
        stack.push(end_pt);
        while (stack.top() != str)
        {
                for (uint32_t offset(0); offset < SIZ; ++offset) {
                        if (graph[stack.top()][offset] && (key[offset] + graph[stack.top()][offset]) == key[stack.top()]) {
                                stack.push(offset);
                                break;
                        }
                }
        }
        stack.push(str);
        sortest_path<Type>(graph,stack,2,key[2],0);
        while (!stack.empty())
        {
                cout << stack.top();
                stack.pop();
        }
        for (int i = 0; i < SIZ; i++) {
                cout << "From:" << str << " To:" << i << " the sortest path is:" << key[i] << endl;
        }
}
// Parameter List:
// (Type graph[x][y] where x = line and y = column) = graph
// uint32_t str = start node

// Return Value Cases:
// void

// Function Call Example
/*
 *int graph[SIZ][SIZ]{
            {0,1,10},
            {1,0,30},
            {10,30,0}};
  Dijkstra(graph,0);
*/

