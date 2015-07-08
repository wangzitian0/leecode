/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int delta=0;
        ListNode ans=null,last=null;
        while(true)
        {
            if(l1!=null||l2!=null||delta>0)
            {
                if(l1!=null)
                {
                    delta+=l1.val;
                    l1=l1.next;
                }
                if(l2!=null)
                {
                    delta+=l2.val;
                    l2=l2.next;
                }
                ListNode p= new ListNode(delta%10);
                delta/=10;
                if(ans==null)ans=p;
                if(last!=null)last.next=p;
                last=p;
            }
            else break;
        }
        if(ans==null)ans= new ListNode(0);
        return ans;
    }
}
