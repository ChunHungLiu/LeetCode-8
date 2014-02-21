class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0 || dict.find(s) != dict.end()) { return true; }
        
        for (int i = 1; i < s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            
            if (dict.find(right) != dict.end() && wordBreak(left, dict)) {
                return true;
            }
        }
        
        return false;
    }
};