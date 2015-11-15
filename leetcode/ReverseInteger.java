
/** Solution for reverse integer
 * 
 * @author Administrator
 *
 */
public class ReverseInteger {
    public long reverse(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        long res = 0;
        boolean negative = false;
//        x is negative number
        if(x<0){
          negative = true;
            x = Math.abs(x);
        }
        
        while(x != 0){
            res = res*10 + x%10;
            x = x/10;
        }// End while loop
        
        if(negative == true)
            res = -res;        
        return res;
    }// End method reverse
} // End class Solution
