/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

-Integers in each row are sorted in ascending from left to right.
-Integers in each column are sorted in ascending from top to bottom
*/
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows =matrix.size();
        int col = matrix[0].size();
        int i=0;
        int j=col-1;
        while(i<=rows-1 && j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;

        }
        return false;

    }
};
*/