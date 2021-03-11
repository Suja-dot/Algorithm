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
    public int minimumVal(ListNode[] lists){
        int res = 0;
        while(res<lists.length && lists[res] == null) {
            res++;
        }
        for(int i=res+1; i<lists.length; i++){
            if(lists[i]!=null && lists[res].val > lists[i].val) res = i;
        }
        return res;
    }
    
    public ListNode mergeKLists(ListNode[] lists) {
        int min_index;
        ListNode head = new ListNode();
        ListNode prev = new ListNode();
        min_index = minimumVal(lists);
        if(min_index >= lists.length) return null;
        head = lists[min_index];
        prev = head;
        //System.out.println("Add Head : "+head.val);
        
        if(lists[min_index].next != null) lists[min_index] = lists[min_index].next;
        else lists[min_index] = null;
        
        while(true){
            min_index = minimumVal(lists);
            if(min_index == lists.length) break;
            prev.next = lists[min_index];
            prev = prev.next;
            //System.out.println("Add node : "+prev.val);
            if(lists[min_index].next != null) lists[min_index] = lists[min_index].next;
            else lists[min_index] = null;
        }
        return head;
    }
}
