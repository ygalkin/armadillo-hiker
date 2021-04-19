// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ret;
        vector<Node*> q;
        
        q.push_back(root);
        while(!q.empty()) {
            const auto size = q.size(); // because we change q size in the loop
            vector<int> level;
            for (auto i = 0; i < size; ++i) {
                const auto node = q[i];
                level.push_back(node->val);
                for (auto child : node->children)
                    q.push_back(child);
            }
            
            ret.push_back(level);
            q.erase(begin(q), begin(q) + size);
        }
        
        return ret;
    }
};