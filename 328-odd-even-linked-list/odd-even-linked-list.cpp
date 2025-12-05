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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_head = head;
        if (!head) return nullptr;
        ListNode* even_head = head->next;

        ListNode* odd = odd_head;
        ListNode* even = even_head;
        while (odd && even && even->next) {
            ListNode* even_next = even->next;
            // Update next pointers
            odd->next = even_next;
            even->next = even->next->next;
            // Move current pointers to next
            odd = odd->next;
            even = even->next;
        }
        // Link odd numbers to even numbers
        odd->next = even_head;
        return head;
        
    }
};