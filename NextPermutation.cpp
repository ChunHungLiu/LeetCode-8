class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) { return; }
        
        int i = num.size() - 2;
        while (i >= 0 && num[i] >= num[i+1]) { --i; }
        if (i < 0) { reverse(num.begin(), num.end()); return; }
        
        int j = num.size()-1;
        while (j > i && num[j] <= num[i]) { --j; }
        
        swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.end());
    }
};