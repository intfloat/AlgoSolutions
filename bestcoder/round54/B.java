import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.nextInt();
            for (int tt = 0; tt < T; ++tt) {
                int N = in.nextInt();
                BigInteger[] arr = new BigInteger[N];
                int zero = 0;
                for (int i = 0; i < N; ++i) {
                    arr[i] = new BigInteger(in.next());
                    if (arr[i].equals(BigInteger.ZERO)) ++zero;
                }
                if (zero == N) {
                    out.println("Yes");
                    continue;
                }
                else if (zero > 0) {
                    out.println("No");
                    continue;
                }
                boolean ok = true;
                for (int i = 1; i <= N - 2; ++i) {
                    BigInteger a = arr[i - 1].multiply(arr[i + 1]);
                    BigInteger b = arr[i].multiply(arr[i]);
                    if (!a.equals(b)) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) out.println("No");
                else out.println("Yes");
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