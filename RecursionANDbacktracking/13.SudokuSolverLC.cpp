class Solution {
    /*bool isValid(int board[N][N], int row, int col, int num) {
    // Check if num is already present in the same row or column
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check if num is already present in the 3x3 subgrid
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[subgridStartRow + i][subgridStartCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}*/
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<9;i++){
            if(board[i][col] == c)return false;
            if(board[row][i] == c)return false;

            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){

                if(board[i][j] == '.'){
                    for(char c = '1';c<='9';c++){
                        if(isValid(board, i, j , c)){
                            board[i][j] = c;

                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
