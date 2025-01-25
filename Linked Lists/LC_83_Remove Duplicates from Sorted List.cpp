class Solution {
public:
    ListNode* deleteNode(ListNode* head, ListNode* temp) {
        if (temp == head) { 
            head = head->next;
            delete temp; 
            return head;
        }
        ListNode* prev = head;
        while (prev->next != temp) {
            prev = prev->next;
        }
        prev->next = temp->next;
        delete temp; 
        return head;
    }

    // Function to remove duplicates from a sorted list
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                head = deleteNode(head, temp->next);
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
