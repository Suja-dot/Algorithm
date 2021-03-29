class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        cnt = 0
        start = 0
        pivot = -1
        end = len(nums)-1
        ans = [-1,-1]
        if len(nums) == 0:
            return ans
        middle = math.ceil((start+end)/2)
        while(start <= end):
            #print(start,end,middle)
            if nums[middle] == target:
                pivot = middle
                break
            else:
                if nums[middle] > target:
                    end = middle-1
                else:
                    start = middle+1
                middle = math.ceil((start+end)/2)
        #print(pivot)
        ans = [pivot,pivot]
        if pivot != -1:
            for i in range(pivot,-1,-1):
                if nums[i] == nums[pivot]:
                    ans[0] = i
                else:
                    break
            for i in range(pivot,len(nums),1):
                if nums[i] == nums[pivot]:
                    ans[1] = i
                else:
                    break
        return ans
