class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        ans = 1
        m = len(matrix)
        n = len(matrix[0])
        ansMatrix = [[-1 for col in range(n)] for row in range(m)]
        
        def dfs(i,j):
            if ansMatrix[i][j] != -1:
                return ansMatrix[i][j]
            ansMatrix[i][j] = 1
            for di,dj in [(0,1),(0,-1),(1,0),(-1,0)]:
                ni, nj = i+di, j+dj
                if 0<=ni<m and 0<=nj<n and matrix[i][j]<matrix[ni][nj]:
                    ansMatrix[i][j] = max(ansMatrix[i][j],1+dfs(ni,nj))
            return ansMatrix[i][j]
        
        
        for i in range(m):
            for j in range(n):
                ans = max(ans,dfs(i,j))
        return ans
