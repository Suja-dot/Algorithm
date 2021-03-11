class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        vector<int> numK;
        int posK, posA, sum, upper;
        while(K>0){
            numK.push_back(K%10);
            K/=10;
        }
        posK = upper = 0;
        posA = A.size()-1;
        for(int i=0;i<min(A.size(),numK.size());i++){
            sum = A[posA--]+numK[posK++]+upper;
            upper = sum/10;
            sum %= 10;
            ans.push_back(sum);
        }
        if(A.size() > numK.size()){
            while(posA >= 0){
                sum = upper + A[posA--];
                upper = sum/10;
                sum %= 10;
                ans.push_back(sum);
            }
        }else if(A.size() < numK.size()){
            while(posK < numK.size()){
                sum = upper + numK[posK++];
                upper = sum/10;
                sum %= 10;
                ans.push_back(sum);
            }
        }
        while(upper > 0){
            ans.push_back(upper%10);
            upper/=10;
        }
        
        for(int i=0;i<ans.size()/2;i++){
            int temp = ans[i];
            ans[i] = ans[ans.size()-1-i];
            ans[ans.size()-1-i] = temp;
        }
        return ans;
    }
};
