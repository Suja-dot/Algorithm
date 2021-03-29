class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ans = True
        alpha = [0 for i in range(0,27)]
        for i in s:
            alpha[ord(i)-ord('a')] += 1
        for i in t:
            alpha[ord(i)-ord('a')] -= 1
            
        for i in range(0,27):
            if alpha[i] != 0:
                ans = False
                break
        return ans
        
