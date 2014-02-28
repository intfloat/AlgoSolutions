import java.util.Scanner;


public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = Integer.parseInt(cin.nextLine());
		String[] str = new String[101];
		int res = 0;
		for(int i=1; i<=t; i++){
			int n = Integer.parseInt(cin.nextLine());
			for(int j=0; j<n; j++)
				str[j] = cin.nextLine();
			res = 0;
			for(int j=1; j<n; j++){
				if(str[j].compareTo(str[j-1]) < 0){
					int k = j;
					res++;
					while(k>=1 && str[k].compareTo(str[k-1])<0){
						String tmp = str[k];
						str[k] = str[k-1];
						str[k-1] = tmp;
					}
				}// end if
			}// end for
			System.out.println("Case #"+i+": "+res);
		}// end for
	}

}
