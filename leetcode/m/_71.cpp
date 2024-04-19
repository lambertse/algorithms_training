//71. Simplify Path
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int len = path.length();
        string p = "";
        
        int idx = 0;
        while(idx < len){
            if(path[idx] == '/'){
                if(p!="") st.push("/" + p);
                p="";
                while(idx < len && path[idx] == '/'){idx++;}
            }
            while(idx < len && path[idx] != '/'){
                p+=path[idx];
                idx++;
            }
            if( p == "." ){
                p="";
            }
            else if(p == ".."){
                p="";
                if(!st.empty())st.pop();
            }
        }
        if(p!="") st.push("/"+p);
        string res="";
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res.empty() ? "/" : res;
    }
};


int main(){
    Solution s;
    std::cout << s.simplifyPath("/...");
}