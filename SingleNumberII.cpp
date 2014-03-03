class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int, int> table;
        for (int i = 0; i < n; ++i) {
            ++table[A[i]];
        }
        for (map<int, int>::iterator it = table.begin(); it != table.end(); ++it) {
            if (it->second != 3) { return it->first; }
        }
        
        return -1;
    }
};

class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32] = {0};
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((A[j] >> i) & 1) {
                    ++count[i];
                }
            }
            res |= ((count[i] % 3) << i);
        }

        return res;
    }
};

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        
        for (int i = 0; i < n; ++i) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        
        return ones;
    }
};