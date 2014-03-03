class Solution {
public:
    bool isNumber(const char *s) {
        bool dots = false, expon = false, number = false;
        int len = 0;
        while (*(s+len) == ' ') { ++len; }                      // get rid of ' ';
        if (*(s+len) == '-' || *(s+len) == '+') { ++len; }      // get rid of sign
        
        while (*(s+len)) {
            if (*(s+len) == '.' && dots == false && expon == false) { dots = true; } // dots can only appear once, but can be anywhere
            else if (*(s+len) == 'e' && expon == false && number == true) { 
                if (*(s+len+1) == '-' || *(s+len+1) == '+') { ++len; } // match "1e+6" (valid)
                expon = true; 
                number = false;     // to prevend "1e" (invalid)
            } else if (*(s+len) >= '0' && *(s+len) <= '9') { 
                number = true; 
            } else if (*(s+len) == ' ') {
                while (*(s+len) == ' ') { ++len; } // get rid of trimming ' '
                return number && !*(s+len);
            } else { return false; }
            ++len;
        }
        
        return number;
    }
};