
// passed!! so many rules in Roman numerals
public class NumberToRoman {
  
    public static final int[] number = {1000, 500, 100, 50, 10, 5, 1};
    public static final char[] cha = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    
    public String intToRoman(int num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        String res = "";
        
        for(int i=0; i<cha.length; i++){
            if(i==1 && num>=900){
                res += "CM";
                num -= 900;
            }
            else if(i==2 && num>=400){
                res += "CD";
                num -= 400;
            }
            else if(i==3 && num>=90){
                res += "XC";
                num -= 90;
            }
            else if(i==4 && num>=40){
                res += "XL";
                num -= 40;
            }
            else if(i==5 && num>=9){
                res += "IX";
                num -= 9;
            }
            else if(i==6 && num>=4){
                res += "IV";
                num -= 4;
            }
            
            while(num >= number[i]){
                res += cha[i];
                num -= number[i];
            }// end inner while loop
        }// end for loop
        
        return res;
    }// end method    

}// end class
