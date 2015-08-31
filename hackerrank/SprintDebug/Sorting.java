import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

   public static int[] x;
    public static int n;

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        x = new int[n];
        int first = 0, last = 0;
        boolean fb = false, lb = false;
        for (int i = 0; i < n; i++) {
            x[i] = s.nextInt();
            if (!fb && i > 0 && (x[i] < x[i - 1])) {
                first = i;
                fb = true;
            }
        }
        while ((fb || first - 1 >= 0) && x[first] == x[first - 1]) {
            first++;
        }
        for (int i = n - 1; i > 0; i--) {
            if (x[i] < x[i - 1]) {
                last = i;
                break;
            }
        }
        while (fb && last + 1 < n && x[last] == x[last + 1]) {
            last++;
        }
        if (last == 0 && first == 0) {
            System.out.println("yes");
        } else {
            swap(first - 1, last);
            if (check()) {
                System.out.println("yes");
                System.out.println("swap " + (first) + " " + (last + 1));
            } else {
                swap(first - 1, last);
                int j = 0;
                for (int i = first - 1; i <= last && last - j > i; i++) {
                    swap(i, last - j);
                    j++;
                }
                if (check()) {
                    System.out.println("yes");
                    System.out.println("reverse " + first + " " + (last + 1));
                } else
                {
                    System.out.println("no");
                }
            }
        }
    }

    public static void swap(int i, int j) {
        int temp = x[i];
        x[i] = x[j];
        x[j] = temp;
    }

    public static boolean check() {
        for (int i = 1; i < n; i++) {
            if (x[i] < x[i - 1]) {
                return false;
            }
        }
        return true;
    }
}
