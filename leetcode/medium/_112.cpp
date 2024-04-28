//122. Best Time to Buy and Sell Stock II
#include <vector>
using namespace std;

//Find next nearest trough or next nearest peak, control by isPeak var
int findNext(vector<int> v, int idx, bool isPeak = false){
    idx++;
    if(idx >= v.size())
        return idx;
    while(idx < v.size()){
        if(!isPeak && v[idx] > v[idx-1])
            break;
        if(isPeak && v[idx] < v[idx-1])
        break;
        idx++;
    }
    return idx-1;
}

int maxProfit(vector<int>& prices) {
    if(prices.size()==1) return 0;
    int maxProfit = 0,trough = 0,nearPeak = 0;
    do{
        trough = findNext(prices, nearPeak);
        nearPeak = findNext(prices, trough, true);
        if(nearPeak >= prices.size())
            break;
        maxProfit += (prices[nearPeak] - prices[trough]);
    }while(trough < prices.size());
    return maxProfit;
}

int main(){
    std::vector<int> v{7,6,4,3,1};
    return maxProfit(v);
}