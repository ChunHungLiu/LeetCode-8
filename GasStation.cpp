class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if (n < 1) { return 0; }

        for (int start = 0; start < n; ++start) {
            int cur_sum = gas[start]-cost[start], nxt = (start+1)%n;
            
            while (cur_sum >= 0) {
                cur_sum += gas[nxt]-cost[nxt];
                nxt = (nxt+1)%n;
                if (cur_sum >= 0 && nxt == start) { return start; }
            }
            
            if (nxt > start) { start = nxt-1; }
        }
        
        return -1;
    }
};