//118. Pascal's Triangle
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
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1},{1,1}};
        vector<vector<int>> ret{{1},{1,1}};
        for(int i = 2;i < numRows; i++){
            vector<int> line{1};
            for(int j = 1; j < i; j++){
                line.push_back(ret[i-1][j-1] + ret[i-1][j]);
            }
            line.push_back(1);
            ret.push_back(line);
        }
        return ret;
    }
};

int main(){
    Solution s;
    s.generate(5);
}