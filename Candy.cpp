class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        if (n == 0) { return 0; }
        
        int left[n], right[n];
        
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            if (i == 0) { left[i] = cur; }
            else if (ratings[i] > ratings[i-1]) { left[i] = ++cur; }
            // else if (ratings[i] == ratings[i-1]) { left[i] = cur; } 
            else { left[i] = 1; cur = 1; }
        }
        
        cur = 1;
        for (int i = n-1; i >= 0; --i) {
            if (i == n-1) { right[i] = cur; }
            else if (ratings[i] > ratings[i+1]) { right[i] = ++cur; }
            // else if (ratings[i] == ratings[i+1]) { right[i] = cur; }
            else { right[i] = 1; cur = 1; }
        }
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += max(left[i], right[i]);
        }
        
        return sum;
    }
};