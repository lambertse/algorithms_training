// 162. Find peak element
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    Solution() {
    std:
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            int m = nums[mid];
            int l = mid == 0 ? INT_MIN : nums[mid-1];
            int r = mid == nums.size()-1 ? INT_MIN : nums[mid+1];
            if (r > m)
                left = mid + 1;
            else if (l > m)
                right = mid - 1;
            else
                return mid;
        }
        return left;
    }
};

int main(){
    Solution s;
    std::vector<int> v{};
    std::cout << s.findPeakElement(v);
}