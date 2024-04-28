//274. H-Index
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int hIndex(vector<int>& citations) {
        std::unordered_map<int,int> _m;
        int maxx = -1;
        int size = citations.size();
        for(int i = 0; i < size; i++){
            _m[citations[i]]++;
            maxx = max(citations[i], maxx);
        }
        int cur = 0;
        for(int i = maxx; i >=0 ;i--){
            if(_m.find(i) != _m.end()){
                cur+=_m[i];
            }
            if(i<=cur)
                return i;
        }
        return 0;
    }
};
int main(){
    vector<int> v{3,0,6,1,5};
    Solution s;
    std::cout << s.hIndex(v);
}