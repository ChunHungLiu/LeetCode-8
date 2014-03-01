class Solution {
public:
    int sqrt(int x, int left, int right) {
        if (left >= right) { return left; }
        int mid = (left + right)/2;
        
        if (pow(mid, 2) <= x && pow(mid+1, 2) > x) { return mid; }
        else if (pow(mid, 2) > x) { return sqrt(x, left, mid-1); }
        else { return sqrt(x, mid+1, right); }
    }

    int sqrt(int x) {
        if (x <= 0) { return 0; }
        int right = 1;
        while (pow(right, 2) <= x) { right <<= 1; }
        
        return sqrt(x, right/2, right);
    }
};