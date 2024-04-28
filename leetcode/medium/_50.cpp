// 50. Pow(x, n)
#include<iostream>

using namespace std;
#define RECUR
#define ll long long
class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    #ifdef BIN_SEARCH
    double cal(double x, long long cur){
        static double ret = 1;
        if(cur == 1)
            return x;
        ret = cal(x, cur/2);
        if(cur%2 == 0)
           ret *= ret;
        else 
            ret *= ret*x;
        return ret;
    }
    double myPow(double x, int n) {
        if( n == 0 || x == 1) return 1;
        if( n == 1 || x == 0 ) return x;
        if( n == -1) return 1/x;
        if( x == -1) return (n%2==0) ? 1: -1;
        
        ll lN = n;
        if(lN < 0) {x = 1/x; lN*=-1;}
        return cal(x, lN);
    }
    #endif
    #ifdef RECUR
    double myPow(double x, int n) {
        if( n == 0 ) return 1;
        if( n == 1 ) return x;
        if( n == -1) return 1/x;
        
        if(n%2==0) return myPow(x*x, n/2);
        return x*myPow(x, n-1);
    }
    #endif
};

int main(){
    Solution s;
    std::cout << static_cast<double>(s.myPow(2.1,3));
}