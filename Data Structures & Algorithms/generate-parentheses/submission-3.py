class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def dfs(curr, openCount, closedCount):
            #We finished
            if openCount == n and closedCount == n:
                res.append(curr)
                return
            
            #Check if we can add open
            if openCount < n:
                dfs(curr + "(", openCount + 1, closedCount)
            
            #Check if we can add closed
            if openCount > closedCount:
                dfs(curr + ")", openCount, closedCount + 1)
        
        dfs("", 0, 0)
        return res
            
