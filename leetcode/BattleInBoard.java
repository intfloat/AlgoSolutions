public class Solution {
    public int countBattleships(char[][] board) {
        if (board.length == 0) {
            return 0;
        }
        int row = board.length, col = board[0].length;
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) {
                    ++res;
                }
            }
        }
        return res;
    }
}