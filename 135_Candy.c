int max(int a, int b){return (a>b)?a:b;}

int candy(int* ratings, int ratingsSize){
    int candys[2][20001];
    int ans = 0;
    
    candys[0][0] = 1;
    for(int i=1;i<ratingsSize;i++){
        if(ratings[i-1] >= ratings[i]) candys[0][i] = 1;
        else if(ratings[i-1] < ratings[i]) candys[0][i] = candys[0][i-1]+1;
    }
    candys[1][ratingsSize-1] = 1;
    for(int i=ratingsSize-2;i>=0;i--){
        if(ratings[i+1] >= ratings[i]) candys[1][i] = 1;
        else if(ratings[i+1] < ratings[i]) candys[1][i] = candys[1][i+1]+1;
    }
    
    for(int i=0;i<ratingsSize;i++){
        ans += max(candys[0][i],candys[1][i]);
    }
    return ans;
}
