#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store nodes with their values
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // Initialize the min heap with the head of each list
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Extract nodes from the heap and build the result list
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            // Append the node to the result list
            current->next = node;
            current = current->next;

            // If the node has a next, push it into the heap
            if (node->next) {
                minHeap.push(node->next);
            }
        }

        // Return the merged sorted list
        return dummy->next;
    }
};
