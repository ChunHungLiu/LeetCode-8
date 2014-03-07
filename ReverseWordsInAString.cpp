class Solution {
public:
    void reverseWords(string &s) {
        string res = "";
        int end = s.size(), start = 0;
        
        while (end > 0) {
            end = s.find_last_not_of(' ', end);
            if (end == string::npos) { break; }
            start = s.find_last_of(' ', end);
            if (start == string::npos) { start = -1; }
            string sub = s.substr(start+1, end-start);
            if (res != "") { res += " "; }
            res += sub;
            end = start;
        }
      
        s = res;
    }
};