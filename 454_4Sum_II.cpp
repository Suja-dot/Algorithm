class Solution {
private:
    
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        //Create A+B sum lists
        map<int,int> sumExist;
        int ans=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(sumExist.find(A[i]+B[j])==sumExist.end()){
                    sumExist.insert({A[i]+B[j],1});
                }else{
                    sumExist[A[i]+B[j]]++;
                }
            }
        }
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                if(sumExist[-(C[i]+D[j])]!=0) ans+=sumExist[-(C[i]+D[j])];
            }
        }
        return ans;
    }
};
