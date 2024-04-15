// 6. Zigzac conversion
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1) return s;
    std::vector<std::string> lines(numRows < s.length() ? numRows : s.length());
    int curLine = 0;
    /*Threre are 2 flow: going down ahead or go backward. Monitor by "isGoDown" variable*/
    bool isGoDown = false;
    for(int i = 0; i < s.length(); i++){
        if(curLine == 0 || curLine == numRows - 1){
            isGoDown = !isGoDown;
        }
        lines[curLine] += s[i];
        curLine += isGoDown ? 1 : -1; 
    }
    string res = "";
    for(auto &s : lines){
        res += s;
    }
    return res;
}

int main(){
    std::cout << convert("PAYPALISHIRING",3);
}