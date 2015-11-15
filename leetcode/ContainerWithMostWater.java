
// use two pointers, excellent problem
public class ContainerWithMostWater {
  
    public int maxArea(int[] height) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int res = 0;
        int left=0, right=height.length-1;
        
//      move into middle
        while(left < right){
            int tmp = Math.min(height[left], height[right]);
            res = Math.max(res, (right-left)*tmp );
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }// end method
    
}// end class
