class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n-1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target) { return mid; }
            else if (A[mid] < target) { ++left; }
            else { --right; }
        }
        
        return left;
    }
};