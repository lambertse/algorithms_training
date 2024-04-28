//74. Search a 2D Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRow = matrix.size();
        int numCol = matrix[0].size();
        int left = 0;
        int right = numRow*numCol - 1;
        while(left <= right){
            int mid = right + (left - right)/2;
            int row = mid/numCol;
            int col = mid%numCol;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};