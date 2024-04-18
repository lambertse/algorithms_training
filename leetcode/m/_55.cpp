//55. Jump game
#include <vector>
#include <iostream>
using namespace std;

#define GREEDY

class Solution {
public:
    #ifdef DP
    bool jump(int idx, vector<int>& nums, vector<bool>& v){
        if(!v[idx])
            return false;
        if(idx >= nums.size()-1)
            return true;
        else if(nums[idx] == 0){
            v[idx] = false;
            return false;
        }
        for(int i = nums[idx]; i >= 1; i--)
            if(jump(idx + i, nums,v))
                return true;
        v[idx] = false;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<bool> v(nums.size() + 1, true);
        return jump(0, nums, v);
    }
    #endif
    #ifdef GREEDY
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i = 0; i < nums.size(); i++){
            if(reachable < i)
                return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
    #endif
};

int main(){
    vector<int> vec{1,2};
    Solution s;
    std::cout << s.canJump(vec);
}