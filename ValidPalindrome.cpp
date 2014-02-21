class Solution {
public:
    bool valid(char a) {
        return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9');
    }

    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        
        while (start < end) {
            while (start < end && !valid(s[start])) { ++start; }
            while (start < end && !valid(s[end])) { --end; }
            
            if (tolower(s[start]) != tolower(s[end])) { return false; }
            ++start; --end;
        }
        
        return true;
    }
};