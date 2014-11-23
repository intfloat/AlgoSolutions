import java.util.Scanner;


public class cf340A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long x, y, a, b;
		Scanner cin = new Scanner(System.in);
		x = cin.nextLong();
		y = cin.nextLong();
		a = cin.nextLong();
		b = cin.nextLong();
		long lcm = (x*y)/gcd(x, y);
		//System.out.println(lcm);
		long res = b/lcm - (a-1)/lcm;
		System.out.println(res);
		return;
	}
	
	/**
	 * 
	 * @param x
	 * @param y
	 * @return gcd of two long numbers
	 */
	public static long gcd(long x, long y){
		if(y == 0)
			return x;
		return gcd(y, x%y);
	}

}
