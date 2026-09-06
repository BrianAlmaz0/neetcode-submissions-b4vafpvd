class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pacific, atlantic = set(), set()
        ROWS, COLS = len(heights), len(heights[0])

        def dfs(row, col, ocean):
            #Check if we're in bounds
            if row >= 0 and row < ROWS and col >= 0 and col < COLS and (row, col) not in ocean:
                ocean.add((row, col))
                
                #Recurse only to valid cells
                if row + 1 < ROWS and heights[row + 1][col] >= heights[row][col]:
                    dfs(row + 1, col, ocean)
                if row - 1 >= 0 and heights[row - 1][col] >= heights[row][col]:
                    dfs(row - 1, col, ocean)
                if col + 1 < COLS and heights[row][col + 1] >= heights[row][col]:
                    dfs(row, col + 1, ocean)
                if col - 1 >= 0 and heights[row][col - 1] >= heights[row][col]:
                    dfs(row, col - 1, ocean)


        for i in range(ROWS):
            for j in range(COLS):
                if i == 0 or j == 0:
                    dfs(i, j, pacific)
                if i == ROWS - 1 or j == COLS - 1:
                    dfs(i, j, atlantic)

        res = []
        for cell in pacific:
            if cell in atlantic:
                res.append(list(cell))
        
        return res