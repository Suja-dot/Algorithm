class Solution {
public:
   
    string licenseKeyFormatting(string S, int K) {
        string ans = "";
        int cnt = 0;
        stack<char> stack;
        S.erase(remove(S.begin(),S.end(),'-'),S.end());
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        
        for(int i=S.length()-1;i>=0;i--){
            stack.push(S[i]);
            cnt++;
            if(cnt>=K&&(cnt%K==0)&&i!=0){
                stack.push('-');
            }
        }
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        return ans;
    }
};
