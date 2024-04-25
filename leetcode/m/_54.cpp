// /54. Spiral Matrix
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        std::vector<int> ret;
        int curPoint = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int d = min(col, row)/2;
        while (curPoint < d)
        {
            // left to right
            for (int i = curPoint; i <  col - curPoint - 1; i++)
                ret.push_back(matrix[curPoint][i]);
            // top to bot
            for (int i = curPoint; i < row - curPoint - 1; i++)
                ret.push_back(matrix[i][col - curPoint - 1]);
            // right to left
            for (int i = col - curPoint - 1; i >= curPoint + 1; i--)
                ret.push_back(matrix[row - curPoint - 1][i]);
            // bot to top
            for (int i = row - curPoint - 1; i >= curPoint + 1; i--)
                ret.push_back(matrix[i][curPoint]);
            curPoint++;
            
        }
        if(col%2!=0 || row%2!=0){
            if(curPoint == col - curPoint - 1 && col % 2 !=0){
                for(int i = curPoint; i <= row - curPoint - 1; i++)
                    ret.push_back(matrix[i][curPoint]);
            }else if(curPoint == row - curPoint -1 && row %2 !=0){
                for(int i = curPoint; i <= col - curPoint - 1; i++)
                    ret.push_back(matrix[curPoint][i]);
            }
        }
        return ret;
    }
};


int main(){
    std::vector<std::vector<int>> v{{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
    Solution s;
    std::vector<int> ret  = s.spiralOrder(v);
    for(auto& i: ret) std::cout << i << " ";
}