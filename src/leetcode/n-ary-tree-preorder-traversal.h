// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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
    void preorder(const Node* node, vector<int>& vals) const {
        if (node == nullptr)
            return;

        vals.push_back(node->val);
        for (auto child : node->children) {
            preorder(child, vals);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ret;
        preorder(root, ret);
        return ret;
    }
};

// TODO: iterative solution