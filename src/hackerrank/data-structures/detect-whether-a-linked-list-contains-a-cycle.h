// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    if (head == nullptr) {
        return false;
    }

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return true;
        }
    }

    return false; // if fast == nullptr we have end of the list          
}