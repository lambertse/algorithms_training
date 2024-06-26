//48. Rotate image
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    reverse(matrix.begin(), matrix.end());
       for(int i = 0; i < size; i++)
        for(int j = 0; j <= i; j++)
            swap(matrix[i][j], matrix[j][i]);
        
    }
};

int main(){
    vector<vector<int>> v{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(v);
}