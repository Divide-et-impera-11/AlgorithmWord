using namespace std;
#include <iostream>
#include <string>
#include <vector>
//---------------------Coin Exchange---------------------
class Coin {
public:
        uint32_t count;
        uint32_t value;
        Coin(uint32_t value) : value(value), count(0) {
                ;
        }
        ~Coin() {
                ;
        }

};
void money_exchange(uint32_t exchange) {
        vector<Coin> coins = {Coin(200),Coin(100),Coin(50),Coin(10),Coin(5),Coin(1)};
        while (exchange)
        {
                for (vector<Coin>::iterator iter = coins.begin(); iter != coins.end();++iter) {
                        if (iter->value <= exchange) {
                                exchange -= iter->value;
                                iter->count++;
                                break;
                        }
                }
        }
        for (int i = 0; i < coins.size(); i++) {
                cout << coins[i].value << " " << coins[i].count << endl;
        }
}
// Parameter List:
// uint32_t exchange = money exchange

// Return Value Cases:
// void

// Function Call Example
// money_exchange(525);
