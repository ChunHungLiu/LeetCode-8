class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int len = 0, start = 0;
        string space(L, ' ');
        
        for (int i = 0; i < words.size(); ++i) {
            int val = len + (i-start) + words[i].size(); // assume a minimal of 1 space
            if (val <= L) { len += words[i].size(); continue; }
            
            int num_of_gap = i-start-1;
            int total_space = L-len;
            int average_space = num_of_gap == 0 ? 0 : total_space / num_of_gap;
            int uneven_space = num_of_gap == 0 ? total_space : total_space % num_of_gap;
            string tmp = words[start];
            ++start;
            while (start < i) {
                tmp += space.substr(0, average_space);
                if (uneven_space > 0) { tmp += " "; uneven_space--; }
                tmp += words[start];
                ++start;
            }
            if (num_of_gap == 0) { tmp += space.substr(0, uneven_space); }
            
            len = words[i].size();
            res.push_back(tmp);
        }
        
        if (start == words.size()) { return res; }
        
        string last = words[start];
        len = words[start].size();
        start++;
        while (start < words.size()) {
            last += " ";
            last += words[start];
            len += words[start].size();
            ++len;
            start++;
        }
        last += space.substr(0, L-len);
        
        res.push_back(last);
        return res;
    }
};