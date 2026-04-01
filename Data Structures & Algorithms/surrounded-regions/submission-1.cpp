class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        //Check if out of bounds
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O'){
            return;
        }

        board[row][col] = '#';

        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);

    }
    void solve(vector<vector<char>>& board) {
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                if((row == 0 || row == board.size() - 1 || col == 0 || col == board[0].size() - 1) && board[row][col] == 'O'){
                    dfs(board, row, col);
                }
            }
        }

        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                if(board[row][col] == 'O'){
                    board[row][col] = 'X';
                } else if(board[row][col] == '#'){
                    board[row][col] = 'O';
                }
            }
        }
    }
};
