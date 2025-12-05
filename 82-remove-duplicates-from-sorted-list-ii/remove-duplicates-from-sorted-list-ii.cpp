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
        /*
        keep track of duplicate nodes, store the next node that they point to that is not duplicate.

        Watch out for edge case when head is duplicate
        */
        if (!head) return nullptr;
        map<int, ListNode*> duplicate_to_next;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            if (prev && curr->val == prev->val) {
                duplicate_to_next[curr->val] = curr->next;
            }
            prev = curr;
            curr = curr->next;
        }
        // Edge case for head
        while (head && duplicate_to_next.count(head->val)) {
            head = duplicate_to_next[head->val];
        }

        curr = head;
        // Curr is a non duplicate
        while (curr) {
            if (curr->next && duplicate_to_next.count(curr->next->val)) {
                ListNode* next_non_duplicate = duplicate_to_next[curr->next->val];
                // Go through pointers
                while (next_non_duplicate && duplicate_to_next.count(next_non_duplicate->val)) {
                    next_non_duplicate = duplicate_to_next[next_non_duplicate->val];
                }
                curr->next = next_non_duplicate;
            }
            curr= curr->next;
        }
        return head;
        
    }
};