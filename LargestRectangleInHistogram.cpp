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
};