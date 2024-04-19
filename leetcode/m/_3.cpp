//3. Longest substring without repeating character
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    Solution(){
        std::ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        std::string curMax = "";
        int len = s.length();
        for(int i = 0; i < len; i++){
            auto it = curMax.find(s[i]);
            if(it == std::string::npos){
                curMax+=s[i];
            }
            else{
                int curlen = curMax.length();
                if( curlen > ret ) ret = curlen;
                curMax = curMax.substr(it+1);
                curMax+=s[i];
            }
        }
        return std::max(int(curMax.length()), ret);
    }
};

int main(){
    Solution s;
    std::cout << s.lengthOfLongestSubstring("aabaab!bb");
}