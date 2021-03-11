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
        ListNode ans = new ListNode();
        ListNode prev = new ListNode();
        int pos1, pos2;
        int sum, upper;
        ArrayList<Integer> num1 = new ArrayList<Integer>();
        ArrayList<Integer> num2 = new ArrayList<Integer>();
        ArrayList<Integer> totalNum = new ArrayList<Integer>();
        while(l1!=null){ num1.add(l1.val); l1 = l1.next; }
        while(l2!=null){ num2.add(l2.val); l2 = l2.next; }
        pos1 = num1.size()-1;
        pos2 = num2.size()-1;
        sum = upper = 0;
        for(int i=0;i<Math.min(num1.size(),num2.size());i++){
            sum = num1.get(pos1--) + num2.get(pos2--) + upper;
            upper = sum/10;
            sum %= 10;
            totalNum.add(sum);
        }
        if(num1.size() > num2.size()){
            while(pos1 >= 0){
                sum = num1.get(pos1--) + upper;
                upper = sum/10;
                sum%=10;
                totalNum.add(sum);
            }
        }else if(num1.size() < num2.size()){
            while(pos2 >= 0){
                sum = num2.get(pos2--) + upper;
                upper = sum/10;
                sum%=10;
                totalNum.add(sum);
            }
        }
        while(upper > 0){
            totalNum.add(upper%10);
            upper/=10;
        }
        ans.val = totalNum.get(totalNum.size()-1);
        prev = ans;
        for(int i=totalNum.size()-2;i>=0;i--){
            ListNode next = new ListNode(totalNum.get(i));
            prev.next = next;
            prev = prev.next;
        }
        //Create ans ListNode
        return ans;
    }
}
