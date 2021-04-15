# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def validBST(node,left, right):
            if not node:
                return True
            if not(node.val < right and node.val > left):
                return False
            return(validBST(node.left,left,node.val) and validBST(node.right,node.val,right))
        return validBST(root,float("-inf"),float("inf"))
