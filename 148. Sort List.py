# just a merge sort
#

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        fast = head
        slow = head
        slowPre = None
        while fast != None:
            slowPre = slow
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next
        slowPre.next = None
        # slow is head2, head is head1
        head = self.sortList(head)
        slow = self.sortList(slow)
        # merge
        newHead = None
        newTail = None
        while head and slow:
            if head.val < slow.val:
                if newTail:
                    newTail.next = head
                else:
                    newHead = head
                newTail = head
                head = head.next
            else:
                if newTail:
                    newTail.next = slow
                else:
                    newHead = slow
                newTail = slow
                slow = slow.next
            newTail.next = None
        if head:
            newTail.next = head
        else:
            newTail.next = slow
        return newHead

