using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
//---------------------Set Cover---------------------
vector<set<int>> set_cover() {
        vector<int> universe = { 1,2,3,4,5 };
        vector<set<int>> unio;
        vector<set<int>> S = {
                set<int>() = {1,2,3},
                set<int>() = {2,4},
                set<int>() = {3,4},
                set<int>() = {4,5}};
        sort(S.begin(), S.end(), [](set<int> &arg1, set<int> &arg2) -> bool {return arg1.size() > arg2.size();});
                for (vector<set<int>>::iterator iter = S.begin(); iter != S.end();++iter) {
                        for (uint32_t u_offset(0); u_offset < universe.size();) {
                                if (find_if(iter->begin(), iter->end(), [&](int arg1) -> bool {return arg1 == universe.at(u_offset);}) != iter->end()) {
                                        universe.erase(universe.begin() + u_offset);
                                        unio.push_back(*iter);
                                        continue;
                                }
                                u_offset++;
                        }
                        if (universe.empty())
                                break;
                }
        return unio;
}
// Parameter List:
// void

// Return Value Cases:
// vector<set<int>> = universe set

// Function Call Example
// set_cover();
