class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int totalRows = board.size();
        int totalCols = board[0].size();

        //Check each of the rows
        for(int row = 0; row < totalRows; row++){
            set<char> seen;
            for(int col = 0; col < totalCols; col++){
                if(board[row][col] != '.'){
                    if(seen.find(board[row][col]) != seen.end()){
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }

        //Check each of the cols
        for(int col = 0; col < totalCols; col++){
            set<char> seen;
            for(int row = 0; row < totalRows; row++){
                if(board[row][col] != '.'){
                    if(seen.find(board[row][col]) != seen.end()){
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }

        //Check each of the 9 squares
        for(int square = 0; square < 9; square++){
            set<char> seen;
            for(int row = 0; row < 3; row++){
                for(int col = 0; col < 3; col++){
                    //Find the actual coordinates of the nums we have
                    int newRow = (square / 3) * 3 + row;
                    int newCol = (square % 3) * 3 + col;

                    if(board[newRow][newCol] != '.'){
                        if(seen.find(board[newRow][newCol]) != seen.end()){
                            return false;
                        }
                        seen.insert(board[newRow][newCol]);
                    }
                }
            }
        }
        return true;
    }
};
