class Solution {
public:
    bool isOperator(string &s) {
        if (s.size() > 1) { return false; }
        return (s[0] == '+') || (s[0] == '-') || (s[0] == '*') || (s[0] == '/');
    }
    
    int evalRPN(vector<string> &tokens) {
        int res = 0;
        stack<int> s;
        
        for (auto i : tokens) {
            if (isOperator(i)) {
                if (s.empty()) { return 0; }
                int val1 = s.top(); s.pop();
                if (s.empty()) { return 0; }
                int val2 = s.top(); s.pop();
                
                switch(i[0]) {
                    case '+': res = val1 + val2; break;
                    case '-': res = val2 - val1; break;
                    case '*': res = val1 * val2; break;
                    case '/': res = val2 / val1; break;
                    default: return 0; break;
                }
                
                s.push(res);
            } else {
                s.push(atoi(i.c_str()));
            }
        }

        if (s.empty()) { return 0; }
        return s.top();
    }
};