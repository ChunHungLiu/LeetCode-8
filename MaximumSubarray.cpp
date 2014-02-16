class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) { return 0; }
        
        int res = A[0], cur = A[0];
        for (int i = 1; i < n; ++i) {
            cur += A[i];
            cur = max(cur, A[i]);
            res = max(res, cur);
        }
        
        return res;
    }
};