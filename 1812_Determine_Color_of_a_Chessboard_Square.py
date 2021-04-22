class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        ans = False
        evenWhite = ['a','c','e','g']
        if coordinates[0] in evenWhite:
            if ord(coordinates[1]) % 2 == 0:
                ans = True
            else:
                ans = False
        else:
            if ord(coordinates[1]) % 2 == 0:
                ans = False
            else:
                ans = True
        return ans
