class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        queue = deque()
        visited = set()

        def assignDist(r, c):
            if r < 0 or r >= len(grid) or c < 0 or c >= len(grid[0]) or (r,c) in visited or grid[r][c] == -1:
                return
            
            grid[r][c] = dist + 1
            visited.add((r, c))
            queue.append((r, c))

        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 0:
                    queue.append((r, c))
                    visited.add((r, c))
        
        dist = 0
        while queue:
            size = len(queue)
            for _ in range(size):
                r, c = queue.popleft()

                assignDist(r + 1, c)
                assignDist(r - 1, c)
                assignDist(r, c + 1)
                assignDist(r, c - 1)
            dist += 1

