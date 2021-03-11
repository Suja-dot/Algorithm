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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode tail = head;
        int cnt = 1;
        // check total length
        while(tail.next != null) {
            tail = tail.next;
            cnt++;
        }
        //remove node when firt node
        if(cnt == n){
            head = head.next;
        }else{
            //remove node in middle or last
            tail = head;
            for(int i=0;i<cnt-n-1;i++){
                tail = tail.next;
            }
            System.out.println("Current Node "+tail.val);
            if(tail.next!=null) tail.next = tail.next.next;
            else tail = null;
        }
        return head;
    }
}
