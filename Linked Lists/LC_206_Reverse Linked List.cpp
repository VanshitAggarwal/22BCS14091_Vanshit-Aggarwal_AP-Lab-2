class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;
        vector<int>data(1);
        while(temp!=NULL){
            data.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int size=data.size();
        int i=1;
        while(temp!=NULL){
            temp->val=data[size-i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};
