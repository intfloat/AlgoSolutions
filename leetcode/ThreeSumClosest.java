import java.util.Arrays;


/**
 * 
 * @author Administrator
 * we can find nearest sum from 
 * less than target to more than target
 */
public class ThreeSumClose {
    
    public int threeSumClosest(int[] num, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
      int len = num.length;
        int minVal=-9999999, maxVal=9999999;
        
        Arrays.sort(num);
//      find closest value
        for(int i=0; i<num.length-2; i++){
            int left = i+1;
            int right = len-1;
            while(left < right){
                int sum = num[left]+num[right]+num[i]; 
                if(sum > target){
                    maxVal = Math.min(maxVal, sum);
                    right--;
                    continue;
                }
                else{
                    minVal = Math.max(minVal, sum);
                    left++;
                }
            }// end while loop
        }// end for loop        
        
        if(target-minVal < maxVal-target)
            return minVal;      
        return maxVal;
    }// end method
    
}// end class
