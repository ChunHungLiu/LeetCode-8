class Solution {
public:
    int romanToInt(string s) {
        // I=1, V=5, X=10, L=50, C=100, D=500, M=1000
        map<char, int> table;
        table['M'] = 1000;
        table['D'] = 500;
        table['C'] = 100;
        table['L'] = 50;
        table['X'] = 10;
        table['V'] = 5;
        table['I'] = 1;
        
        int res = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (table[s[i]] < table[s[i+1]]) res -= table[s[i]];
            else res += table[s[i]];
        }
        res += table[s[s.size()-1]];
        
        return res;
    }
};