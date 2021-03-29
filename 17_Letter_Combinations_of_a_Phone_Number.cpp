class Solution {
public:
    map<char,vector<string>> match;
    
    void Init(char num, char start){
        vector<string> temp;
        int loopcnt;
        if(num=='1'||num=='0') loopcnt = 0;
        else if(num=='7'||num=='9') loopcnt=4;
        else loopcnt = 3;
        for(int i=0;i<loopcnt;i++){
            string tmp = "";
            tmp = start;
            temp.push_back(tmp);
            start++;
        }
        match.insert(make_pair(num,temp));
    }
    
    vector<string> letterCombinations(string digits) {
        vector<char> digit;
        vector<string> ans;
        
        Init('0','0');
        Init('1','0');
        Init('2','a');
        Init('3','d');
        Init('4','g');
        Init('5','j');
        Init('6','m');
        Init('7','p');
        Init('8','t');
        Init('9','w');

        for(int i=0;i<digits.length();i++){
            digit.push_back(digits[i]);
        }
        
        for(int i=0;i<digit.size();i++){
            if(ans.size()==0){
                ans = match[digit[i]];
            }else{
                vector<string> next;
                for(int j=0;j<ans.size();j++){
                    for(int k=0;k<match[digit[i]].size();k++){
                        next.push_back(ans[j]+match[digit[i]][k]);
                    }
                }
                ans = next;
            }
        }
        return ans;
    }
};
