class Solution {
public:
    enum state {RIGHT=0, DOWN, LEFT, UP};

    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
            
        int x = 0, y = 0, cur = 1, layer = 0;
        state direction = RIGHT;
        while (cur <= n*n) {
            res[x][y] = cur;
            ++cur; 
            
            switch(direction) {
                case RIGHT:
                    if (++y == n-layer) {
                        direction = DOWN;
                        y = n-1-layer; ++x;
                    }
                    break;
                case DOWN:
                    if (++x == n-layer) {
                        direction = LEFT;
                        x = n-1-layer; --y;
                    }
                    break;
                case LEFT:
                    if (--y < layer) {
                        direction = UP;
                        y = layer; --x;
                    }
                    break;
                case UP:
                    if (--x == layer) {
                        direction = RIGHT;
                        ++layer; x = layer; ++y;
                    }
                    break;
            }
        }

        return res;
    }
};