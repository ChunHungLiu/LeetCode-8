class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        int left = 0, right = n-1;
        
        while (left <= right) {
            int mid = (left+right) / 2;
            if (A[mid] == target) {
                left = mid; right = mid;
                while (left >= 0 && A[left] == target) { --left; }
                while (right < n && A[right] == target) { ++right; }
                res.push_back(left+1); res.push_back(right-1);
                return res;
            } else if (A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        res.push_back(-1); res.push_back(-1);
        return res;
    }
};