class Solution {
public:
    bool exist(vector<vector<char> > &board, string &word, vector<vector<bool> > &visited, int idx, int x, int y) {
        if (idx == word.size()) { return true; }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) { return false; }
        if (visited[x][y] == true) { return false; }
        if (board[x][y] != word[idx]) { return false; }
        
        visited[x][y] = true;
        bool val = exist(board, word, visited, idx+1, x+1, y) || \
                   exist(board, word, visited, idx+1, x, y+1) || \
                   exist(board, word, visited, idx+1, x-1, y) || \
                   exist(board, word, visited, idx+1, x, y-1);
        if (val) { return true; }
        else { visited[x][y] = false; return false; }
    }

    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) { return true; }
        if (board.size() == 0 || board[0].size() == 0) { return false; }
        
        int m = board.size(), n = board[0].size(), len = word.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist(board, word, visited, 0, i, j)) { return true; }
            }
        }

        return false;
    }
};