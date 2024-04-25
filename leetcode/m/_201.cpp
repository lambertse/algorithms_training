#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr int getBit(int bit, int i) {return ((bit>>i)&1);}

class Solution {
public:
    Solution(){    
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    inline int log2(int num) {return log(num)/log(2);}
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;
        if(left == right) return left;
        int ret = 0;
        int i = log2(right);
        while(i >= 0){
            if(getBit(left,i) == 1 && getBit(right,i) == 1)
                ret += pow(2, i);
            i--;
        }
        return ret;
    }
};

int main(){
    Solution s;
    std::cout << s.rangeBitwiseAnd(6,7);
}
