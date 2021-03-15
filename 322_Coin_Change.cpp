class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dpTable[10001];
        memset(dpTable,-1,10000*sizeof(int));
        dpTable[0] = 0;
        for(int i=0;i<coins.size();i++) {
            if(coins[i]>10000) continue;
            dpTable[coins[i]] = 1;
        }
        
        for(int i=0;i<=amount;i++){
            if(dpTable[i]!=-1){
                for(int j=0;j<coins.size();j++){
                    if(coins[j]>10000 || i+coins[j]>10000) continue;
                    if(dpTable[i+coins[j]] == -1) dpTable[i+coins[j]] = dpTable[i]+1;
                    else dpTable[i+coins[j]] = min(dpTable[i+coins[j]],dpTable[i]+1);
                }
            }    
        }
        return dpTable[amount];
    }
};
