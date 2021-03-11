class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int first, second;
        first = 0;
        second = n;
        for(int i=0;i<n;i++){
            res.push_back(nums[first++]);
            res.push_back(nums[second++]);
        }
        return res;
    }
};
