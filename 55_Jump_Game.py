class Solution:
    def canJump(self, nums: List[int]) -> bool:
        ans = False
        curIndex = 0
        lastIndex = curIndex+nums[0]
        while True:
            if curIndex == len(nums)-1:
                break
            lastIndex = max(lastIndex,curIndex+nums[curIndex])
            if curIndex >= lastIndex:
                break
            curIndex+=1
            
        if curIndex == len(nums)-1:
            ans = True
        return ans
