# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        queue = deque([(root, float("-infinity"))])
        ans = 0

        while queue:
            node, maxVal = queue.popleft()

            if node.val >= maxVal:
                ans += 1
            
            if node.left:
                queue.append((node.left, max(maxVal, node.val)))
            
            if node.right:
                queue.append((node.right, max(maxVal, node.val)))

        return ans