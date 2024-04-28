//12. Integer to Roman
#include <map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

static map<int, vector<string>> mapp{{100,{"CM","CD","D","C"}},{10, {"XC","XL","L","X"}}, {1,{"IX","IV","V","I"}}};
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    string intToRoman(int num) {
        string ret = "";
        int idx = num/1000;
        while(idx-->0)
            ret+="M";
        num = num%1000;
        for(int i = 100; i >=1 ; i/=10){
            idx = num/i;
            if(idx == 9) ret+=mapp[i][0];
            else if(idx == 4) ret+=mapp[i][1];
            else if(idx>=5){
                ret+=mapp[i][2];
                while(idx-5>0){
                    ret+=mapp[i][3];
                    idx--;
                }
            }
            else{
                while(idx>0){
                    ret+=mapp[i][3];
                    idx--;
                }
            }
            num%=i;
        }
        return ret;
    }
};

int main(){
    Solution s;
    std::cout << s.intToRoman(58);
}