/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        map<Node*, Node*> mapping;
        set<Node*> visited;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* nnode = q.front(); q.pop();
            if (visited.count(nnode)) continue;
            visited.insert(nnode);
            if (!mapping.count(nnode)) {
                mapping[nnode] = new Node();
                mapping[nnode]->val = nnode->val;
            }
            // Process node
            for (Node* neighbor: nnode->neighbors) {
                if (!mapping.count(neighbor)) {
                    mapping[neighbor] = new Node(neighbor->val);
                }
                mapping[nnode]->neighbors.push_back(mapping[neighbor]);
            }

            // Add neighbors for processing
            for (Node* neighbor: nnode->neighbors) {
                if (!visited.count(neighbor)) {
                    q.push(neighbor);
                }
            }
        }
        return mapping[node];
    }
};