/*
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void printList(Node* head) {
        Node* current = head;
        bool isFirst = true;
        while (current != nullptr) {
            if (!isFirst) {
                cout << " ";
            }
            cout << current->data;
            isFirst = false;
            current = current->next;
        }
        cout << endl;
    }
};
