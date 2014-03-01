class Solution {
public:
    double pow(double x, int n) {
        bool positive = true, reverse = false;
        if (x < 0) { x = -x; if (n%2 == 1) { positive = false; } }
        if (n < 0) { n = -n; reverse = true; }
        
        double res = 1.0, tmp = x;
        while (n > 0) {
            if (n%2 == 1) { res *= tmp; }
            n >>= 1;
            tmp *= tmp;
        }
        
        if (reverse) res = 1 / res;
        
        return positive ? res : -res;
    }
};