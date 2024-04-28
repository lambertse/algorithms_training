//238. Product of Array Except Self
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    //O(2*n)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        int rightSide = 1;
        int size = nums.size();
        for(int i = 1; i < size; i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for(int i = size-1; i >= 0;i--){
            prefix[i]*=rightSide;
            rightSide = rightSide*nums[i];
        }
        return prefix;
    }
};