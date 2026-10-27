class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        int high = (row_size * col_size) - 1;
        int low = 0;
        int mid = (high + low) / 2;
        int row = 0;
        int col = 0;

        while(low <= high){
            row = mid / col_size;
            col = mid % col_size;
            if(target == matrix[row][col]) return true;
            else if(target < matrix[row][col]){
                high = mid - 1;
                mid = (high + low) / 2;
            }else if(target > matrix[row][col]){
                low = mid + 1;
                mid = (high + low) / 2;
            }
        }
        return false;
    }
};

/*
* What is known:
* Each row is sorted in ascending order
* First integer of every row is greater than the last integer of the previous row.
* Therefore lowest value = matrix[0,0] and highest value = matrix[matrix.size()-1,matrix[m].size()-1].
* Only have to return either true or false.
* Default is false.
* 
* Approach: Binary Search 2D Vector as a 1D vector
* Treat the matrix as a big one dimensional vector running from [0,(m*n)-1].
* Initalize two variables high and low being the first and last index of this hypothetical vector.
* Initialize another variable mid as (high + low) / 2.
* While (low <= high):
*   Convert mid from a position to row and column indices using row = mid/n and col = mid%n.
*   If target == matrix[row][col]: return true
*   Else if target < matrix[row][col]: high = mid - 1 (eliminating rows after position mid)
*   Else if target > matrix[row][col]: low = mid + 1 (eliminating rows before position mid)
* 
* 
*/