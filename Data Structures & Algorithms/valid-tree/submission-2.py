class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if not n:
            return False
        
        graph = [[] for _ in range(n)]
        for n1, n2 in edges:
            graph[n1].append(n2)
            graph[n2].append(n1)
        
        visited = set()
        def dfs(curr, prev):
            if curr in visited:
                return False
            
            visited.add(curr)
            for n in graph[curr]:
                if n == prev:
                    continue
                if dfs(n, curr) == False:
                    return False
            return True
        
        return dfs(0, -1) and len(visited) == n