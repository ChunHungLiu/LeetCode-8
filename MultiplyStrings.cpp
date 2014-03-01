class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res(num1.size()+num2.size(), 0);
        
        for (int i = 0; i < num1.size(); ++i) {
            int a = num1[num1.size()-i-1] - '0';
            int carry = 0;
            for (int j = 0; j < num2.size(); ++j) {
                int b = num2[num2.size()-j-1] - '0';
                int val = carry + res[i+j] + a*b;
                res[i+j] = val % 10;
                carry = val / 10;
            }
            res[i+num2.size()] = carry;
        }
        
        int len = num1.size()+num2.size()-1;
        while (len > 0 && res[len] == 0) { --len; }
        
        string s = "";
        while (len >= 0) { s.push_back('0'+res[len--]); }
        
        return s;
    }
};