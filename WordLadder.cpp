class Solution {
public:
    vector<string> changeOneLetter(string &s, unordered_set<string> &dict) {
        vector<string> res;
        
        for (int i = 0; i < s.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (s[i] == c) { continue; }
                string tmp = s;
                tmp[i] = c;
                if (dict.find(tmp) != dict.end()) {
                    res.push_back(tmp);
                }
            }
        }
        
        return res;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        map<string, string> trace;
        
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            
            if (cur.compare(end) == 0) {
                int res = 1;
                while (cur != start) {
                    ++res; cur = trace[cur];
                }
                return res;
            }
            
            vector<string> available_words = changeOneLetter(cur, dict);
            for (auto s : available_words) {
                if (visited.find(s) != visited.end()) { continue; }
                visited.insert(s);
                q.push(s);
                trace[s] = cur;
            }
        }
        
        return 0;
    }
};