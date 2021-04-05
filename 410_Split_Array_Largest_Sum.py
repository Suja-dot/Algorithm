class Solution:
    def canSplit(self, nums: List[int], m: int, target: int) -> bool:
        cnt = 1
        tSum = 0
        for num in nums:
            tSum += num
            if tSum > target:
                cnt += 1
                tSum = num
                if cnt > m:
                    return False
        return True
    
    def splitArray(self, nums: List[int], m: int) -> int:
        minSum = 0
        maxSum = 0
        for num in nums:
            minSum = max(minSum,num)
            maxSum += num
        l = minSum
        r = maxSum
        while(l<=r):
            mid = int(l + (r-l)/2)
            if self.canSplit(nums,m,mid) == True:
                r = mid-1
            else:
                l = mid+1
                
        return l
        
