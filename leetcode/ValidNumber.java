
public class Solution {
    
    public boolean isNumber(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
      s = s.trim();
        if(s.endsWith("f") || s.endsWith("D") || s.endsWith("H"))
            return false;
        try{
            float val = Float.valueOf(s);
        }
        catch(Exception e){
            return false;
        }
        return true;
    }    

}
