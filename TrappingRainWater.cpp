class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) { return 0; }
        int left[n], right[n];
        
        left[0] = A[0];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i-1], A[i]);
        }

        right[n-1] = A[n-1];        
        for (int i = n-2; i >= 0; --i) {
            right[i] = max(right[i+1], A[i]);
        }
        
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += min(left[i], right[i]) - A[i];
        }
        
        return sum;
    }
};
