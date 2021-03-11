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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode prev_node,current_node;
        prev_node = new ListNode();
        current_node = head;
        while(true){
            if(current_node == null) break;
            if(prev_node.next == null){
                prev_node = current_node;
                current_node = current_node.next;
                continue;
            }else{
                if(prev_node.val == current_node.val){
                    prev_node.next = current_node.next;
                    current_node = current_node.next;
                }else{
                    prev_node = current_node;
                    current_node = current_node.next;
                }
            }
        }
        return head;
    }
}
