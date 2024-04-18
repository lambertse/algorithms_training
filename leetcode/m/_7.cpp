//7. Reverse Integer
#include <iostream>
#include <cmath>
using namespace std;

#define max_int ((1ll<<31) - 1)
#define min_int (-(1ll<<31))
class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int reverse(int x) {
        int res = 0;
        while(x!=0){
            int r = x%10;
            if((max_int - r)/10 < res || (min_int + r)/10 > res)
                return 0;
            res = res*10+r;
            x/=10;
        }
        return res;
    }
};