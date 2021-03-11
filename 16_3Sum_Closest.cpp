class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 1000000;
        int pivot, l, r;
        int prev_sum;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            pivot = i;
            l = i+1;
            r = nums.size()-1;
            while(l<r){
                int sum = nums[pivot]+nums[l]+nums[r];
                if(abs(sum-target)<abs(res-target)) res = sum;
                if(sum<target) l++;
                else r--;
            }
        }
        return res;
    }       
};
