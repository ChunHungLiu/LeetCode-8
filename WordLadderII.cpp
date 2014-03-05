class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, vector<string>> prevMap;
        vector<unordered_set<string>> candidates(2);
        int cur = 0, pre = 1;
        candidates[cur].insert(start);
        
        while (true) {
            swap(cur, pre);
            for (auto iter = candidates[pre].begin(); iter != candidates[pre].end(); ++iter) { dict.erase(*iter); }
            candidates[cur].clear();
            
            for (auto iter = candidates[pre].begin(); iter != candidates[pre].end(); ++iter) {
                for (int pos = 0; pos < iter->size(); ++pos) {
                    string word = *iter;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (word[pos] == c) { continue; }
                        word[pos] = c;
                        if (dict.count(word)) {
                            prevMap[word].push_back(*iter);
                            candidates[cur].insert(word);
                        }
                    }
                }
            }
            
            if (candidates[cur].size() == 0) { return vector<vector<string>>(); }
            if (candidates[cur].count(end)) { break; }
        }
        
        vector<vector<string>> res;
        vector<string> path;
        findLadders(prevMap, path, end, res);

        return res;
    }
    
    void findLadders(unordered_map<string, vector<string>> &prevMap, vector<string> &path, string &word, vector<vector<string>> &res) {
        if (prevMap[word].size() == 0) {
            path.push_back(word);
            vector<string> curPath = path;
            reverse(curPath.begin(), curPath.end());
            res.push_back(curPath);
            path.pop_back();
            return;
        }
        
        path.push_back(word);
        for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter) {
            findLadders(prevMap, path, *iter, res);
        }
        path.pop_back();
    }
};