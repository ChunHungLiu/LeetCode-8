class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) { return false; }
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        
        while (left <= right) {
            int mid = (left+right) / 2;
            int x = mid/n, y = mid%n;
            if (matrix[x][y] == target) { return true; }
            else if (matrix[x][y] < target) { left = mid+1; }
            else { right = mid-1; }
        }

        return false;
    }
};