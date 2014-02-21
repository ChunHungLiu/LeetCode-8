/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) { return NULL; }
        map<UndirectedGraphNode*, UndirectedGraphNode*> table;
        UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
        table[node] = res;
        
        queue<UndirectedGraphNode*> q;
        q.push(node);

        while (!q.empty()) {
            UndirectedGraphNode* cur = q.front(); q.pop();
            UndirectedGraphNode* cur_cp;
            if (table.find(cur) != table.end()) {
                cur_cp = table[cur];
            } else {
                cur_cp = new UndirectedGraphNode(cur->label);
            }
            
            for (int i = 0; i < cur->neighbors.size(); ++i) {
                UndirectedGraphNode* tmp;
                if (table.find(cur->neighbors[i]) != table.end()) {
                    tmp = table[cur->neighbors[i]];
                } else {
                    tmp = new UndirectedGraphNode(cur->neighbors[i]->label);
                    table[cur->neighbors[i]] = tmp;
                    q.push(cur->neighbors[i]);
                }
                cur_cp->neighbors.push_back(tmp);
            }
            
            table[cur] = cur_cp;
        }
        
        return res;
        
    }
};