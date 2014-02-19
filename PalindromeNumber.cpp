class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        ss << x;
        string s = ss.str();
        string t = string(s.rbegin(), s.rend());
        return s == t;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }

        // get the high bit
        long long high = 1;
        while (x/high != 0) { high *= 10; }
        high /= 10;
        
        while (x >= 10) {
            if (x%10 != x/high) { return false; }
            x %= high; x /= 10;  // get rid of first and last
            high /= 100;
        }
        
        return true;
    }
};