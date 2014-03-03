class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!*p) { return !*s; }
        if (*(p+1) != '*') { return ( (*p == *s || (*s && *p == '.')) && isMatch(s+1, p+1) ); }
        
        // *(p+1) is '*'
        while ( (*p == *s) || (*s && *p == '.') ) {
            if (isMatch(s, p+2)) return true;
            ++s;
        }
        
        return isMatch(s, p+2);
    }
};