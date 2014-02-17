class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1;
        for (int k = m+n-1; k >= 0; --k) {
            if (i < 0) {
                while (j >= 0) 
                    A[k--] = B[j--];
            }
            if (j < 0) break;
            A[k] = (A[i] > B[j]) ? A[i--] : B[j--];
        }
    }
};