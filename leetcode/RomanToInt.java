
// I didn't change any line of code and submit again, accepted this time...
public class RomanToInt {
  
    public static final int[] number = {1000, 500, 100, 50, 10, 5, 1};
    public static final char[] cha = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    public static final int[] special = {900, 400, 90, 40, 9, 4};
    public static final String[] pattern = {"CM", "CD", "XC", "XL", "IX", "IV"};
    
    public int romanToInt(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int res = 0;
        
        for(int i=0; i<pattern.length; i++){
            for(int j=0; j<s.length()-1; j++){
                if(pattern[i].equals(s.substring(j, j+2)) ){
                    s = s.substring(0, j)+s.substring(Math.min(s.length(), j+2));
                    j = -1;
                    res += special[i];
                }// end if clause
            }// end for loop
        }// end for loop
        
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<cha.length; j++){
                if(cha[j] == s.charAt(i)){
                    res += number[j];
                    break;
                }// end if clause
            }// end inner for loop
        }// end external for loop
        
        return res;
    }// end method
    
}// end class
