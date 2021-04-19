class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        firinc = lastinc = 0
        rob = nrob = 0
        for i in range(len(nums)-1):
            nrob, rob = max(nrob,rob), nrob+nums[i]
        firinc = max(nrob, rob)
        nrob = rob = 0
        for i in range(1,len(nums)):
            nrob, rob = max(nrob,rob), nrob+nums[i]
        lastinc = max(nrob, rob)
        return max(firinc, lastinc)
        
