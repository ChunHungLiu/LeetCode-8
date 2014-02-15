class Solution {
public:
    enum state {UP=0, DOWN, LEFT, RIGHT};
    
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        state direction = RIGHT;
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) { return res; }
        int m = matrix.size(), n = matrix[0].size();
        
        int x = 0, y = 0, count = 0, layer = 0;
        while (count < m*n) {
            res.push_back(matrix[x][y]);
            ++count;
            
            switch (direction) {
                case RIGHT:
                    if (++y == n-layer) {
                        direction = DOWN;
                        y = n-1-layer; ++x; 
                    }
                    break;
                case DOWN:
                    if (++x == m-layer) {
                        direction = LEFT;
                        x = m-1-layer; --y;
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
                        ++layer;
                        x = layer; ++y;
                    }
                    break;
                default:
                    break;
            }
        }
        
        return res;
    }
};