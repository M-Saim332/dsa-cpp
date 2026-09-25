/*
Approach:
- Use two pointers: slow and fast.
- Start both pointers from the head of the linked list.
- Move slow by 1 node at a time.
- Move fast by 2 nodes at a time.
- When fast reaches the end of the list, slow will be at the middle.
- Return slow as the middle node.

Time Complexity: O(n)
Space Complexity: O(1)

Key Concept:
- Slow and Fast Pointer Technique
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
