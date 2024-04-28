//172. Trailing zeroes
#include <iostream>
using namespace std;

//O(log5(n))

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        for(int  i = 5; i <= n ;i+=5){
            int num = 0;
            int tmp = i;
            while(tmp%10==0){
                num++;
                tmp/=10;
            }
            while(tmp%5==0){
                num++;
                tmp/=5;
            }
            ret+=num;
        }
        return ret;
    }
};
int main(){
    Solution s;
    std::cout << s.trailingZeroes(50);
    
}