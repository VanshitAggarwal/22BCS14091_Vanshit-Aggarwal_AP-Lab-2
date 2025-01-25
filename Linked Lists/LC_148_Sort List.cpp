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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Split the list into two halves
        ListNode* mid = getMiddle(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge the two sorted halves
        return merge(left, right);
    }

private:
    // Function to find the middle of the linked list
    ListNode* getMiddle(ListNode* head) {
        if (!head) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr; // Break the list into two halves
        return mid;
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        
        if (left) current->next = left;
        if (right) current->next = right;
        
        return dummy->next;
    }
};
