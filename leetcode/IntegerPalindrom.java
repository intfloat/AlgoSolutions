
public class IntegerPalindrom {
  
    public boolean isPalindrome(int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(x < 0)
            return false;       
        String str1 = String.valueOf(x);
        String str2 = "";
        for(int i=str1.length()-1; i>=0; i--)
            str2 += str1.charAt(i);
//      pretty easy to implement
        return str1.equals(str2);
    }// end method
    
}// end class
