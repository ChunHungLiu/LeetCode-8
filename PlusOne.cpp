class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            int val = digits[i] + carry;
            carry = val / 10;
            res.push_back(val%10);
        }
        if (carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        
        return res;
    }
};