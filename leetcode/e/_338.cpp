//338. Counting Bits
#include <vector>
#include <iostream>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res;
    for(int i = 0; i <=n; i++)
        res.push_back(__builtin_popcount(i));
    return res;
}
int main(){
    std::cout << (1ll << 10);
}