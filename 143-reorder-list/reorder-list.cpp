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
    void reorderList(ListNode* head) {
        /*
        Get length of linked list.
        For nodes n/2 - n, push them to stack.
        Iterate through linked list and interleave the nodes.
        */
        stack<ListNode*> s;
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0;i<(n + 1)/2;i++) {
            curr = curr->next;
        }
        // Push curr to stack
        while (curr) {
            s.push(curr);
            curr = curr->next;
        }
        // Interleave
        curr = head;
        cout << s.size() << endl;
        while (curr && !s.empty()) {
            ListNode* next =  curr->next;
            ListNode* new_next = s.top();s.pop();
            curr->next = new_next;
            new_next->next = next;
            curr = next;
            if (s.empty() && curr) {
                curr->next = nullptr;
            }
        }
    }
};