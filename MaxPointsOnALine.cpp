/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int len = points.size();
        if (len <= 2) { return len; }
        
        int res = 0;
        unordered_map<double, int> table;
        for (int i = 0; i < len; ++i) {
            table.clear();
            int cur_max = 0, same_points = 1;
            for (int j = i+1; j < len; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) { same_points++; continue; }
                
                double slope;
                if (points[i].x == points[j].x) { slope = INT_MAX; }
                else { slope = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x); }
                table[slope]++;
                cur_max = max(cur_max, table[slope]);
            }
            res = max(res, cur_max+same_points);
        }
        
        return res;
    }
};