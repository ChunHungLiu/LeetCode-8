class Solution {
public:
    bool feasible(int cur, int n, int pos, int table[]) {
        for (int i = 0; i < cur; ++i) {
            if (table[i] == pos || abs(table[i]-pos) == abs(i-cur)) { return false; }
        }
        return true;
    }

    void solveNQueens(vector<vector<string> > &res, int cur, int n, int table[]) {
        if (cur == n) { // we got a solution!
            vector<string> solution(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                solution[i][table[i]] = 'Q';
            }
            res.push_back(solution);
            return;
        } 
        
        for (int i = 0; i < n; ++i) {
            if (feasible(cur, n, i, table)) {
                table[cur] = i;
                solveNQueens(res, cur+1, n, table);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        int table[n];

        solveNQueens(res, 0, n, table);
        
        return res;
    }
};