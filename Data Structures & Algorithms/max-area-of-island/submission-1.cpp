class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int& curr){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0){
            return 0;
        }
        curr++;
        grid[row][col] = 0;
        dfs(grid, row + 1, col, curr);
        dfs(grid, row - 1, col, curr);
        dfs(grid, row, col + 1, curr);
        dfs(grid, row, col - 1, curr);

        return curr;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxx = 0;
        int curr = 0;

        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == 1){
                    curr = 0;
                    maxx = max(maxx, dfs(grid, row, col, curr));
                }
            }
        }
        return maxx;
    }
};
