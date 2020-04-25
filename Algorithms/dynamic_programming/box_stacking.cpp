using namespace std;
#include <iostream>
#include <string>
#include <algorithm>
//---------------Box Stacking---------------
//Top-Down
struct Box {
public:
        uint32_t w, h, d;
        Box(uint32_t w, uint32_t h, uint32_t d) :w(w), h(h), d(d) {
                NULL;
        }
};
uint32_t box_stack(Box* boxes, size_t len,Box* top, uint32_t area) {
        uint32_t max_vl = 0;
        for (uint32_t offset(0); offset < len; ++offset) {
                Box* bx = boxes + offset;
                if (top == nullptr) {
                        max_vl = max(bx->h + box_stack(boxes, len, bx, bx->w * bx->d), max_vl);
                        max_vl = max(bx->d + box_stack(boxes, len, bx, bx->w * bx->h), max_vl);
                        max_vl = max(bx->w + box_stack(boxes, len, bx, bx->h * bx->d), max_vl);
                        continue;
                }
                //...
                if(area > (bx->w * bx->d)) max_vl = max(bx->h + box_stack(boxes, len, bx, bx->w * bx->d), max_vl);
                if(area > (bx->w * bx->h)) max_vl = max(bx->d + box_stack(boxes, len, bx, bx->w * bx->h), max_vl);
                if(area > (bx->h * bx->d)) max_vl = max(bx->w + box_stack(boxes, len, bx, bx->h * bx->d), max_vl);

        }
        return max_vl;
}
//Bottom-Up
uint32_t factorial(uint32_t num) {
        uint32_t res = 1;
        while (num) res *= num--;
        return res;
}
class Level {
public:
        uint32_t height,area;
        Level(uint32_t height, uint32_t area) : height(height), area(area) {
                NULL;
        }
        Level(Level& ref) {
                this->height = ref.height;
                this->area = ref.area;
        }
        Level() = default;
};
uint32_t box_stack(Box* boxes, size_t len) {
        const uint32_t RW = factorial(len * 3), LN = len * 3;
        Level** oss = new Level*[LN];
        for (uint32_t i(0); i < LN; ++i)
                oss[i] = new Level[RW];
        //Build first Row
        for (uint32_t bi(0),ri(0); bi < len; ++bi) {
                Box* bx = boxes + bi;
                oss[0][ri++] = Level(bx->h, bx->w * bx->d);
                oss[0][ri++] = Level(bx->d, bx->w * bx->h);
                oss[0][ri++] = Level(bx->w, bx->d * bx->h);
        }
        uint32_t eor = 1, block;
        for (uint32_t li(0); li < (LN - 1); ++li) {
                eor *= (LN - li);
                block = LN - (li + 1);
                for (uint32_t ri(0); ri < eor; ++ri) {
                        for (uint32_t bi(0),si(ri * block); si < (ri * block + block);) {
                                if (bi == len) {
                                        oss[li + 1][si] = oss[li][ri];
                                        ++si;
                                }
                                else {
                                        Box* bx = boxes + bi;
                                        if (oss[li][ri].area > bx->w * bx->d) oss[li + 1][si++] = Level(oss[li][ri].height + bx->h, bx->w * bx->d);
                                        if (oss[li][ri].area > bx->w * bx->h) oss[li + 1][si++] = Level(oss[li][ri].height + bx->d, bx->w * bx->h);
                                        if (oss[li][ri].area > bx->d * bx->h) oss[li + 1][si++] = Level(oss[li][ri].height + bx->w, bx->d * bx->h);
                                        ++bi;
                                }
                        }
                }
        }
        //max function
        return accumulate(oss[LN - 1] + 1, oss[LN - 1] + RW, Level(oss[LN - 1][0]), [](Level &i, Level &m) {return i.height > m.height ? i : m;}).height;
}
/*Parameter List:
 *
 *  |--Top-Down:  --->[Box* boxes = array of boxes, size_t len = length of array,Box* top = box on the top of stack, uint32_t area = are of the box on the top of stack]
 *- |
 *  |--Bottom-Up: --->[Box* boxes = array of boxes, size_t len = length of array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = heighest stack to can build from boxes]
 *- |
 *  |--Bottom-Up: --->[uint32_t = heighest stack to can build from boxes]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[box_stack(boxes,3,nullptr,0) boxes = boxes = new Box[3]{Box(34,12,53),Box(122,32,55),Box(23,12,7)}]
 *- |
 *  |--Bottom-Up: --->[box_stack(boxes,3) boxes = boxes = new Box[3]{Box(34,12,53),Box(122,32,55),Box(23,12,7)}]
 *
 */
