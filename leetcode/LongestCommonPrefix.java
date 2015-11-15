import java.util.Arrays;


public class LongestCommonPrefix {
    
    public String longestCommonPrefix(String[] strs) {
        // Start typing your Java solution below
        // DO NOT write main() function      
        String result = "";
        if(strs==null || strs.length==0)
            return result;
        
//      possible longest common prefix 
        int maxLength = strs[0].length();
        for(String s:strs)
            maxLength = Math.min(maxLength, s.length());
        
        for(int i=0; i<maxLength; i++){
            int counter = 0;
            for(int j=0; j<strs.length; j++){
                if(strs[j].charAt(i)==strs[0].charAt(i))
                    counter++;
//              there is no need to compare further
                else
                    break;
            }
            Arrays.sort(strs);          
//          all strings have same characters at position i
            if(counter == strs.length)
                result += strs[0].charAt(i);
            else
                break;
        }
        return result;
        
    }// end method
}// end class
