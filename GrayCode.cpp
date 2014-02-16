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

class Solution {
public:
    vector<int> grayCode(int n) {
        int num = pow(2, n);
        vector<int> res;
        set<int> seen;
        
        int cur = 0;
        seen.insert(cur);
        res.push_back(cur);
        while (res.size() < num) {
            int tmp = 1;
            while (1) {
                cur ^= tmp;
                if (seen.find(cur) == seen.end()) {
                    seen.insert(cur);
                    res.push_back(cur);
                    break;
                } else {
                    cur ^= tmp; // revert back to cur
                    tmp <<= 1;
                }
            }
        }

        return res;
    }
};