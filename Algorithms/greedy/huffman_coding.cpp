using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numberic>
//---------------------Huffman Coding---------------------
class Leaf {
public:
        Leaf(Leaf*, Leaf*, char, uint32_t, bool);
        Leaf(const Leaf&);
        Leaf();
        ~Leaf();
        Leaf *left;
        Leaf *right;
        char chr;
        uint32_t rate;
        bool root;
};
Leaf::Leaf() = default;
Leaf::~Leaf() = default;
Leaf::Leaf(const Leaf& cpy) {
        this->chr = cpy.chr;
}
Leaf::Leaf(Leaf *left, Leaf *right, char chr, uint32_t rate, bool root) :
        left(left),
        right(right),
        chr(chr),
        rate(rate),
        root(root) {
}
//-----------------Tree-------------------
inline bool h_code(Leaf* lf_ptr, char c, vector<bool> &bit) {
        if (lf_ptr->chr == c)
                return true;
        if (lf_ptr->left) {
                bit.push_back(0);
                if (h_code(lf_ptr->left, c, bit))
                        return true;
        }
        if (lf_ptr->right) {
                bit.push_back(1);
                if (h_code(lf_ptr->right, c, bit))
                        return true;
        }
        bit.pop_back();
        return false;
}
inline Leaf* conn(set<Leaf*> &bin_tree,Leaf *f) {
        if (!f->root) {
                auto itr = find_if(bin_tree.begin(), bin_tree.end(), [&](Leaf* ptr) {return ptr->root && ptr->rate == f->rate;});
                if (itr != bin_tree.end()) {
                        (*itr)->chr = f->chr;
                        bin_tree.erase(bin_tree.find(f));
                        delete f;
                        f = *itr;
                        f->root = false;
                }
        }
        return f;
}
void HuffmanCoding(string msg) {
    set<Leaf*> bin_tree;
    Leaf *f1(nullptr), *f2(nullptr);
        for (string::iterator itr = msg.begin(); itr != msg.end(); ++itr) {
                if (find_if(bin_tree.begin(), bin_tree.end(), [&](Leaf* ptr) -> bool {return ptr->chr == *itr;}) == bin_tree.end()) {
                        bin_tree.insert(new Leaf(nullptr,nullptr,*itr, count(msg.begin(), msg.end(), *itr),false));
                }
        }
        while (bin_tree.size() > 1)
        {
                auto itr = bin_tree.end();
        f1 = *(--itr);
                f2 = *(--itr);
                if (conn(bin_tree, f1) != conn(bin_tree, f2)) {
                        bin_tree.insert(new Leaf(f1, f2, char(), f1->rate + f2->rate, true));
                        bin_tree.erase(bin_tree.find(f1));
                        bin_tree.erase(bin_tree.find(f2));
                }
                else {
                        bin_tree.insert(new Leaf(f1, nullptr, char(),0, true));
                        bin_tree.erase(bin_tree.find(f1));
                }
        }
        map<char,vector<bool>> chr_hc;
        pair<char, vector<bool>> p;
        for (string::iterator itr = msg.begin(); itr != msg.end(); ++itr) {
                if (chr_hc.find(*itr) == chr_hc.end()) {
                        p.first = *itr;
                        h_code(*bin_tree.begin(),p.first,p.second);
                        chr_hc.insert(p);
                        p.second.clear();
                }
        }
        //Huffman Code
        for (auto map_itr = chr_hc.begin(); map_itr != chr_hc.end(); ++map_itr) {
                cout << "Character:" << map_itr->first << " " << "Huffman Code:";
                for (auto hf_itr = map_itr->second.begin(); hf_itr != map_itr->second.end(); hf_itr++)
                        cout << *hf_itr;
                cout << endl;
        }
}
// Parameter List:
// string msg = message

// Return Value Cases:
// void

// Function Call Example
// HuffmanCoding("HI From Hungary!");
