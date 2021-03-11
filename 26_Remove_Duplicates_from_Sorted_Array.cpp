class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int prev_num;
        if(nums.size()==0) return 0;
        else prev_num = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev_num){
                nums.erase(nums.begin()+i);
                i--;
            }else{
                prev_num = nums[i];
            }
        }
        
        
        ans = nums.size();
        return ans;
    }
};
