// https://www.hackerrank.com/challenges/tree-postorder-traversal/problem

    void postOrder(Node *root) {
        if (root == nullptr) {
            return;
        }
        
        postOrder(root->left);
        postOrder(root->right);
        
        cout << root->data << " ";
    }

// TODO: implement iterative approach