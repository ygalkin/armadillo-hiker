// https://www.hackerrank.com/challenges/is-binary-search-tree/problem

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
bool is_bst(Node* node, Node* min, Node* max) {
    if (node == nullptr) {
        return true;
    }

    if ((min && node->data <= min->data) || (max && node->data >= max->data)) {
        return false;
    }

    return is_bst(node->left, min, node) && is_bst(node->right, node, max);
}

bool checkBST(Node* root) {
    return is_bst(root, nullptr, nullptr);
}