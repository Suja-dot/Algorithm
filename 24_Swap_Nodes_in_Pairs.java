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
    public ListNode swapPairs(ListNode head) {
        ListNode first = new ListNode();
        ListNode second = new ListNode();
        
        if(head == null) return null;
        
        first = head;
        second = first.next;
        if(second != null) head = second;
        else head = first;
        while(true){
            if(first == null) break;
            ListNode prev_line = new ListNode();
            if(second != null) prev_line = second.next;
            else break;
            
            if(second.next != null && second.next.next != null) first.next = second.next.next;
            else first.next = second.next;
            second.next = first;
            
            if(prev_line != null) first = prev_line;
            else first = null;
            if(first!=null) second = first.next;            
            else second = null;
        }
        return head;
    }
}
