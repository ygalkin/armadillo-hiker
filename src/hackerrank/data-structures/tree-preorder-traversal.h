// https://www.hackerrank.com/challenges/tree-preorder-traversal/problem

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

// TODO: implement iterative approach