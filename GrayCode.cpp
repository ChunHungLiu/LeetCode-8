class Solution {
public:
    vector<int> grayCode(int n) {
        int num = pow(2, n);
        vector<int> res;
        
        for (int i = 0; i < num; ++i) {
            res.push_back((i>>1) ^ i);
        }
        
        return res;
    }
};

