class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int old = 0, cur = 0, count = 0;
        while (cur < n) {
            if (A[cur] != elem) {
                if (old != cur) A[old] = A[cur];
                ++cur; ++old;
            } else {
                ++count; ++cur;
            }
        }
        
        return n-count;
    }
};