/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(const Interval& a, const Interval& b) {
    return a.start < b.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2) { return intervals; }
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<Interval> res;
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            Interval& cur = res.back();
            if (cur.end >= intervals[i].start) {
                cur.start = min(cur.start, intervals[i].start);
                cur.end = max(cur.end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};