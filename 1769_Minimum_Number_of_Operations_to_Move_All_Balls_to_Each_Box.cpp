class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> place;
        vector<int> res;
        int sum;
        for(int i=0;i<boxes.length();i++){
            if(boxes[i] == '1') place.push_back(i);
        }
        for(int i=0;i<boxes.length();i++){
            sum = 0;
            for(int j=0;j<place.size();j++){
                sum += abs(place[j]-i);
            }
            res.push_back(sum);
        }
        return res;
    }
};
