class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cur = 0, res = 0;
        
        while (*(s+cur)) { ++cur; }
        --cur;
        
        while (*(s+cur) == ' ') { --cur; }
        
        while(cur >= 0 && *(s+cur) != ' ') {
            ++res; --cur;
        }
        
        return res;
    }
};