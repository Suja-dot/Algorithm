class Solution {
public:
    int totalFruit(vector<int>& tree) {
        queue<int> basket;
        int maxAmount[40001];
        int type[2];
        int amount[2];
        int ans = 0;
        
        //init
        type[0] = type[1] = -1;
        amount[0] = amount[1] = 0;
        for(int i=0;i<=40000;i++) maxAmount[i] = 0;
        
        for(int i=0;i<tree.size();i++){
            if(tree[i] == type[0]){
                basket.push(i);
                amount[0]++;
            }else if(tree[i] == type[1]){
                basket.push(i);
                amount[1]++;
            }else{
                if(type[0] == -1){ // all empty
                    basket.push(i);
                    type[0] = tree[i];
                    amount[0]++;
                }else if(type[1] == -1){ // another basket empty
                    basket.push(i);
                    type[1] = tree[i];
                    amount[1]++;
                }else{
                    while(amount[0]!=0 && amount[1]!=0){ // pop 
                        int index = basket.front();
                        maxAmount[index] = basket.size();
                        if(ans < maxAmount[index]) ans = maxAmount[index];
                        if(type[0] == tree[index]){
                            amount[0]--;
                            if(amount[0] == 0) type[0] = tree[i];
                        }else if(type[1] == tree[index]){
                            amount[1]--;
                            if(amount[1] == 0) type[1] = tree[i];
                        }
                        basket.pop();
                    }
                    if(tree[i] == type[0]){ // can collect
                        basket.push(i);
                        amount[0]++;
                    }else if(tree[i] == type[1]){ // can collect
                        basket.push(i);
                        amount[1]++;
                    }
                }
            }
        }
        //Remain queue pop
        while(basket.size()!=0){
            int index = basket.front();
            maxAmount[index] = basket.size();
            if(ans < maxAmount[index]) ans = maxAmount[index];
            basket.pop();
        }
        return ans;
    }
};
