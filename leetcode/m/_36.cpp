//36. Valid Sudoku
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> check;
        //check row
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.')
                    continue;
                else if(check[board[row][col]])
                    return false;
                check[board[row][col]] = 1;
            }
            check.clear();
        }
        //check col
        for(int col = 0; col < 9; col++){
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.')
                    continue;
                else if(check[board[row][col]])
                    return false;
                check[board[row][col]] = 1;
            }
            check.clear();
        }
        //check 3x3
        for(int i = 0 ; i <= 6; i+=3){
            for(int j = 0; j <=6; j+=3){
                for(int k = i; k < i + 3; k++){
                    for(int l = j; l < j + 3; l++){
                        if(board[k][l] == '.')
                            continue;
                        else if(check[board[k][l]])
                            return false;
                        check[board[k][l]] = 1;
                    }
                }
                check.clear();
            }
        }

        return true;
    }
};