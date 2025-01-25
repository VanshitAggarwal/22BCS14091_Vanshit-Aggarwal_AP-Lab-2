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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head != nullptr) {

            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all duplicate nodes
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Skip the last duplicate node
                prev->next = head->next;
            } else {
                // Move prev to the current node if no duplicates
                prev = prev->next;
            }
            head = head->next;
        }
        
        return dummy->next; // Return the head of the modified list
    }
};
