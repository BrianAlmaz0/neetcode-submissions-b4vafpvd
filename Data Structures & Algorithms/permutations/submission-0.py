class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(curr, used):
            if len(curr) == len(nums):
                res.append(curr.copy())
                return
            
            for i, num in enumerate(nums):
                if i not in used:
                    curr.append(num)
                    used.add(i)
                    dfs(curr, used)
                    curr.pop()
                    used.remove(i)
        
        dfs([], set())
        return res