class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        ans = 0
        eachStone = [0 for i in range(130)]
        for i in range(len(stones)):
            eachStone[ord(stones[i])] +=1
        
        for i in range(len(jewels)):
            ans += eachStone[ord(jewels[i])]
        return ans
