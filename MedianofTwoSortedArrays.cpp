// passed on my machine, but failed at leetcode, don't know why
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m == 0 && n == 0) { return 0; }
        if (m == 0) { return n%2 == 0 ? (B[n/2-1]+B[n/2]) / 2.0 : B[n/2]; }
        if (n == 0) { return m%2 == 0 ? (A[m/2-1]+A[m/2]) / 2.0 : A[m/2]; }
        if (m == 1 && n == 1) { return (A[0]+B[0]) / 2.0; }

        int len = m+n, i = 0, j = 0;
        int pre = -1, cur = min(A[0], B[0]);
        
        for (int k = 0; k < len/2; ++k) {
            if (i == m || A[i] > B[j]) { ++j; }
            else { ++i; }

            pre = cur;
            if (i == m) { cur = B[j]; }
            else if (j == n) { cur = A[i]; }
            else { cur = min(A[i], B[j]); }
        }

        if (len%2 == 0) { return (pre+cur) / 2.0; }
        else { return cur; }
    }
};


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n;
        if (len == 0) return 0;
        else if (m == 0) { return case0(B, n); }
        else if (n == 0) { return case0(A, m); }
        else if (m == 1) { return case1(A[0], B, n); }
        else if (n == 1) { return case1(B[0], A, m); }
        else if (m == 2) { return case2(A[0], A[1], B, n); }
        else if (n == 2) { return case2(B[0], B[1], A, m); }
        
        int i = m/2, j = n/2;
        if (A[i] <= B[j]) {
            int k = (m%2 == 0) ? min(i-1, n-j-1) : min(i, n-j-1);
            return findMedianSortedArrays(A+k, m-k, B, n-k);
        } else {
            int k = (n%2 == 0) ? min(j-1, m-i-1) : min(j, m-i-1);
            return findMedianSortedArrays(A, m-k, B+k, n-k);
        }
    }
    
    // median is in this array
    double case0(int C[], int n) {
        return (n%2 == 0) ? (C[n/2-1]+C[n/2]) / 2.0 : C[n/2]; 
    }
    
    // add 1 number to this array
    double case1(int med, int C[], int n) {
        if (n == 0) { return med; }
        else if (n == 1) { return (med+C[0]) / 2.0; }
        else if (n%2 == 0) {
            int left = C[n/2-1], right = C[n/2];
            if (med <= left) { return left; }
            else if (med >= right) { return right; }
            else { return med; }
        } else {
            int left = C[n/2-1], mid = C[n/2], right = C[n/2+1];
            if (med <= left) { return (left+mid) / 2.0; }
            else if ( med >= right) { return (right+mid) / 2.0; }
            else { return (med+mid) / 2.0; }
        }
    }
    
    // add 2 numbers to this array
    double case2(int num1, int num2, int C[], int n) {
        if (n == 0) { return (num1+num2) / 2.0; }
        else if (n == 1) { 
            if (num1 >= C[0]) { return num1; }
            else if (num2 <= C[0]) { return num2; }
            else { return C[0]; }
        } else if (n == 2) {
            int a = C[0], b = C[1];
            
            if (num2 <= b && num1 >= a) { return (num1+num2) / 2.0; }
            else if (num1 <= a && num2 >= b) { return (a+b) / 2.0; }
            else if (num2 <= b) { return (num2+a) / 2.0; }
            else { return (num1+b) / 2.0; }
        } else if (n == 3) {
            int a = C[0], b = C[1], c = C[2];
            
            if (num2 <= a) { return a; }
            else if (num1 >= c) { return c; }
            else if (num2 <= b) { return num2; }
            else if (num1 >= b) { return num1; }
            else { return b; }
        } else {
            // if array size is less than 4, add INT_MIN and INT_MAX at two ends of the array
            int a = C[n/2-2];
            int b = C[n/2-1];
            int c = C[n/2];
            int d = C[n/2+1];
            
            if (n%2 == 0) {
                // on left side
                if (num2 <= a) { return (a+b) / 2.0; }
                else if (num2 <= b) { return (num2+b) / 2.0; }
                // on right side
                else if (num1 >= d) { return (c+d) / 2.0; }
                else if (num1 >= c) { return (c+num1) / 2.0; }
                // between b, c, num1 and num2
                else if (num2 <= c && num1 <= b) { return (num2+b) / 2.0; }
                else if (num2 <= c && num1 > b) { return (num1+num2) / 2.0; }
                else if (num1 >= b && num2 >= c) { return (num1+c) / 2.0; }
                else { return (b+c) / 2.0; }
            } else {
                // on left side
                if (num2 <= b) { return b; }
                // on right side
                else if (num1 >= d) { return d; }
                // between b, c, d, num1 and num2
                else if (num2 <= c) { return num2; }
                else if (num1 >= c) { return num1; }
                else { return c; }
            }
        } 
    }
};