class Solution {
public:
    bool search(int A[], int n, int target) {
        if (n == 0) { return false; }
        if (n == 1) { return A[0] == target; }
        
        int left = 0, right = n-1; 
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target) { return true; }
            if (A[left] < A[mid]) { // left part is normal
                if (A[left] <= target && target < A[mid]) 
                    right = mid - 1;
                else
                    left = mid + 1;
            } else if (A[left] > A[mid]) { // right part is sorted
                if (A[mid] < target && target <= A[right])
                    left = mid + 1;
                else 
                    right = mid - 1;
            } else {
                ++left;
            }
        }
        
        return false;
    }
};