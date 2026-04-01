# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stk = []
        curr = root
        n = 0

        while curr or stk:
            while curr:
                stk.append(curr)
                curr = curr.left
            
            curr = stk.pop()
            n += 1
            if n == k:
                return curr.val
            
            curr = curr.right
            