//2200. Find All K-Distant Indices in an Array
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keys;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key) keys.push_back(i);
        }
        for(int i = 0; i < nums.size(); i++){
            for(auto j : keys){
                if(abs(j-i) <= k){ret.push_back(i);break;}
            }
        }
        return ret;
    }
};

int main(){

}