// separate rows and cols! due to continue
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9 || board[0].size() != 9) return false; 
        set<char> seen;
        
        // check row
        for (int i = 0; i < board.size(); ++i) {
            seen.clear();
            for (int j = 0; j < board[i].size(); ++j) {
                // check row
                if (board[i][j] == '.') { continue; }
                if (board[i][j] < '1' || board[i][j] > '9') { return false; }
                if (seen.find(board[i][j]) != seen.end()) { return false; }
                seen.insert(board[i][j]);
            }
        }
        
        // check col
        for (int i = 0; i < board.size(); ++i) {
            seen.clear();
            for (int j = 0; j < board[i].size(); ++j) {
                // check row
                if (board[j][i] == '.') { continue; }
                if (seen.find(board[j][i]) != seen.end()) { return false; }
                seen.insert(board[j][i]);
            }
        }

        /* Requred idx:
        (0,0), (0,1), (0,2), (1,0), (1,1), (1,2), (2,0), (2,1), (2,2)
        (0,3), (0,4), (0,5), (1,3), (1,4), (1,5), (2,3), (2,4), (2,5)
        ...
        (3,0), (3,1), (3,2), (4,0), (4,1), (4,2), (5,0), (5,1), (5,2)
        */
        for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            seen.clear();
            for (int x = i*3; x < i*3+3; ++x) {
            for (int y = j*3; y < j*3+3; ++y) {
                if (board[x][y] == '.') { continue; }
                if (seen.find(board[x][y]) != seen.end()) { return false; }
                seen.insert(board[x][y]);
            }
            }
        }
        }
        
        return true;
    }
};
