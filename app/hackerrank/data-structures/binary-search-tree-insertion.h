// https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

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
    Node * insert(Node * root, int data) {
        if (root == nullptr)
            return new Node(data);

        auto next_node = (data < root->data) ? &root->left : &root->right;
        *next_node = insert(*next_node, data);
        
        return root;
    }
