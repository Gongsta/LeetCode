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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (ListNode* node: lists) {
            if (!node) continue;
            pq.push({node->val, node});
        }
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        while (!pq.empty()) {
            // pop value and push next value
            auto [val, node] = pq.top();pq.pop();
            if (node->next) {
                pq.push({node->next->val, node->next});
            }

            // Update pointers
            if (curr == nullptr) {
                curr = node;
                head = curr;
            } else {
                curr->next = node;
                curr = curr->next;
            }
        }

        return head;
         
    }
};