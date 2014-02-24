class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) { return 0; }
        int furthest = A[0], count = 1, idx = 0;
        
        while (idx < n) {
            if (furthest >= n-1) { return count; }
            
            int cur_max = furthest;
            while (idx <= furthest && idx < n) {
                cur_max = max(cur_max, A[idx]+idx);
                ++idx;
            }
            --idx;
            if (cur_max == furthest) { return 0; }
            furthest = cur_max;
            ++count;
        }
        
        return 0;
    }
};