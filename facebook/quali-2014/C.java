import java.text.DecimalFormat;
import java.util.Scanner;


public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		double[][][][] dp = new double[205][110][1005][2];
		for(int tt=1; tt<=t; tt++){
//			initialization
			int K = cin.nextInt();
			for(int i=0; i<2*K+1; i++)
				for(int j=0; j<K+5; j++)
					for(int k=0; k<dp[i][j].length; k++)
						for(int kk=0; kk<dp[i][j][k].length; kk++)
							dp[i][j][k][kk] = 0;
						
			double ps = cin.nextDouble();
			double pr = cin.nextDouble();
			double oripi = cin.nextDouble();
			int pimul = (int) Math.round(oripi*1000);
			double pu = cin.nextDouble();
			int pumul = (int) Math.round(pu*1000);
			double pw = cin.nextDouble();
			double pd = cin.nextDouble();
			int pdmul = (int) Math.round(pd*1000);
			double pI = cin.nextDouble();
//			int pImul = (int) Math.round(pI*1000);
			dp[1][1][pimul][1] = oripi*ps+(1.0-oripi)*pr;
			dp[1][0][pimul][0] = oripi*(1.0-ps)+(1.0-oripi)*(1.0-pr);
			for(int i=2; i<=2*K-1; i++){
				int upper = Math.min(K, i);
				for(int j=0; j<=upper; j++){
					if((i-1-j) >= K) continue;
					for(int pp=0; pp<=1000; pp++){
						if(j > 0)
							dp[i][j][pp][1] = dp[i-1][j-1][pp][1]*(1.0-pw)
								+dp[i-1][j-1][pp][0]*(1.0-pI);
						dp[i][j][pp][0] = dp[i-1][j][pp][1]*(1.0-pw)
								+dp[i-1][j][pp][0]*(1.0-pI);
						if(pp==0){
							for(int tmp=0; tmp<=pdmul; tmp++){
								dp[i][j][pp][0] += dp[i-1][j][pp+tmp][0]*pI;
								if(j > 0)
									dp[i][j][pp][1] += dp[i-1][j-1][pp+tmp][0]*pI;
							}
						}
						if(pp==1000){
							for(int tmp=0; tmp<=pumul; tmp++){
								dp[i][j][pp][0] += dp[i-1][j][pp-tmp][1]*pw;
								if(j > 0)
									dp[i][j][pp][1] += dp[i-1][j-1][pp-tmp][1]*pw;
							}
						}
						if(pp-pumul>=0 && pp!=0 && pp!=1000){
							if(j > 0)
								dp[i][j][pp][1] += dp[i-1][j-1][pp-pumul][1]*pw;
							dp[i][j][pp][0] += dp[i-1][j][pp-pumul][1]*pw;
						}
						if(pp+pdmul<=1000 && pp!=0 && pp!=1000){
							if(j > 0)
								dp[i][j][pp][1] += dp[i-1][j-1][pp+pdmul][0]*pI;
							dp[i][j][pp][0] += dp[i-1][j][pp+pdmul][0]*pI;
						}						
						double oopi = (double)pp/1000.0;
						dp[i][j][pp][1] *= oopi*ps+(1.0-oopi)*pr;
						dp[i][j][pp][0] *= oopi*(1.0-ps)+(1.0-oopi)*(1.0-pr);
					}// end pp loop
				}// end j loop
			}// end i loop
			double res = 0;
			for(int i=K; i<=2*K-1; i++){
				for(int pp=0; pp<=1000; pp++){
					res += dp[i][K][pp][1];
				}
			}
			DecimalFormat df = new DecimalFormat("0.000000");
			System.out.println("Case #"+tt+": "+df.format(res));
		}
	}// end main method

}
