class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int fresh = 0;
        queue<pair<int, int>> q;


        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == 1){
                    fresh++;
                }
                if(grid[row][col] == 2){
                    q.push({row, col});
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty() && fresh > 0){
            int qlength = q.size();

            for(int i = 0; i < qlength; i++){
                auto cell = q.front();
                q.pop();

                for(const auto& curr : directions){
                    int row = cell.first + curr.first;
                    int col = cell.second + curr.second;

                    //Check if in bounds and orange
                    if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            res++;
        }
        if(fresh > 0){
            return -1;
        }
        return res;
    }
};
