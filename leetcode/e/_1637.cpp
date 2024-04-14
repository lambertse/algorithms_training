//1637. Widest Vertical Area Between Two Points Containing No Points
#include <vector>
#include <algorithm>
using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    std::sort(points.begin(), points.end());
    int max = 0;
    for(int i = 0; i < points.size()-1; i++){
        if(points[i+1][0] - points[i][0] > max)
            max = points[i+1][0] - points[i][0];
    }
    return max;
}