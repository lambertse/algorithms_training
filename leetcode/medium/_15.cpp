//15. Three sum
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> res{};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n - 2; i++)
    {
        int need = -nums[i];
        
        int l = i + 1, r = n - 1;
        while(l < r)
        {
            if(nums[l] + nums[r] < need)
                l++;
            else if(nums[l] + nums[r] > need)
                r--;
            else
            {
                res.insert({nums[i], nums[l], nums[r]});
                l++;
                r--;
            }
        }
    }
    
    vector<vector<int>> ans;
    for(auto it : res)
        ans.push_back(it);

    return ans;

}
};