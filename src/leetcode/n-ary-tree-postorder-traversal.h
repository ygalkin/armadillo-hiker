// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    void postorder(const Node* node, vector<int>& vals) const {
        if (node == nullptr)
            return;

        for (auto child : node->children) {
            postorder(child, vals);
        }
        vals.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ret;
        postorder(root, ret);
        return ret;
    }
};
