class Solution {
private:
public:
    void findPermu(vector<int>& nums, int s, vector<vector<int>>& ans){
        if(s == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=s;i<nums.size();i++){
            swap(nums[i],nums[s]);
            findPermu(nums,s+1,ans);
            swap(nums[i],nums[s]);
        }
        return ;
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        findPermu(nums,0,ans);
        return ans;
    }
};
