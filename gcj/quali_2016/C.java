import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Count {
    private static int n;
    private static BigInteger get(long cur, int base) {
        BigInteger ret = BigInteger.ZERO;
        BigInteger b = new BigInteger(String.valueOf(base));
        for (int i = n - 1; i >= 0; --i) {
            ret = ret.multiply(b);
            if ((cur & (1L << i)) != 0) ret = ret.add(BigInteger.ONE);
        }
        return ret;
    }
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        n = reader.nextInt();
        int tot = reader.nextInt();
        ArrayList<Long> res = new ArrayList<Long>();
        for (long i = 0; i < (1 << (n - 2)); ++i) {
            boolean ok = true;
            long val = (1L << (n - 1)) + (i << 1) + 1L;
            for (int j = 2; j <= 10; ++j) {
                BigInteger tmp = get(val, j);
                if (tmp.isProbablePrime(50)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res.add(val);
                //System.out.println("Found: " + val);
                if (res.size() == tot * 3) {
                    break;
                }
            }
        }
        int max_try = 100000;
        int have = 0;
        for (int i = 0; i < res.size(); ++i) {
            long rr = res.get(i);
            boolean ok = true;
            ArrayList<BigInteger> factors = new ArrayList<BigInteger>();
            for (int j = 2; j <= 10; ++j) {
                BigInteger tmp = get(rr, j);
                long cnt = 0;
                for (BigInteger d = new BigInteger("2"); cnt < max_try; d = d.add(BigInteger.ONE)) {
                    if (tmp.mod(d).equals(BigInteger.ZERO)) {
                        factors.add(d);
                        break;
                    }
                    ++cnt;
                }
                if (cnt >= max_try) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                System.out.print(Long.toUnsignedString(rr, 2));
                for (int j = 0; j < factors.size(); ++j) {
                    System.out.print(" " + factors.get(j));
                }
                System.out.println();
                ++have;
                if (have == tot) {
                    break;
                }
            }
        }
        reader.close();
    }
}
