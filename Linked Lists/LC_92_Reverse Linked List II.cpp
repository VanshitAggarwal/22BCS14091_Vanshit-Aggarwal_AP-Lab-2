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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // Edge case: if head is null or m == n, return head
        if (!head || m == n) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Reach the node just before the start of the section to be reversed
        for (int i = 1; i < m; i++) {
            prev = prev->next;
        }

        // Step 2: Start reversing from position m to n
        ListNode* start = prev->next;
        ListNode* then = start->next;

        for (int i = 0; i < n - m; i++) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        return dummy->next; // Return the modified list
    }
};
