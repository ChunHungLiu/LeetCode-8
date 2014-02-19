class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) { return 0; }
        int m = triangle.size();
        vector<int> cur;
        vector<int> nxt;
        cur.push_back(triangle[0][0]);

        for (int i = 1; i < triangle.size(); ++i) {
            vector<int> nxt;
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) { nxt.push_back(cur[0] + triangle[i][j]); }
                else if (j == triangle[i].size()-1) { nxt.push_back(cur.back() + triangle[i][j]); }
                else { nxt.push_back(triangle[i][j] + min(cur[j-1], cur[j])); }
            }
            cur = nxt; nxt.clear();
        }

        int res = INT_MAX;
        for (int i = 0; i < cur.size(); ++i) {
            res = min(res, cur[i]);
        }

        return res;
    }
};