int max(int a, int b){return (a>b)?a:b;}

int maxSubArray(int* nums, int numsSize){
    int ans=-100000;
    for(int i=1;i<numsSize;i++){
        nums[i] = max(nums[i],nums[i]+nums[i-1]);
    }
    for(int i=0;i<numsSize;i++){
        ans = max(ans,nums[i]);
    }
    return ans;
}
