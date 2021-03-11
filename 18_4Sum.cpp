class Solution {
private:
    vector<vector<int>> ans; 
public:
    bool checkRepit(vector<int> addValue){
        for(int i=0;i<ans.size();i++){
            if(ans[i][0] == addValue[0] && ans[i][1] == addValue[1] && ans[i][2] == addValue[2] && ans[i][3] == addValue[3]){
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int advTarget,l,r;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                advTarget = nums[i]+nums[j];
                l = j+1;
                r = nums.size()-1;
                while(l<r){
                    if(advTarget + nums[l] + nums[r] == target){
                        vector<int> ansCase;
                        ansCase.push_back(nums[i]);
                        ansCase.push_back(nums[j]);
                        ansCase.push_back(nums[l]);
                        ansCase.push_back(nums[r]);
                        if(checkRepit(ansCase) == false) this->ans.push_back(ansCase);
                        while((l+1)<r && nums[l]==nums[l+1]) l++;
                        while(l<(r-1) && nums[r]==nums[r-1]) r--;
                        l++; r--;
                    }
                    while(l<r && advTarget + nums[l] + nums[r] < target) l++;
                    while(l<r && advTarget + nums[l] + nums[r] > target) r--;
                }
            }
        }
        return this->ans;
    }
};
