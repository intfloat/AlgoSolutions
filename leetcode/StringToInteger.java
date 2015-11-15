
// so many boundary conditions ><
public class StringToInteger {
  
    public long int_max = 2147483647L;
    public long int_min = -2147483648L;
    
    public long atoi(String str) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(str==null || str.length()==0) return 0;
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) != ' '){
                str = str.substring(i);
                break;
            }
//          all characters are spaces
            if(i==str.length()-1 && str.charAt(i)==' ')
                return 0;
        }// end for loop
        
        long res = 0;
//      check if the number is negative
        boolean negative = (str.charAt(0)=='-');
        if(negative==true || str.charAt(0)=='+')
            str = str.substring(1);
        
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i)>='0' && str.charAt(i)<='9')
                res = res*10 + str.charAt(i)-'0';
//          invalid characters
            else
                break;
            if(negative==false && res>int_max)
                return int_max;
            if(negative==true && -res<int_min)
                return int_min;
        }
        
        if(negative == false)
            return res;
        else
            return -res;
    }// end method
    
}// end class
