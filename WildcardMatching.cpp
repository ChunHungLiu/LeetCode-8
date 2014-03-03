class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int i = 0, j = 0, tmp = 0, cur = 0;
        bool star = false;
        
        while (*(s+i)) {
            switch(*(p+j)) {
            case '?' : break;    // match any character
            case '*' :
                star = true;
                if (!*(p+j+1)) { return true; }
                tmp = j;
                cur = i;
                --i;    // match * to nothing, backoff i
                break;
            default  :
                if (*(s+i) != *(p+j)) { 
                    if (!star) { return false; }
                    j = tmp;
                    i = cur++;
                }
                break;
            }
            ++i; ++j;
        }
        
        while (*(p+j) == '*') ++j;
        return !*(p+j);
    }
};