
public class Solution {
    public int lengthOfLastWord(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(s==null || s.length()==0)
        return 0;
        
        s = s.trim();
        if(s.length() == 0)
            return 0;
        
        String[] str = s.split(" ");
        return str[str.length-1].length();
    }
}
