class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n == 0) { return 0; }
        int res = A[0];
        for (int i = 1; i < n; ++i) {
            res ^= A[i];
        }
        
        return res;
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