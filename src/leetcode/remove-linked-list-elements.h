// https://leetcode.com/problems/remove-linked-list-elements/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        for (auto node = head; node != nullptr;) {
            if (node == head && node->val == val) {
                head = head->next;
                delete node;
                node = head;
            }
            else if (node->next != nullptr && node->next->val == val) {
                auto tmp = node->next;
                node->next = node->next->next;
                delete tmp;
            }
            else
                node = node->next;
        }

        return head;
    }
};