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
    ListNode* sortList(ListNode* head) {
        
        int n = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }
        return divideAndConquerSort(head, n);
    }
    ListNode* divideAndConquerSort(ListNode* node, int n) {
        if (n == 0 || n == 1) return node;
        ListNode* mid = node;
        for (int i=0;i<n/2;i++) {
            if (i == n/2 - 1) {
                ListNode* temp = mid;
                mid = mid->next;
                temp->next = nullptr;  // break up link
            } else {
                mid = mid->next;
            }
        }

        ListNode* head = divideAndConquerSort(node, n/2);
        if (n % 2 == 0){
            mid = divideAndConquerSort(mid, n/2);
        } else {
            mid = divideAndConquerSort(mid, n/2+1);
        }
        return merge(head, mid);
    }
    ListNode* merge(ListNode* head, ListNode* mid) {
        // Head and mid are both sorted
        ListNode* curr;
        if (head->val <= mid->val) {
            curr = head;
            head = head->next;
        } else {
            curr = mid;
            mid = mid->next;
        }
        ListNode* currHead = curr;
        while (head != nullptr || mid != nullptr) {
            if (head == nullptr) {
                curr->next = mid;
                mid = mid->next;
            } else if (mid == nullptr) {
                curr->next = head;
                head = head->next;
            } else {
                if (head->val <= mid->val) {
                    curr->next = head;
                    head = head->next;
                } else {
                    curr->next = mid;
                    mid = mid->next;
                }
            }
            curr = curr->next;
        }
        return currHead;
    }
};