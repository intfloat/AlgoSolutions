/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode res = new ListNode(0);
      ListNode number1 = l1, number2 = l2;
//      to indicate current list node
        ListNode ptr = res;
//      to indicate carry value, 0 or 1
        int carry = 0;
        
        while(number1!=null || number2!=null || carry!=0){
//           two numbers
            if(number1!=null && number2!=null){
                ptr.val = (carry + number1.val + number2.val)%10;
                carry = (carry + number1.val + number2.val)/10;
                number1 = number1.next;
                number2 = number2.next;
            }
//          only one number
            else if(number1 != null){
                ptr.val = (carry + number1.val) % 10;
                carry = (carry + number1.val) / 10;
                number1 = number1.next;
            }
//          only number2 is null
            else if(number2 != null){
                ptr.val = (carry + number2.val) % 10;
                carry = (carry + number2.val) / 10;
                number2 = number2.next;
            }
//          only carry is non-zero value
            else{
                ptr.val = carry % 10;
                carry = carry / 10;
            }
            
//          create new list node
            if(number1!=null || number2!=null || carry!=0){
                ptr.next = new ListNode(0);
                ptr = ptr.next;
            }
        }// end while loop
        return res;
    }// end method addTwoNumbers
}// end class solution
