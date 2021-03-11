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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int upper_data = 0, sum = 0, flag = 1;
        ListNode head = new ListNode();
        ListNode current_node = new ListNode();
        
        while(true){
            //[Step1] Calculate Sum
            if(l1 == null) sum = l2.val + upper_data;
            else if(l2 == null) sum = l1.val + upper_data;
            else sum = l1.val + l2.val + upper_data;
            upper_data = sum/10;
            sum %= 10;
            
            //[Step2] Save value in ListNode
            current_node.val = sum;
            current_node.next = new ListNode();
            
            //[Cond1] Receive Header for Return
            if(flag == 1) {
                head = current_node;
                flag = 0;
            }
            
            //[Step3] Check next value
            if(l1 == null){
                if(l2.next==null) break;
                else l2 = l2.next;
            }
            else if(l2 == null){
                if(l1.next==null) break;
                else l1 = l1.next;
            }
            else if(l1.next == null && l2.next == null) break;
            else{
                l1 = l1.next;
                l2 = l2.next;
            }
            current_node = current_node.next;
        }
        
        //[Step4] Check Remain value
        if(upper_data > 0) current_node.next.val = upper_data%10;
        else current_node.next = null;
        
        return head;
    }
}
