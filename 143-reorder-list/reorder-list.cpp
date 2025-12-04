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
        Reverse nodes n/2 - n
        Iterate through linked list and interleave the nodes.
        */

        // Find midpoint
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse nodes from slow till the end
        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* new_midpoint = prev;
        curr = head;
        // Interleave between head and new_midpoints
        while (new_midpoint) {
            ListNode* next = curr->next;
            ListNode* new_midpoint_next = new_midpoint->next;
            curr->next = new_midpoint;
            new_midpoint->next = next;
            new_midpoint = new_midpoint_next;
            curr = next;
        }
    }
};