class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() == 0 || T.size() == 0 || S.size() < T.size()) { return ""; }

        map<char, int> table;
        for (int i = 0; i < T.size(); ++i) { table[T[i]]++; }

        int count = 0, start = 0, len = INT_MAX;
        string res = "";
        for (int i = 0; i < S.size(); ++i) {
            if (table.find(S[i]) == table.end()) { continue; }
            
            table[S[i]] -= 1;
            if (table[S[i]] >= 0) count++;
            
            if (count == T.size()) {
                for (int j = start; j <= i; ++j) {
                    if (table.find(S[j]) == table.end()) { continue; }
                    
                    table[S[j]] += 1;
                    if (table[S[j]] > 0) {
                        count--;
                        start = j;
                        if (i-start+1 < len) {
                            len = i-start+1;
                            res = S.substr(start, len);
                        }
                        start++;
                        break;
                    }
                }
            }
        }
    
        return res;
    }
};