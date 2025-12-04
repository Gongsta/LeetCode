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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        int mid = n / 2;
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0;i < mid;i++) {
            prev = curr;
            curr = curr->next;
        }
        if (prev) {
            prev->next = curr->next;
        } else {
            head = nullptr;
        }
        curr->next = nullptr; // Remove links of node we are removing
        return head;
        
    }
};