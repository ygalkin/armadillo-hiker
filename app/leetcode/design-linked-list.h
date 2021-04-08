// https://leetcode.com/problems/design-linked-list/

// Single-linked list implementation

class MyLinkedList {
private:
    ListNode* _head = nullptr;

    ListNode* get_node(int index) {
        ListNode* current = _head;

        while (current != nullptr && index > 0) {
            --index;
            current = current->next;
        }

        if (index < 0) {
            return nullptr;
        }

        return current;
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto node = get_node(index);
        if (node == nullptr) {
            return -1;
        }

        return node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto new_node = new ListNode(val);

        new_node->next = _head;
        _head = new_node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (_head == nullptr) {
            addAtHead(val);
            return;
        }

        auto current = _head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new ListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        auto new_node = new ListNode(val);

        auto node = get_node(index - 1);
        if (node == nullptr) {
            return;
        }
        new_node->next = node->next;
        node->next = new_node;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        auto curr = get_node(index);
        if (curr == nullptr) {
            return;
        }
        if (index == 0) {
            _head = curr->next;
            delete curr;
            return;
        }

        auto prev = get_node(index - 1);
        if (prev == nullptr) {
            return;
        }

        prev->next = curr->next;
        delete curr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */