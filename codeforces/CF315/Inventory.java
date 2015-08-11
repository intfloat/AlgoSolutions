import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;

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
            int n = in.nextInt();
            boolean[] ok = new boolean[n + 1];
            TreeSet<Integer> set = new TreeSet<Integer>();
            int[] arr = new int[n + 1];
            for (int i = 0; i < n; ++i) {
                set.add(i + 1);
            }
            for (int i = 0; i < n; ++i) {
                arr[i + 1] = in.nextInt();
            }
            for (int i = 1; i <= n; ++i) {
                if (set.contains(arr[i])) {
                    set.remove(arr[i]);
                    ok[i] = true;
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (ok[i]) {
                    out.print(arr[i] + " ");
                }
                else {
                    out.print(set.pollFirst() + " ");
                }
            }
            out.println();
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