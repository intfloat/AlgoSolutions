
public class LongestPalindromicSubstring {
  
    public String res;
    public int maxi;
    
    public String longestPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = s.length();
        s = '@'+s+'$'; maxi = 0;
        
        for(int i=1; i<=len; i++){
//          expand around its center
            expand(i, i, s);
            expand(i, i+1, s);
        }
        return res;
    }// end method
    
    public void expand(int l, int r, String s){
        while(s.charAt(l) == s.charAt(r)){
            l--; r++;
        }
        l++; r--;
        if((r-l+1)>maxi){
            maxi = r-l+1;
            res = s.substring(l, r+1);
        }
        return;
    }// end expand
    
}// end class
