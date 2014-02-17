class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) { return n; }
        
        int count = 0, cur = 0;
        for (int i = 1; i < n; ++i) {
            while (A[i] == A[cur] && i < n) { ++count; ++i; }
            A[++cur] = A[i];
        }
        
        return n-count;
    }
};