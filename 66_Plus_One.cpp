class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int upper_data=0;
        digits[digits.size()-1]++;
        for(int i=digits.size()-1;i>=0;i--){
            int sum = digits[i]+upper_data;
            upper_data = sum/10;
            digits[i] = sum%10;
        }
        
        if(upper_data!=0) res.push_back(upper_data);
        for(int i=0;i<digits.size();i++) {
            res.push_back(digits[i]);
        }
        return res;
    }
};
