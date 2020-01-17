using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
//---------------------AStar---------------------
#define ROW 4
#define COL 4
class Cell {
public:
        Cell(uint32_t y, uint32_t x) :
                y(y),
                x(x) {
                NULL;
        }
        Cell() = default;
        ~Cell() = default;
        Cell(const Cell& rc) {
                this->x = rc.x;
                this->y = rc.y;
                this->h = rc.h;
                this->g = rc.g;
                this->f = rc.f;
        }
        constexpr bool operator<(const Cell* e) {
                return this->f < e->f;
        }
        uint32_t x, y, g;
        double h, f;
private:
protected:
};
inline double h(pair<uint32_t, uint32_t> &p, pair<uint32_t, uint32_t> &q) {
        return sqrt(pow(abs((int)(p.first - q.first)), 2) + pow(abs((int)(p.second - q.second)), 2));
}
inline void setUp(Cell map[ROW][COL],bool closeList[ROW][COL],pair<uint32_t, uint32_t> &src, pair<uint32_t, uint32_t> &trg) {
        memset(closeList, false, sizeof(closeList)); //closed set
        for (uint32_t row(0); row < ROW; ++row) { //open set
                for (uint32_t col(0); col < COL; ++col) {
                        Cell& c = map[row][col];
                        c.y = row;
                        c.x = col;
                        c.f = UINT_MAX;
                        c.h = UINT_MAX;
                        c.g = UINT_MAX;
                }
        }
        Cell& source = map[src.first][src.second];
        source.g = 0;
        source.h = h(make_pair(source.y, source.x), trg);
        source.f = source.g + source.h;
}
vector<pair<uint32_t, uint32_t>> valid_pos(int32_t y, int32_t x) {
        vector<pair<uint32_t, uint32_t>> pos;
        if (x - 1 >= 0) pos.push_back(make_pair(y, x - 1));
        if (x + 1 < COL) pos.push_back(make_pair(y, x + 1));
        if (y - 1 >= 0)  pos.push_back(make_pair(y - 1, x));
        if (y + 1 < ROW) pos.push_back(make_pair(y + 1, x));
        if (x + 1 < COL && y - 1 >= 0) pos.push_back(make_pair(y - 1, x + 1));
        if (x + 1 < COL && y + 1 < ROW) pos.push_back(make_pair(y + 1, x + 1));
        if (x - 1 >= 0 && y + 1 < ROW) pos.push_back(make_pair(y + 1, x - 1));
        if (x - 1 >= 0 && y - 1 >= 0) pos.push_back(make_pair(y - 1, x - 1));
        return pos;
}
void gameAStar(bool grid[ROW][COL], pair<uint32_t, uint32_t> &src, pair<uint32_t, uint32_t> &trg) {
        Cell map[ROW][COL];
        auto srt = [](Cell *arg0, Cell *arg1) -> bool { return arg0->f < arg1->f; };
        set<Cell*, decltype(srt)> openList(srt);
        bool closeList[ROW][COL];
        vector<pair<uint32_t, uint32_t>> vld_p;
        setUp(map,closeList,src,trg);
        openList.insert(&map[src.first][src.second]);
        while (!openList.empty())
        {
                const Cell &pos = **openList.begin();
                if (pos.y == trg.first && pos.x == trg.second)
                        break;
                vld_p = valid_pos(pos.y, pos.x);
                for (auto itr = vld_p.begin(); itr != vld_p.end(); ++itr) {
                        Cell &e = map[itr->first][itr->second];
                        if (!(grid[itr->first][itr->second] && closeList[itr->first][itr->second])) {
                                if (e.f == UINT_MAX) {
                                        e.h = h(make_pair(e.y, e.x), trg);
                                        e.g = pos.g + 1;
                                        e.f = e.g + e.h;
                                        openList.insert(&e);
                                }
                                else {
                                        e.g = min(pos.g + 1, e.g);
                                        e.f = e.g + e.h;
                                }
                        }
                }
                closeList[pos.y][pos.x] = true;
                openList.erase(find_if(openList.begin(), openList.end(), [&](const Cell* c_ptr) -> bool {return c_ptr == &pos;}));
        }
}
// Parameter List:
// bool grid[ROW][COL] = map
// pair<uint32_t, uint32_t> &src, = start
// pair<uint32_t, uint32_t> &trg =  target

// Return Value Cases:
// void

// Function Call Example
/*bool map[LIN][COL] = {
        {0,0,0,0},
        {0,1,1,1},
        {0,0,0,0},
        {1,1,0,0},
        {0,0,0,0}};
  gameAStar(map, make_pair<uint32_t, uint32_t>(4, 0), make_pair<uint32_t, uint32_t>(0,3));
*/

