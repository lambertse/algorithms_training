//56. Merge Intervals
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return {};
    std::sort(intervals.begin(), intervals.end());
    vector<vector<int>> res{intervals[0]};
    int idx = 1;
    while(idx < intervals.size()){
        if(res.back()[1] < intervals[idx][0])
            res.push_back(intervals[idx]);
        else
            res.back()[1] = max(intervals[idx][1], res.back()[1]); 
        idx++;
    }
    return res;
}

int main(){
    vector<vector<int>> test{{1,4},{2,3}};
    merge(test);
}