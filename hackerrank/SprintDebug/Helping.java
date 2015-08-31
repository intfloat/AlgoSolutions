import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String ar[]) {
        Scanner in = new Scanner(System.in);

        int test = in.nextInt();
        if (test < 0 || test > 100) {
            System.out.println("0");
            return;
        }

        int totalContestants = 0;

        while (test != 0) {
            int n = in.nextInt();
            int[] arr = new int[n];

            if (n <= 100000 && n >= 0) {
                totalContestants += n;
            } else {
                System.out.println("0");
                test--;
                continue;
            }

            if (totalContestants > 1000000) {
                System.out.println("0");
                break;
            }

            while (n != 0) {
                arr[n - 1] = in.nextInt();
                n--;
            }

            System.out.println(getMinPersonsInTeam(arr));

            test--;
        }
    }

    private static int getMinPersonsInTeam(int[] arr) {
        int minNumInTeam = 0;

        Arrays.sort(arr);

        Map<Integer, LinkedList<Integer>> map1 = new HashMap<Integer, LinkedList<Integer>>();
        for (int i = 0; i < arr.length; i++) {
            if (map1.containsKey(arr[i] - 1)) {
                LinkedList<Integer> list = map1.get(arr[i] - 1);
                int count = 1;

                while (i + 1 < arr.length && arr[i + 1] == arr[i]) {
                    count++;
                    i++;
                }

                LinkedList<Integer> list1 = new LinkedList<Integer>();

                while (count > 0 && list.size() > 0) {
                    int val = list.pop();

                    if (list1.isEmpty()) {
                        list1.push(val + 1);
                    } else if (list1.peek() < val + 1) {
                        list1.addLast(val + 1);
                    } else {
                        list1.push(val + 1);
                    }

                    count--;
                }

                while (count != 0) {
                    list1.push(1);
                    count--;
                }

                map1.put(arr[i], list1);

                if (list.isEmpty()) {
                    map1.remove(arr[i] - 1);
                }
            } else {
                LinkedList<Integer> list = new LinkedList<Integer>();
                list.add(1);

                while (i < arr.length-1 && arr[i + 1] == arr[i]) {
                    list.add(1);
                    i++;
                }

                map1.put(arr[i], list);
            }
        }

        boolean start = true;
        Set<Integer> keys = map1.keySet();
        for(Integer in : keys) {
            if (start) {
                minNumInTeam = map1.get(in).peek();
                start = false;
            }

            int val = map1.get(in).peek();
            if (minNumInTeam > val) {
                minNumInTeam = val;
            }
        }

        return minNumInTeam;
    }
}
