// https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        std::cout << node->data << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
