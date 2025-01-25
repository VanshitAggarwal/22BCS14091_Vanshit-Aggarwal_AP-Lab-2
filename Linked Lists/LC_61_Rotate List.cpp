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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Find the length of the list
        ListNode* temp = head;
        int len = 1;
        while (temp->next) {
            len++;
            temp = temp->next;
        }
        
        // Find the new head position after k rotations
        k = k % len;
        if (k == 0) return head;
        
        // Connect the last node to the head to form a circular linked list
        temp->next = head;
        
        // Find the new tail (len - k - 1) and the new head (len - k)
        for (int i = 0; i < len - k; i++) {
            temp = temp->next;
        }
        
        // Set the new head and break the circular link
        ListNode* newHead = temp->next;
        temp->next = nullptr;
        
        return newHead;
    }
};
