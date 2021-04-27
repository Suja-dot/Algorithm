class Solution:
    def sumBase(self, n: int, k: int) -> int:
        ans = 0
        base = [[1,2,4,8,16,32,64],[1,3,9,27,81],[1,4,16,64],[1,5,25],[1,6,36],[1,7,49],[1,8,64],[1,9,81],[1,10,100]]
        for i in range(len(base[k-2])-1,-1,-1):
            mok = n//base[k-2][i]
            if mok > 0:
                ans += mok
                n -= (base[k-2][i]*mok)
        return ans
