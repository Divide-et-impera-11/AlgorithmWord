using namespace std;
#include <iostream>
#include <string>
#define SIZ 3
//-----------Shortest Superstring-----------
//Top-Down
uint32_t shrt_sups(string arr[SIZ],size_t pos,string sups = "") {
        uint32_t plus = arr[pos].length(),minl;
        if (sups.find(arr[pos]) < sups.length())
                plus = 0;
        else {
                uint32_t add = arr[pos].length();
                while (--add){
                        if (add <= sups.length() && arr[pos].substr(0U, add) == sups.substr(sups.length() - add, add)) {
                                plus = arr[pos].length() - add;
                                break;
                        }
                }
        }
        for (auto itr = (arr[pos].end() - plus); itr != arr[pos].end(); itr++)
                sups += *itr;
        minl = pos == SIZ - 1 ? sups.length() : UINT32_MAX;
        for (uint32_t offset(pos + 1); offset < SIZ; ++offset) {
                minl = min(shrt_sups(arr, pos + 1, sups), minl);
                if(pos < SIZ - 2)
                        swap(arr[pos + 1], arr[pos + 2]);
        }
        return minl;
}
//Bottom-Up
inline string ssp_fit(string ssp,string word) {
        uint32_t plus = word.length();
        if (ssp.find(word) < ssp.length())
                plus = 0;
        else {
                uint32_t add = word.length();
                while (--add) {
                        if (add <= ssp.length() && word.substr(0U, add) == ssp.substr(ssp.length() - add, add)) {
                                plus = word.length() - add;
                                break;
                        }
                }
        }
        for (auto itr = (word.end() - plus); itr != word.end(); itr++) {
                ssp += *itr;
        }
        return ssp;
}
uint32_t shrt_ssp(string *words, size_t len) {
        const uint32_t R(len * (len - 1)),C(len);
        uint32_t swapper(0);
        string *oss = new string[R * C];
        for (uint32_t idx0(0); idx0 < R; ++idx0) {
                oss[C * idx0] = words[0];
                for (uint32_t idx1(1); idx1 < C; ++idx1) {
                        //build ssp
                        oss[idx0 * C + idx1] = ssp_fit(oss[idx0 * C + idx1 - 1], words[idx1]);
                }
                swap(words[swapper], words[swapper + 1]);
                if (++swapper == len - 1)
                        swapper = 0;
        }
        //optimal substrucure property
        uint32_t glb_opt = oss[C - 1].length();
        for (uint32_t offset(1); offset < R; ++offset) {
                if (oss[C * offset + C - 1].length() < glb_opt)
                        glb_opt = oss[C * offset + C - 1].length();
        }
        return glb_opt;
}



/*Parameter List:
 *
 *  |--Top-Down:  --->[string arr[SIZ] = words of superstring,size_t pos = index of next word into superstring,string sups = superstring]
 *- |
 *  |--Bottom-Up: --->[string *words = words of superstring,size_t len = number of words]
 *
 Return Cases:
 *
 *  |--Top-Down:  --->[uint32_t = long of shortest superstring]
 *- |
 *  |--Bottom-Up: --->[uint32_t = long of shortest superstring]
 *
 * Function Call:
 *
 *  |--Top-Down:  --->[shrt_sups(arr,0) arr = arr[SIZ]{"apple","apex","nintendo"}]
 *- |
 *  |--Bottom-Up: --->[shrt_ssp(words,SIZ) words = words = new string[SIZ]{"apple","apex","nintendo"}]
 *
 */
