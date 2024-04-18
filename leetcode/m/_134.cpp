//134. Gas station
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Solution(){
    //     std::ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);
    // }
    #ifdef BRUTEFORCE
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            int firstIdx = i;
            int curGas = 0;
            bool isBreak = false;
            for(int j = firstIdx; j < gas.size(); j++){
                curGas+=gas[j];
                if(curGas - cost[j] < 0){
                    isBreak = true;
                    break;
                }
                curGas -= cost[j];
            }
            if(isBreak)
                continue;
            for(int j = 0; j < firstIdx; j++){
                curGas+=gas[j];
                if(curGas - cost[j] < 0){
                    isBreak = true;
                    break;
                }
                curGas -= cost[j];
            }
            if(!isBreak)
                return i;
        }
        return -1;
    }
    #endif
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        int size = 0;
        int gasSize = gas.size();
        for(int i = 0; i < 2*gasSize; i++){
            cur+=gas[i % gasSize];
            if(cur < cost[i % gasSize]){
                cur = 0;
                size = 0;
                continue;
            }
            if(++size == gasSize)
                return i-size+1;
            cur-=cost[i % gasSize];
        }
        return -1;
    }
};

int main(){
    vector<int> v{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
    Solution s;
    std::cout << s.canCompleteCircuit(v, cost);
}