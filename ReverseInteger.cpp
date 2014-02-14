// discuss overflow!
class Solution {
public:
    int reverse(int x) {
        bool positive = true;
        if (x < 0) { positive = false; x = -x; }
        
        int res = 0;
        while (x > 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        
        if (positive) { return res; }
        else { return -res; }
    }
};