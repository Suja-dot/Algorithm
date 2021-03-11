class Solution {
public:
    string convert(string s, int numRows) {
        string res="";
        int flag = 0,cnt=0; //0 = descending, 1 = ascending
        vector<char> arr[1001];
        //[Step1] Split String
        if(numRows==1) return s;
        for(int i=0;s[i]!='\0';i++){
            if(flag == 0){
                arr[cnt++].push_back(s[i]);
                if(cnt == numRows){
                    flag = 1;
                    cnt = numRows-2;
                }
            }else{
                arr[cnt--].push_back(s[i]);
                if(cnt<0){
                    flag = 0;
                    cnt = 1;
                }
            }
        }
        //[Step2] Merge String
        for(int i=0;i<numRows;i++){
            for(int j=0;j<arr[i].size();j++){
                res += arr[i][j];
            }
        }
        return res;
    }
};
