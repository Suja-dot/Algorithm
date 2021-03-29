class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        ans = True
        dictString = {}
        for i in range(0,len(s)):
            if s[i] in dictString:
                if(dictString[s[i]] != t[i]):
                    ans = False
                    break
            else:
                if t[i] in dictString.values():
                    ans = False;
                    break
                else:
                    dictString[s[i]] = t[i]
        return ans
