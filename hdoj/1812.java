import java.math.BigInteger;
import java.util.Scanner;


public class HDOJ1812 {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            int N = cin.nextInt();
            int C = cin.nextInt();
            BigInteger result = BigInteger.ZERO;
            BigInteger color = new BigInteger(String.valueOf(C));
//          0 degree
            result = result.add(color.pow(N * N));
            if (N % 2 == 1) {
//              90 degree
                int tmp = (N * N - 1) / 4 + 1;
                result = result.add(color.pow(tmp));
//              180 degree
                tmp = (N * N - 1) / 2 + 1;
                result = result.add(color.pow(tmp));
//              270 degree
                tmp = (N * N - 1) / 4 + 1;
                result = result.add(color.pow(tmp));
//              reflect
                tmp = (N * N - N) / 2 + N;
                result = result.add(color.pow(tmp).multiply(new BigInteger("2")));
            }
            else {
//              90 degree
                result = result.add(color.pow(N * N / 4));
//              180 degree
                result = result.add(color.pow(N * N / 2));
//              270 degree
                result = result.add(color.pow(N * N / 4));
                result = result.add(color.pow(N * N / 2).multiply(new BigInteger("2")));
            }
//          diagonal reflect
            int tmp = (N * N - N) / 2 + N;
            result = result.add(color.pow(tmp).multiply(new BigInteger("2")));
            System.out.println(result.divide(new BigInteger("8")));
        }
        return;
    }

}
