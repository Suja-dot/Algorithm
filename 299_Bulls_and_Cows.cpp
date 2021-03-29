class Solution {
public:
    string getHint(string secret, string guess) {
        string ans="";
        int secretNum[10];
        int aCount=0, bCount=0;
        memset(secretNum,0,10*sizeof(int));
        for(int i=0;i<secret.length();i++){
            secretNum[secret[i]-'0']++;
        }
        for(int i=0;i<secret.length();i++){
            if(secret[i] == guess[i]){
                aCount++;
                secretNum[secret[i]-'0']--;
            }
        }
        for(int i=0;i<secret.length();i++){
            if(secret[i] != guess[i]){
                if(secretNum[guess[i]-'0']>0){
                    bCount++;
                    secretNum[guess[i]-'0']--;
                }
            }
        }
        ans = to_string(aCount)+"A"+to_string(bCount)+"B";
        return ans;
    }
};
