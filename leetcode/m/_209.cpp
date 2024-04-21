// 209. Minimum Size Subarray Sum
#include <vector>
#include <iostream>
using namespace std; 

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX;
        int left = 0, right = 0;
        int curSum = 0;
        while(right < nums.size()){
            curSum+=nums[right];
            while(curSum >= target && left <= right){
                ret = min(ret, right - left + 1);
                curSum -= nums[left];
                left++;
            }
            right++;
        }
        return ret == INT_MAX ? 0 : ret;
    }
};

int main(){
    Solution s;
    std::vector<int> v{1,4,4};
    std::cout << s.minSubArrayLen(4, v);
}