class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> boxes(9);

        for(int i=0; i<9;i++){
            unordered_set<char> seen_row;
            unordered_set<char> seen_col;
            int rb=0;
            int cb=0;
            int box=0;
            for(int j=0; j<9;j++){
                if(seen_row.find(board[i][j])==seen_row.end() && board[i][j] != '.'){
                    seen_row.insert(board[i][j]);
                }else if(seen_row.find(board[i][j]) != seen_row.end() && board[i][j] != '.'){
                    return false;
                }

                if(seen_col.find(board[j][i])==seen_col.end() && board[j][i] != '.'){
                    seen_col.insert(board[j][i]);
                }else if(seen_col.find(board[j][i]) != seen_col.end() && board[j][i] != '.'){
                    return false;
                }

                rb = i/3;
                cb = j/3;
                box = (rb*3) + cb;

                if(boxes[box].find(board[i][j]) == boxes[box].end() && board[i][j] != '.'){
                    boxes[box].insert(board[i][j]);
                }else if(boxes[box].find(board[i][j]) != boxes[box].end() && board[i][j] != '.'){
                    return false;
                }

            }
        }
    return true;    
    }
};

/*
* What is known:
* There are 9 rows and 9 columns in the vector of vectors containing chars.
* Each row must contain unique values 1-9 or '.' char.
* Each column must contain unique values 1-9 or '.' char.
* Each of the 3x3 sub-boxes must contain unique values 1-9 or '.' char.
* An unordered_set stores elements that haven't been seen before and flag elements that are in the set.
* Each inner vector is a row on the board.
* Each ith column is comprised of board[i][0-9].
* Each 3x3 sub-box is vector of vectors<char> with size 3x3.
* 
*/