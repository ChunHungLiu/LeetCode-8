class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!*needle) { return haystack; }
        if (!*haystack) { return NULL; }
        
        int len1 = 0, len2 = 0;
        while (*(haystack+len1)) { ++len1; }
        --len1;
        while (*(needle+len2)) { ++len2; }
        --len2;

        int start = 0;
        while (start <= len1-len2) {
            int i = start, j = 0;
            while (*(haystack+i) && *(needle+j) && *(haystack+i) == *(needle+j)) { ++i; ++j; }
            if (!*(needle+j)) { return haystack+start; }
            ++start;
        }

        return NULL;
    }
};