/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode prev,next,head;
        prev = new ListNode();
        head = new ListNode();
        if(l1==null){
            if(l2==null){head = null;}
            else{ head = l2; }
        }else{
            if(l2==null){ head=l1; }
            else{
                if(l1.val < l2.val) {
                    head.val = l1.val;
                    if(l1.next != null) l1 = l1.next;
                    else l1 = null;
                }else{
                    head.val = l2.val;  
                    if(l2.next != null) l2 = l2.next;
                    else l2 = null;
                } 
                prev = head;
                while(true){
                    if(l1 == null || l2 == null) break;
                    if(l1.val < l2.val){
                        next = new ListNode(l1.val);
                        prev.next = next;
                        prev = next;
                        if(l1.next != null){l1 = l1.next;}
                        else{l1=null; break;}
                    }else{
                        next = new ListNode(l2.val);
                        prev.next = next;
                        prev = next;
                        if(l2.next !=null){l2 = l2.next;}
                        else{l2=null; break;}
                    }
                }
                if(l1 != null) prev.next = l1;
                if(l2 != null) prev.next = l2;
            }
        }
        return head;
    }
}
