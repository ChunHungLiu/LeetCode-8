class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0, end = height.size()-1, res = 0;
        
        while (start < end) {
            int cur = (end-start) * min(height[start], height[end]);
            res = max(res, cur);
            
            if (height[start] < height[end]) {
                while (start < end && height[start] > height[start+1]) { ++start; }
                ++start;
            } else {
                while (start < end && height[end] > height[end-1]) { --end; }
                --end;            
            }
        }

        return res;
    }
};