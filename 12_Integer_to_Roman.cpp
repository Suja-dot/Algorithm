class Solution {
public:
    string intToRoman(int num) {
        string arr[4][10]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM","MMMM","","","",""}
        };
        string res = "";
        int cnt=0;
        while(num>0){
            res = arr[cnt][num%10]+res;
            cnt++;
            num/=10;
        }
        return res;
    }
};
