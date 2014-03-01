class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.size() == 0) { return res; }
        int n = L[0].size();
        if (S.size() == 0 || n == 0 || S.size() < n*L.size()) { return res; }

        map<string, int> toFind;
        map<string, int> hasFound;
        
        for (auto s : L) toFind[s]++;
        
        for (int i = 0; i < S.size()-n*L.size()+1; ++i) {
            int j = i;
            string tmp = S.substr(j, n);
            hasFound.clear();
            
            while (toFind.find(tmp) != toFind.end() && j < i+n*L.size()) {
                hasFound[tmp]++;
                if (hasFound[tmp] > toFind[tmp]) break;
                j += n;
                tmp = S.substr(j, n);
            }
            
            if (j == i+n*L.size()) { res.push_back(i); }
        }

        return res;
    }
};