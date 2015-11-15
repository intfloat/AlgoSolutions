import java.util.ArrayList;
import java.util.Arrays;


public class ThreeSum {


  public ArrayList<ArrayList<Integer>> threeSum(int[] num) {        
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();     
        Arrays.sort(num);
        
        for(int i=0; i<num.length; i++){
            int ptr1=i+1, ptr2=num.length-1;
            if(i>0 && num[i]==num[i-1])
                continue;
//          search from two sides
            while(ptr1 < ptr2){
//              smaller than 0
                if(num[i]+num[ptr1]+num[ptr2] < 0)
                    ptr1++;
//              larger than 0
                else if(num[i]+num[ptr1]+num[ptr2] > 0)
                    ptr2--;
//              equal to zero
                else{
                    ArrayList<Integer> element = new ArrayList<Integer>();
                    element.add(new Integer(num[i]));
                    element.add(new Integer(num[ptr1]));
                    element.add(new Integer(num[ptr2]));
//                  update results
                    result.add(element);
                    ptr1++; ptr2--;
                    while(ptr1<num.length && num[ptr1]==num[ptr1-1])
                        ptr1++;
                    while(ptr2>i && num[ptr2]==num[ptr2+1])
                        ptr2--;
                }
            }// end while loop
        }// end for loop
        return result;       
        
    }// end method
    
}// end class
