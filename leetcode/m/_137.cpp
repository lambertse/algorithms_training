//137. Single Number II
#include <vector>
#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

#define SOL3
#define N 32
#define getBit(bit, i) ((bit >> i) & 1)

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    #ifdef SOL1
    int singleNumber(vector<int>& nums) {
        map<int,int> list;
        for(auto &i : nums)
            list[i]++;
        for(auto &i :list)
            if(i.second == 1)
                return i.first; 
        return 0;
    }
    #endif
    #ifdef SOL2 
    int singleNumber(vector<int>& nums) {
      long long ret = 0;
      for(int i = 0; i < N; i++){
        int sum = 0;
        for(auto num: nums) sum += getBit(num, i);
        ret += pow(2,i)*(sum%3);
      }
      return int(ret);
    }
    #endif
    #ifdef SOL3
    //this solution is reference on someone's. Not by my sefl, but I've understand it already =))
    //https://www.youtube.com/watch?v=5Bb2nqA40JY&ab_channel=takeUforward
    //how a genius person that come up with this solution @@!
    int singleNumber(vector<int>& nums) {
      int ones=0, twos=0;
      for (const int num : nums) {
        ones = ones^num & ~twos;
        twos = twos^num & ~ones;
      }
      return ones;
    }
    #endif
};
int main(){
    vector<int> test{6,4,4,4};
    Solution sol;
    std::cout << sol.singleNumber(test);
}