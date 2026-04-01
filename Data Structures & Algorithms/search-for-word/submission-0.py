class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        def dfs(row, col, wordIndex):
            #We reached the end of the word
            if wordIndex == len(word):
                return True

            #Out of bounds case
            if row < 0 or row > len(board) - 1 or col < 0 or col > len(board[0]) - 1 or word[wordIndex] != board[row][col]:
                return False

            #We found a valid letter
            #Change it to random char to make sure it's not counted twice
            letter = board[row][col]
            board[row][col] = "#" 

            #Perform dfs 
            res = dfs(row + 1, col, wordIndex + 1) or dfs(row - 1, col, wordIndex + 1) or dfs(row, col + 1, wordIndex + 1) or dfs(row, col - 1, wordIndex + 1)
            
            board[row][col] = letter
            return res
            


        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] == word[0] and dfs(row, col, 0):
                    return True
        
        return False 
                    