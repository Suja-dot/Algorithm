class Solution {
    public int trap(int[] height) {
    //using two pointer
        int left, right;
        int leftMaxValue, rightMaxValue;
        int ans = 0;
        if(height.length == 0) return 0;
        left = 0;
        right = height.length-1;
        leftMaxValue = height[left];
        rightMaxValue = height[right];
        while(left<right){
            if(leftMaxValue <= rightMaxValue){
                ans += (leftMaxValue-height[left]);
                left++;
                leftMaxValue = Math.max(leftMaxValue,height[left]);
            }else{
                ans += (rightMaxValue-height[right]);
                right--;
                rightMaxValue = Math.max(rightMaxValue,height[right]);
            }
        }
        return ans;
    }
}
