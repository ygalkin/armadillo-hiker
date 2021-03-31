// https://www.hackerrank.com/challenges/tree-inorder-traversal/problem

    void inOrder(Node *root) {
        if (root == nullptr) {
            return;
        }
        
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }

// TODO: implement iterative approach