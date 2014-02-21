class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1) { return true; }
        int furthest = 0;
        
        for (int i = 0; i < n; ++i) {
            furthest = max(furthest, i+A[i]);
            if (i < n-1 && A[i] == 0 && furthest <= i) { return false; }
        }
        
        return true;
    }
};