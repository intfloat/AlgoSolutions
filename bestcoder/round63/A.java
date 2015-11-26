import java.math.BigInteger;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        while (reader.hasNextInt()) {
            int n = reader.nextInt();
            int k = reader.nextInt();
            BigInteger[][] dp = new BigInteger[n][k + 1];
            BigInteger[] num = new BigInteger[n];
            for (int i = 0; i < n; ++i) {
                num[i] = new BigInteger(reader.next());
            }
            for (int i = 0; i < n; ++i) {
                dp[i][1] = BigInteger.ONE;
                for (int j = 2; j <= k; ++j) {
                    dp[i][j] = BigInteger.ZERO;
                    for (int p = i - 1; p >= 0; --p) {
                        if (num[p].compareTo(num[i]) < 0) {
                            dp[i][j] = dp[i][j].add(dp[p][j - 1]);
                        }
                    }
                }
            }
            BigInteger res = BigInteger.ZERO;
            for (int i = 0; i < n; ++i) {
                res = res.add(dp[i][k]);
            }
            System.out.println(res.toString());
        }
        reader.close();
    }
}
