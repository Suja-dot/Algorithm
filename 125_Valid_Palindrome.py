class Solution:
    def isPalindrome(self, s: str) -> bool:
        ans = True
        s = re.sub('[^0-9a-zA-Z]', '', s)
        s = s.lower()
        l = 0
        r = len(s)-1
        for i in range(math.ceil(len(s)/2)):
            if s[l+i] != s[r-i]:
                ans = False
                break
        return ans
