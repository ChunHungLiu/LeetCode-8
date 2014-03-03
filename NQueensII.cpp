class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        int table[n];
        for (int i = 0; i < n; ++i) { table[i] = -1; }
        
        solveNQueens(res, 0, n, table);
        
        return res;
    }
    
    void solveNQueens(int &res, int idx, int n, int table[]) {
        if (idx == n) { ++res; return; }
        
        for (int i = 0; i < n; ++i) {
            if (feasible(idx, i, n, table)) {
                table[idx] = i;
                solveNQueens(res, idx+1, n, table);
                table[idx] = -1;
            }
        }
    }
    
    bool feasible(int idx, int cur, int n, int table[]) {
        for (int i = 0; i < idx; ++i) {
            if (table[i] == cur || table[i]+idx-i == cur || table[i]-idx+i == cur) { return false; }
        }
        
        return true;
    }
};