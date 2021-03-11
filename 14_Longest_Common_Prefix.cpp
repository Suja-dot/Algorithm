class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        bool flag;
        char prefix;
        long min_size = 2147483647;
        //find shortest word
        for(long i=0;i<strs.size();i++){
            if(min_size>strs[i].length()) min_size = strs[i].length();
        }
        if(min_size == 2147483647) min_size = 0;
        for(long i=0;i<min_size;i++){
            prefix = strs[0][i];
            flag = true;
            for(long j=1;j<strs.size();j++){
                if(prefix != strs[j][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans += prefix;
            else break;
        }
        return ans;
    }
};
