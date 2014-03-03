class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) { return 0; }
        if (divisor == INT_MAX) {
            if (dividend == INT_MIN || dividend == INT_MIN+1) { return -1; }
            else { return dividend == INT_MAX ? 1 : 0; }
        }
        if (divisor == INT_MIN) { return dividend == INT_MIN ? 1 : 0; }
        if (abs(divisor) == 1) { return divisor > 0 ? dividend : -dividend; }

        long long a = dividend < 0 ? -dividend : dividend;
        if (dividend == INT_MIN) { a = -a; }
        long long b = divisor  < 0 ? -divisor  : divisor;
        bool positive = (dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0);
        if (a == b) { return positive ? 1 : -1; }

        long long table[32];
        int idx = 0;
        while (b <= a) {
            table[idx] = b;
            idx++;
            b <<= 1;
        }
        --idx;
        
        int res = 0;
        while (a > 0) {
            if (a >= table[idx]) {
                a -= table[idx];
                res += pow(2, idx);
            }
            --idx;
        }
        
        return positive ? res : -res;
    }
};