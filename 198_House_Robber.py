class Solution:
    def rob(self, nums: List[int]) -> int:
        nrob = rob = 0
        for num in nums:
            nrob, rob = max(nrob,rob), num+nrob
        return max(nrob,rob)
