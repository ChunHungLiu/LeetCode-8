class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n < 2) { return; }
        
        for (int x = 0; x < n/2; ++x) {
            // y is the offset here
            for (int y = 0; y < n-2*x-1; ++y) {
                int tmp = matrix[x][x+y];
                matrix[x][x+y] = matrix[n-x-y-1][x];
                matrix[n-x-y-1][x] = matrix[n-x-1][n-x-y-1];
                matrix[n-x-1][n-x-y-1] = matrix[x+y][n-x-1];
                matrix[x+y][n-x-1] = tmp;
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int N = matrix.size();
        if (N < 2) return;
        
        // do it in layer
        for (int i = 0; i < N/2; i++) {
            for (int j = i; j < N-1-i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j]         = matrix[N-j-1][i];
                matrix[N-j-1][i]     = matrix[N-i-1][N-j-1];
                matrix[N-i-1][N-j-1] = matrix[j][N-i-1];
                matrix[j][N-i-1]     = tmp;
            }            
        }
    }
};