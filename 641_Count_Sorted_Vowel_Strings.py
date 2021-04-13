class Solution:
    def sumNum(self,index:int,offset:int,table:List[List[int]]) -> int:
        res = 0
        for i in range(offset,5):
            res += table[i][index]
        return res
    
    def countVowelStrings(self, n: int) -> int:
        dp = [[0 for i in range(n+1)] for j in range(5)]
        
        dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = 1
        for i in range(2,n+1):
            for j in range(5):
                dp[j][i] = self.sumNum(i-1,j,dp)
        
        return self.sumNum(n,0,dp)
        
