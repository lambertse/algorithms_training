//3116. Kth Smallest Amount With Single Denomination Combination
#include <vector>
#include <numeric> 
#include <bitset>
#include <iostream>
using namespace std;
using ll = long long;

#define MASK(n) ((1 << n) - 1)          //Get mask of n bits
#define getBit(bit, i) ((bit >> i) & 1) //Get bit i of an bin num

ll cnt(vector<int>& coins, ll x){
    //using Inclusion–exclusion principle
    int coinSize = coins.size();
    int mask = MASK(coinSize);
    ll cnt = 0;
    for(int sample = 1; sample <= mask; sample++){
        ll lcm = 1;
        for(int i = 0; i < coinSize; i++){
            if(getBit(sample, i)){
                lcm = std::lcm(lcm, coins[i]);
            }
        }
        //plux x/lcm if it is lcm of the nums is odd
        if(__builtin_popcount(sample)&1){
            cnt+=x/lcm;
        }
        else {
            cnt-=x/lcm;
        }
         
    }
    return cnt;
}

long long findKthSmallest(vector<int>& coins, int k) {
    ll left = 0;
    ll right  = 51*1e10; // k < 2*1e9, max size of coins 25 => rigt = 2*1e9*25 + 25
    ll ans = 0;
    while(left <= right){
        ll mid = (left + right)/2;
        if( cnt(coins, mid) < k ){
            left = mid+1;
        }
        else{
            ans = mid;
            right = mid - 1;
        }
    }  
    return ans;
}

int main(){
    vector<int> v{10};
    std::cout << findKthSmallest(v,1118090188);
}