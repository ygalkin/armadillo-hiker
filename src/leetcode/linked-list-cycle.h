// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Space complexity: O(1).
    // Floyd's cycle-detection algorithm (tortoise and hare)
    bool hasCycle(ListNode* head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                return true;
            }
        }

        return false; // if fast == nullptr we have end of the list       
    }
};

// https://www.geeksforgeeks.org/?p=170701
// TODO: Brent's cycle detection algorithm
