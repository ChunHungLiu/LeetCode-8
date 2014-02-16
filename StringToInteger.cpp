class Solution {
public:
    // how about scientic representationas?
    // how about overflows?
    int atoi(const char *str) {
        if (!*str) { return 0; }
        
        // get rid of space
        int cur = 0;
        while (*(str+cur) == ' ') { ++cur; }

        // positive or negative?  
        bool neg = false;
        if (*(str+cur) == '-') { neg = true; ++cur; }
        if (*(str+cur) == '+') { neg = false; ++cur; }
        
        long long sum = 0;
        while (*(str+cur)) {
            if (*(str+cur) < '0' || *(str+cur) > '9') { break; }
            sum *= 10;
            sum += *(str+cur) - '0';
            ++cur;
        }
        
        if (neg) sum = -sum;
        
        if (sum >= INT_MAX) { return INT_MAX; }
        if (sum <= INT_MIN) { return INT_MIN; }
        return sum;
    }
};