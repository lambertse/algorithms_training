//45. Jump game
#include <vector>
#include <iostream>
using namespace std;

#define GREEDY
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    #ifdef DP
    int jump(vector<int>& nums) {
        vector<int> DP(nums.size(),1);
        if(nums.size() == 1)
            return 0;
        int size = nums.size();
        for(int i = size - 2; i >= 0; i--){
            if(nums[i] >= (size-1-i))
                DP[i] = 1;
            else if(nums[i] == 0)
                DP[i] = 0;
            else{
                int minn = INT_MAX;
                for(int j = 1; j <= nums[i]; j++ ){
                    if(DP[i+j]!=0)
                        minn = min(minn, 1 + DP[i+j]);
                }
                DP[i] = minn == INT_MAX ? 0 : minn;
            }
        }
        return DP[0];
    }
    #endif
    #ifdef GREEDY
    int jump(vector<int>& nums) {
        int size = nums.size();  
        if(size == 1) return 0;
        int ans = 0;
        int idx = 0;
        int flag = 0;
 
        while(flag < size - 1){
            ans++;
            int nextFlag = -1;
            for(int i = idx; i <= flag; i++){
                nextFlag = max(nextFlag, i + nums[i]);
            }
            idx = flag + 1;
            flag = nextFlag;
        }
        return ans;
    }
    #endif
};


int main(){
    vector<int> v{2,4,1,2,3,1,1,2};
    Solution s;
    std::cout << s.jump(v);
}