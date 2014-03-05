class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if (n == 0) { return 0; }
        int left[n];
        int right[n];
        stack<int> s;
        
        for (int i = 0; i <  height.size(); ++i) {
            while (!s.empty()) {
                if (height[i] <= height[s.top()]) { s.pop(); }
                else { break; }
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) { s.pop(); }
        
        for (int i = height.size()-1; i >= 0; --i) {
            while (!s.empty()) {
                if (height[i] <= height[s.top()]) { s.pop(); }
                else { break; }
            }
            right[i] = s.empty() ? height.size() : s.top();
            s.push(i);
        }
        while (!s.empty()) { s.pop(); }
        
        int res = INT_MIN;
        for (int i = 0; i < height.size(); ++i) {
            int val = height[i] * (right[i]-left[i]-1);
            res = max(res, val);
        }
        
        return res;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) { return 0; }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > height(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') { height[i][j] = 0; }
                else if (i == 0) { height[i][j] = 1; }
                else { height[i][j] = height[i-1][j]+1; }
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            res = max(res, largestRectangleArea(height[i]));
        }
        
        return res;
    }
};