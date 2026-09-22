/*
Problem: Reverse Linked List
LeetCode: 206

Approach:
- Use three pointers: prev, curr, and next.
- Start prev as nullptr and curr as head.
- Traverse the linked list using curr.
- Store the next node before changing the current node's link.
- Reverse the current node's pointer by pointing it to prev.
- Move prev and curr one step forward.
- When curr becomes nullptr, prev becomes the new head.
- Return prev.

Time Complexity: O(n)
Space Complexity: O(1)

Key Concepts:
- Singly Linked List
- Three Pointer Technique
- Iteration
- Pointer Manipulation
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
