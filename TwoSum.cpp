class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> visited;
        
        for (int i = 0; i < numbers.size(); ++i) {
            int val = target - numbers[i];
            if (visited.find(val) != visited.end()) {
                result.push_back(visited[val]);
                result.push_back(i+1);
            } else {
                visited[numbers[i]] = i+1;
            }
        }
        
        return result;
    }
};