// https://leetcode.com/problems/reverse-linked-list/

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

// Recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* new_head = nullptr;
        reverseList_recursive(head, &new_head)->next = nullptr;
        return new_head;
    }
    
    ListNode* reverseList_recursive(ListNode* head, ListNode** new_head) {
        head->next == nullptr ? *new_head = head : reverseList_recursive(head->next, new_head)->next = head;
        return head;
    }
};

// Iterative solition
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* current = head;
        ListNode* prev = nullptr;
        while(current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};