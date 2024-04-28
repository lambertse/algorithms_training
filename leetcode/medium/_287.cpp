//287. Find the duplicate number
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Constraints: O(1) space complexity and do not modify org vector

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        int rabit = nums[0], turtle = nums[0];
        int itc = 0;
        while(true){
            turtle = nums[turtle];
            rabit = nums[nums[rabit]];
            if(turtle == rabit){
                break;
            }
        }
        int slow = nums[0];
        while (turtle != slow)
        {
            turtle = nums[turtle];
            slow = nums[slow];
        }
        return slow;
    }
};

int main(){
    vector<int> v{1,5,5,6,2,8,4,7,5,5};
    Solution s;
    std::cout << s.findDuplicate(v);
}