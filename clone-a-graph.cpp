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
    Node* dfs(Node* node,unordered_map<Node*,Node*>& nodeMap){
        if(nodeMap[node]){
            return nodeMap[node];
        }
        
        Node* copy = new Node(node->val);
        nodeMap[node] = copy;
        for(Node* nei:node->neighbors){
            copy -> neighbors.push_back(dfs(nei,nodeMap));
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        if(node -> neighbors.size() == 0){
            Node* clone = new Node(node -> val);
            return clone;
        }
        unordered_map<Node*,Node*> nodeMap;
        Node* ans = dfs(node,nodeMap);
        return ans;
    }
};
