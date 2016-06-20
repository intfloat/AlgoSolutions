import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by BananaTree on 16-6-19.
 * email: intfloat@pku.edu.cn
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {

        private static final BigInteger MOD = new BigInteger("1000000007");

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            Scanner reader = new Scanner(System.in);
            while (reader.hasNext()) {
                int n = reader.nextInt();
                if (n % 2 == 1) {
                    System.out.println(0);
                    continue;
                }
                n /= 2;
                BigInteger res = BigInteger.ONE;
                for (int i = 2 * n; i > n + 1; --i) {
                    res = res.multiply(new BigInteger(String.valueOf(i)));
                }
                for (int i = 2; i <= n; ++i) {
                    res = res.divide(new BigInteger(String.valueOf(i)));
                }
                res = res.mod(MOD);
                System.out.println(res);
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

