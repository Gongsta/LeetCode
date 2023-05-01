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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        if (length == 0 || length == 1) {
            return head;
        }
        
        k = k % length;
        
        curr = head;
        int count = length - k;
        
        // Close the list
        for (int i=0;i<length;i++) {
            if (curr->next == nullptr) {
                curr->next = head;
                break;
            } else {
                curr = curr->next;
            }
        }
        
        curr = head;
        
        
        ListNode* new_head;
        ListNode* new_tail;
        
        // Remove the connection
        
        while (count--) {
            if (count == 0) {
                new_head = curr->next;
                curr->next = nullptr;
                
            } else {
                curr = curr->next;
            }
        }
        return new_head;
        
        
    }
};