//12. Integer to Roman
#include <map>
#include <string>
using namespace std;

map<int, char> sym{{1,'I'}, {5,'V'}, {10,'X'}, {50,'L'}, {100,'C'}, {500,'D'}, {1000,'M'}};

class Solution {
public:
    string intToRoman(int num) {
        string ret="";
        for(auto &pair : sym){
            int n = num/pair.first;
            int rest = num%pair.first;
            if(n==9*pair.first/10)
            
            for(int i = 0; i < n; i++)
                ret+=pair.second();
            
        }
    }
};