class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        int flag;
        int needAlpha[26], totalNeedAlpha[26], curAlpha[26];
        memset(totalNeedAlpha,0,26*sizeof(int));
        for(int i=0;i<B.size();i++){
            memset(needAlpha,0,26*sizeof(int));
            for(int j=0;j<B[i].length();j++){
                needAlpha[B[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                totalNeedAlpha[j] = max(totalNeedAlpha[j],needAlpha[j]);
            }
        }
        
        for(int i=0;i<A.size();i++){
            memset(curAlpha,0,26*sizeof(int));
            flag = true;
            for(int j=0;j<A[i].length();j++){
                curAlpha[A[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                if(curAlpha[j]<totalNeedAlpha[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(A[i]);
        }
        return ans;
    }
};
