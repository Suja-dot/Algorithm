# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMaxLevel(self, root: TreeNode) -> int:
        level = 0
        node = root
        while node.left != None:
            node = node.left
            level+=1
        return level
    
    def findLastNode(self, root: TreeNode, level: int) -> int:
        ans = 0
        bit = [0]*level
        for i in range(level):
            bit[i] = 1
            node = root
            for direct in bit:
                if direct == 0:
                    node = node.left
                else:
                    node = node.right
            if node==None:
                bit[i] = 0
        bit.reverse()
        for i in range(level):
            ans += (2**i)*bit[i]
        return ans
        
            
    def countNodes(self, root: TreeNode) -> int:
        if root == None:
            return 0
        level = self.findMaxLevel(root) # 2^level + a
        ans = 2**level-1
        print(ans)
        ans += self.findLastNode(root,level)
        return ans+1
        
        
        
