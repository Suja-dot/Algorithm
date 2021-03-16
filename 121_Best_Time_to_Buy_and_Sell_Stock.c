int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

int maxProfit(int* prices, int pricesSize){
    int ans = 0;
    int minValue = 100000;
    for(int i=0;i<pricesSize;i++){
        minValue = min(minValue,prices[i]);
        ans = max(ans,prices[i]-minValue);
    }
    return ans;
}
