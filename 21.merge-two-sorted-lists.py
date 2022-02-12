# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        current_node = list1
        # We assume that they are sorted lists already
        while list2:
            if list2.val >= current_node.val:
                if (current_node.next):
                    current_node = nurrent_node.next
                else:
                    current_node.next = ListNode(list2.val)
                    list2 = list2.next

            else:
                




        
