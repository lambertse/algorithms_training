//14. Longest common prefix
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int idx = 0;
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs.front();
        while(true){  
            for(int i = 0; i < strs.size() - 1; i++){
                if(idx == strs[i].length() || strs[i][idx] != strs[i+1][idx])
                    return ret;
            }
            ret+=strs[0][idx++];
        }
        return ret;
    }
};
