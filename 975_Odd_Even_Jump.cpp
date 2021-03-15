struct Position{
    int nextEven, nextOdd;
};

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int ans = 0;
        vector<pair<int,int>> arrWithIndex;
        vector<Position> nextPosition;
        bool enableTable[2][20001];
    
        for(int i=0 ;i<arr.size();i++){
            Position temp;
            temp.nextEven = temp.nextOdd = -1;
            arrWithIndex.push_back(make_pair(arr[i],i));
            nextPosition.push_back(temp);
            enableTable[0][i] = enableTable[1][i] = false;
        }
        //printf("Initial Success\n");
        sort(arrWithIndex.begin(),arrWithIndex.end());
        //printf("Sorting Success\n");
        
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arrWithIndex[i].first <= arrWithIndex[j].first){ //arr[i] <= arr[j]
                    if(arrWithIndex[i].second < arrWithIndex[j].second){ // i<j
                        nextPosition[arrWithIndex[i].second].nextOdd = arrWithIndex[j].second;
                        break;
                    }
                }
            }
            
            if((i+1)<arr.size() && arrWithIndex[i].first == arrWithIndex[i+1].first){
                nextPosition[arrWithIndex[i].second].nextEven = arrWithIndex[i+1].second;
            }else{
                for(int j=i-1;j>=0;j--){
                    if(arrWithIndex[i].first >= arrWithIndex[j].first){ //arr[i] >= arr[j]
                        if(arrWithIndex[i].second < arrWithIndex[j].second) {// i<j
                            nextPosition[arrWithIndex[i].second].nextEven = arrWithIndex[j].second;
                            while(j-1>=0 && arrWithIndex[j-1].first == arrWithIndex[j].first){
                                if(arrWithIndex[j-1].second > arrWithIndex[i].second){
                                    nextPosition[arrWithIndex[i].second].nextEven = arrWithIndex[j-1].second;
                                    j--;
                                } else break;
                            }
                            break;
                        }
                    }
                }
            }
        }
        
        //printf("Find Next Postion Success\n");
        enableTable[0][arr.size()-1] = enableTable[1][arr.size()-1] = true;
        for(int i=arr.size()-2;i>=0;i--){
            if(nextPosition[i].nextOdd != -1){
                enableTable[0][i] |= enableTable[1][nextPosition[i].nextOdd];
            }
            if(nextPosition[i].nextEven != -1){
                enableTable[1][i] |= enableTable[0][nextPosition[i].nextEven];
            }
        }
        
        for(int i=0;i<arr.size();i++){
            //printf("%d Next Position (%d, %d)\n",arr[i],nextPosition[i].nextOdd,nextPosition[i].nextEven);
            //printf("%d %d\n",enableTable[0][i],enableTable[1][i]);
            if(enableTable[0][i]) ans++;
        }
        return ans;
    }
};
