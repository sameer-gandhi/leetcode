class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int row = 0;
                    int col = 0;
                    while (col < n) {
                        if (col != j && board[i][col] == board[i][j]) {
                            return false;
                        }
                        col++;
                    }
                    while (row < n) {
                        if (row != i && board[row][j] == board[i][j]) {
                            return false;
                        }
                        row++;
                    }
                    row = 0;
                    col = 0;
                    while (row < n) {
                        if (board[3 * (i / 3) + row / 3]
                                 [3 * (j / 3) + row % 3] == board[i][j] &&
                            ((3 * (i / 3) + row / 3) != i ||
                             (3 * (j / 3) + row % 3) != j)) {
                            return false;
                        }
                        row++;
                    }
                }
            }
        }
        return true;
    }
};