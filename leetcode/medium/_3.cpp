//3. Longest substring without repeating character
#include <iostream>
#include <string>
#include <vector>
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
        std::vector<int> map(256,-1);
        int fstItem = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(map[s[i]]!=-1 && map[s[i]] >= fstItem){
                ret = max(ret, i - fstItem);
                fstItem = map[s[i]] + 1;
            }
            map[s[i]] = i;
        }
        return  max(ret, len - 1 - fstItem);
    }
};

int main(){
    Solution s;
    std::cout << s.lengthOfLongestSubstring("aab");
}