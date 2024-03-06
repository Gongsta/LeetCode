/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        bool has_cycle = false;
        while (head != nullptr) {
            if (s.count(head)) {
                has_cycle = true;
                break;
            }
            s.insert(head);
            head = head->next;
        }
        return has_cycle;
        
    }
};