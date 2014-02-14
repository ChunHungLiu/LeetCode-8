class Solution {
public:
    string convert(string s, int nRows) {
        string table[nRows];
        for (int i = 0; i < nRows; ++i)
            table[i] = "";
        
        int cur_row = 0;
        bool direction_down = true;
        for (int i = 0; i < s.size(); ++i) {
            table[cur_row].push_back(s[i]);
            if (direction_down) {
                if (++cur_row == nRows) {
                    direction_down = false; cur_row = max(0, nRows - 2);
                    if (cur_row == 0) { direction_down = true; }
                }
            } else {
                if (--cur_row == 0) { direction_down = true; }
            }
        }
        
        string res = "";
        for (int i = 0; i < nRows; ++i) 
            res.append(table[i]);
        
        return res;
    }
};