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
    void dfs(unordered_map<Node*, Node*>& visited, Node* node){
        if(visited.count(node)){
            return;
        }

        Node* clone = new Node(node->val);
        visited[node] = clone;

        for(Node* nei : node->neighbors){
            if(!visited.count(nei)){
                dfs(visited, nei);
            }
            clone->neighbors.push_back(visited[nei]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> visited;
        dfs(visited, node);
        return visited[node];
    }
};
