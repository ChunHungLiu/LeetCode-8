// passed on my machine, failed @ leetcode, don't know why
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) { return; }
        int m = matrix.size(), n = matrix[0].size();
        int col = -1, row = -1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (row == -1) {
                        row = i; col = j;
                    } else {
                        matrix[row][j] = 0;
                        matrix[i][col] = 0;
                    }
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == row || j == col) continue;
                if (matrix[row][j] == 0 || matrix[i][col] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) matrix[i][col] = 0;
        for (int j = 0; j < n; ++j) matrix[row][j] = 0;
    }
};


// does not pass large arrays
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) { return; }
        unsigned long long row = 0, col = 0;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row |= (1L << i);
                    col |= (1L << j);
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ( (row>>i)&1 > 0 || (col>>j)&1 > 0 ) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) { return; }
        int m = matrix.size(), n = matrix[0].size();
        int row[m], col[n];
        for (int i = 0; i < m; ++i) row[i] = 1;
        for (int j = 0; j < n; ++j) col[j] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] == 0 || col[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};