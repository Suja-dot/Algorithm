class Solution {
public:    
    void findPermu(int s, vector<int>& nums, vector<vector<int>>& ans){
        if(s==nums.size()){
            ans.push_back(nums);
            return ;
        }    
        for(int i=s;i<nums.size();i++){
            swap(nums[s],nums[i]);
            findPermu(s+1,nums,ans);
            swap(nums[s],nums[i]);
        }
        return ;
    }

    vector<vector<int>> removeDuplicate(vector<vector<int>>& ans){
        vector<vector<int>> removeDuplicate;
        
        removeDuplicate.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            bool flag = true;
            for(int j=0;j<ans[0].size();j++){
                if(removeDuplicate[removeDuplicate.size()-1][j] != ans[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag == false){
                removeDuplicate.push_back(ans[i]);
            }
        }
        return removeDuplicate;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0) return ans;
        findPermu(0,nums,ans);
        sort(ans.begin(),ans.end());
        ans = removeDuplicate(ans);
        return ans;
    }
};
