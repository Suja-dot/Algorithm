class Solution {
    public int searchInsert(int[] nums, int target) {
        int res = -1;
        int i;
        for(i=0; i<nums.length; i++){
            if(nums[i] == target){
                res = i;
                break;
            }
            else if(nums[i]>target){
                res = i;
                break;
            }
        }
        if(res == -1) res = i;
        return res;
    }
}
