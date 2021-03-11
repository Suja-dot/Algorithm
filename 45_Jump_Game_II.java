class Solution {
    public int jump(int[] nums) {
        int[] ans = new int[nums.length];
        ans[0] = 0;
        for(int i=1;i<nums.length;i++) ans[i] = -1;
        for(int i=0;i<nums.length;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j >= nums.length) break;
                if(ans[i+j] == -1) ans[i+j] = ans[i]+1;
                else ans[i+j] = Math.min(ans[i+j],ans[i]+1);
            }
        }
        return ans[nums.length-1];
    }
}
