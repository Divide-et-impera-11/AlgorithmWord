using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//---------------------Bit Packing---------------------
class Object {
public:
        uint32_t weight;
        uint32_t biggle;
        Object(uint32_t weight, uint32_t biggle) :weight(weight), biggle(biggle) {
                ;
        }
        ~Object() {
                ;
        }
};
vector<Object> bit_packing(vector<Object>& objects,uint32_t package_weight) {
        vector<Object> package;
        uint32_t free_space(package_weight);
        package.reserve(objects.size());
        sort(objects.begin(), objects.end(), [](Object &arg1, Object &arg2) -> bool {return arg1.biggle > arg2.biggle;});
        for (vector<Object>::const_iterator c_iter = objects.cbegin(); c_iter != objects.cend(); ++c_iter) {
                if (c_iter->weight <= free_space) {
                        package.push_back(*c_iter);
                        free_space -= c_iter->weight;
                }
        }
        return package;
}
// Parameter List:
// vector<Object>& objects = content of the bag
// uint32_t package_weight = weight of the bag

// Return Value Cases:
// vector<Object> = objects of the bag what will be inside of the bag

// Function Call Example
// bit_packing(vector<Object>(3) = {Object(23,2),Object(2,5),Object(34,55)},100);
