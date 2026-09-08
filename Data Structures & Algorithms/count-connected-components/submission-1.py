class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for n1, n2 in edges:
            graph[n1].append(n2)
            graph[n2].append(n1)
        
        visited = set()
        def dfs(node):
            if node in visited:
                return
            
            visited.add(node)
            for n in graph[node]:
                dfs(n)
        
        res = 0
        for i in range(n):
            if i not in visited:
                res += 1
                dfs(i)
        
        return res