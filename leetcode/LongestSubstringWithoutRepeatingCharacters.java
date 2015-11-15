import java.util.Arrays;


public class  LongestSubstringWithoutRepeatingCharacters{
    public int lengthOfLongestSubstring(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
      
//      case of empty string
        if(s==null || s.isEmpty()==true)
            return 0;
        
        int len = s.length();
        int res = 1;
        int start = 0, cur = 1;
        int position[] = new int[300];
        Arrays.fill(position, -1);
        position[s.charAt(0)] = 0;
        
//      loop and find corresponding result
        while(cur < len){
//          s[cur] has not occurred
            if(position[s.charAt(cur)] < start){
                res = Math.max(cur-start+1, res);
                position[s.charAt(cur)] = cur;
            }
//          s[cur] has occurred in previous substring
            else{
                start = position[s.charAt(cur)] + 1;
                res = Math.max(res, cur-start+1);
                position[s.charAt(cur)] = cur;
            }
            cur++;
        }// End while loop
        return res;
    }// End method lengthOfLongestSubstring
    
} // End class Solution
