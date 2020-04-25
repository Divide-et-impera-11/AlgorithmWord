using namespace std;
#include <iostream>
#include <string>
//--------------Longest Bitonic Subsequence--------------
enum State
{
        UP,DOWN
};
//Top-Down
uint32_t bitonic_seq(uint32_t* num,uint32_t *mem, size_t len, size_t pos, State STA) {
        uint32_t max_up(1), max_down(1);
        if (STA == UP) {
                for (uint32_t offset(pos + 1); offset < len; ++offset) {
                        if (num[offset] >= num[pos]) {
                                if (mem[offset] && mem[len + offset])
                                        max_up = 1 + max(mem[offset], mem[len + offset]);
                                else
                                        max_up = max(1 + bitonic_seq(num, mem, len, offset, UP), max_up);
                        }
                }
                mem[pos] = max_up;
        }
        for (uint32_t offset(pos + 1); offset < len; ++offset) {
                if (num[offset] <= num[pos]) {
                        if (mem[len + offset])
                                max_down = max(1 + mem[offset + len],max_down);
                        else
                                max_down = max(1 + bitonic_seq(num, mem, len, offset, DOWN), max_down);
                }
                mem[pos + len] = max_down;
        }
        return max(max_up, max_down);
}
//Bottom-Up
uint32_t bitonic_seq(uint32_t* num, size_t len) {
        uint32_t**oss = new uint32_t*[len];
        for (auto i = 0; i < len; ++i)
                *(oss + i) = new uint32_t[2];
        for (int32_t offset(len - 1); offset >= 0; --offset) {
                //Longest Up
                oss[offset][0] = 1;
                for (int32_t state = offset + 1; state < len; ++state) {
                        if (num[offset] <= num[state]) {
                                oss[offset][0] = max(oss[offset][0],1 + max(oss[state][0], oss[state][1]));
                        }
                }
                //Longest Down
                oss[offset][1] = 1;
                for (int32_t state = offset + 1; state < len; ++state) {
                        if (num[offset] >= num[state]) {
                                oss[offset][1] = max(oss[offset][1], 1 + oss[state][1]);
                        }
                }
        }
        return max(oss[0][0], oss[0][1]);
}

/*Parameter List:
 *
 *  |--Top-Down:  --->[uint32_t* num = array of numbers,uint32_t *mem = memorization array,size_t len = lenght of array,size_t pos = position of number,State STA = sequence state]
 *- |
 *  |--Bottom-Up: --->[uint32_t* num = array of numbers, size_t len = lenght of array]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = longest bitonic subsequence]
 *- |
 *  |--Bottom-Up: --->[uint32_t = longest bitonic subsequence]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[bitonic_seq(num,mem,4,0,State::UP) num = num = new uint32_t[4]{2,5,7,2} mem = mem = new uint32_t[4]]
 *- |
 *  |--Bottom-Up: --->[bitonic_seq(num,4) num = num = new uint32_t[4]{2,5,7,2}]
 *
 */
