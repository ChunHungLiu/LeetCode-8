class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) { return n; }
        
        int count = 0, cur = 1;
        for (int i = 2; i < n; ++i) {
            while ( A[i] == A[cur] && A[i] == A[cur-1] && i < n) { ++count; ++i; }
            A[++cur] = A[i];
        }
        
        return n-count;
    }
};