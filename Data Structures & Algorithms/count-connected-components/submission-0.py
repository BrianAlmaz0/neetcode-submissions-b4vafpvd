class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for n1, n2 in edges:
            graph[n2].append(n1)
            graph[n1].append(n2)

        def dfs(node):
            if node in visited:
                return
            
            visited.add(node)
            for n in graph[node]:
                dfs(n)

        count = 0
        visited = set()
        for i in range(n):
            if i not in visited:
                count += 1
                dfs(i)
        
        return count