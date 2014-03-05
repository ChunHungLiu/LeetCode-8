// same idea, passed on my machine but failed at leetcode. Don't know why
class Solution {
public:
    struct Node {
        int x, y;
        Node(int x_, int y_) : x(x_), y(y_) { }
    };
    
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0) { return; }
        int m = board.size(), n = board[0].size();
        queue<Node> q;
        
        for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                if (board[i][j] == 'O') { 
                    q.push(Node(i, j));
                    board[i][j] = '#';
                    while (!q.empty()) {
                        Node cur = q.front(); q.pop();
                        if (cur.x > 0 && board[cur.x-1][cur.y] == 'O') { board[cur.x-1][cur.y] = '#'; q.push(Node(cur.x-1, cur.y)); }
                        if (cur.y > 0 && board[cur.x][cur.y-1] == 'O') { board[cur.x][cur.y+1] = '#'; q.push(Node(cur.x, cur.y-1)); }
                        if (cur.x < m-1 && board[cur.x+1][cur.y] == 'O') { board[cur.x+1][cur.y] = '#'; q.push(Node(cur.x+1, cur.y)); }
                        if (cur.y < n-1 && board[cur.x][cur.y+1] == 'O') { board[cur.x][cur.y+1] = '#'; q.push(Node(cur.x, cur.y+1)); }
                    }
                }
            }
        }
        }
        
        for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '#') { board[i][j] = 'O'; }
            else { board[i][j] = 'X'; }
        }
        }
    }
};