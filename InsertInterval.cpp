/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (max(intervals[i].start, newInterval.start) <= min(intervals[i].end, newInterval.end)) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            } else if (newInterval.start > intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.push_back(newInterval);
                inserted = true;
                while (i < intervals.size()) {
                    res.push_back(intervals[i]);
                    ++i;
                }
            }
        }
        if (!inserted) res.push_back(newInterval);
        
        return res;
    }
};