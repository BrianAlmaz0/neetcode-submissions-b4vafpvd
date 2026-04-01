class Solution {
public:
    bool binarySearch(vector<int>& row, int target){
        int left = 0;
        int right = row.size() - 1;

        while(left <= right){
            int middle = (left + right) / 2;

            if(row[middle] == target){
                return true;
            } else if (row[middle] < target){
                left = middle + 1;
            } else{
                right = middle - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRows = matrix.size();
        int totalCols = matrix[0].size();
        int top = 0;
        int bottom = totalRows - 1;

        while(top <= bottom){
            int row = (top + bottom) / 2;

            if(target < matrix[row][0]){
                bottom = row - 1;
            } else if (target > matrix[row][totalCols - 1]){
                top = row + 1;
            } else{
                return binarySearch(matrix[row], target);
            }
        }
        return false;
    }
};
