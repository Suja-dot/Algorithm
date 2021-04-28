class Solution:
    def makeLargestSpecial(self, S: str) -> str:
        special = []
        cnt = 0
        i = 0
        for j, c in enumerate(S):
            if c == '1':
                cnt+=1
            else:
                cnt-=1
            if cnt == 0:
                special.append('1'+self.makeLargestSpecial(S[i+1:j])+'0')
                i = j+1
        return ''.join(sorted(special)[::-1])
