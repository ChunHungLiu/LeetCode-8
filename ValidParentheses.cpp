class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0 || s.length()%2) { return false; }
        
        stack<char> table;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                table.push(s[i]);
            } else if (s[i] == ')') {
                if (!table.empty() && table.top() == '(') { table.pop(); }
                else { return false; }
            } else if (s[i] == ']') {
                if (!table.empty() && table.top() == '[') { table.pop(); }
                else { return false; }
            } else if (s[i] == '}') {
                if (!table.empty() && table.top() == '{') { table.pop(); }
                else { return false; }
            } else {
                return false;
            }
        }
        
        return table.empty();
    }
};