class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>> &board, int row, int col) {
        // get next empty space
        if (!getNext(board, row, col)) { return true; } 
        
        vector<char> possible;
        getValue(board, possible, row, col);
        if (possible.size() == 0) { return false; }
        
        for (auto i : possible) {
            board[row][col] = i;
            if (solve(board, row, col)) { return true; }
            board[row][col] = '.';
        }
        
        return false;
    }
    
    bool getNext(vector<vector<char>> &board, int &row, int &col) {
        while (row < board.size() && col < board[0].size()) {
            if (board[row][col] == '.') { return true; }
            ++col;
            if (col == board[0].size()) { ++row; col = 0; }
        }
        return false;
    }
    
    void getValue(vector<vector<char>> &board, vector<char> &possible, int row, int col) {
        bool x[board.size()];
        memset(x, true, board.size());
        
        for (int i = 0; i < board.size(); ++i) {
            if (board[row][i] != '.') { x[board[row][i]-'1'] = false; }
            if (board[i][col] != '.') { x[board[i][col]-'1'] = false; }
            char c = board[row/3*3+i/3][col/3*3+i%3];
            if (c != '.') { x[c-'1'] = false; }
        }
        
        for (int i = 0; i < board.size(); ++i) {
            if (x[i]) { possible.push_back('1'+i); }
        }
    }
};