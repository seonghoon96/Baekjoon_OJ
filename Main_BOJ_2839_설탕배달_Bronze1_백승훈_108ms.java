import java.util.Scanner;

public class Main_BOJ_2839_설탕배달_Bronze1_백승훈_108ms	 {

	/**
	 * 설탕 배달을 해야하는데 봉지가 3, 5키로
	 * 최대한 적은 봉지
	 * 그리디 방식으로 접근
	 * 
	 * 5키로 봉지 먼저 포함시키고, 3키로 나머지
	 * 정확하게 N키로그램만 배달해야 하므로
	 */
	
	
	
	public static void main(String[] args) {
		
		Solution2();
		
	}
	
	/** 
	 * 일반적인 방법
	 * 수식으로 접근해서 그리디 방식으로 풀이
	 * 5a + 3b = N 을 만족해야함
	 *  
	 */
	public static void Solution1(){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int a=0, b=0;
		for (a=N/5; a>=0; a--) {
			if((N-5*a)%3 == 0) {
				b = (N - 5 * a) / 3;
				break;
			}
		}
		
		System.out.println(a+b);		
	}
	
	
	
	public static void Solution2(){
		
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] dp = new int[N+1];
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = 0;
		dp[3] = 1;
		dp[4] = 0;
		dp[5] = 1;
		for(int i=6; i<=N; i++){
			if(dp[i-5] != 0) dp[i] = dp[i-5]+1;
			else if(dp[i-3] != 0) dp[i] = dp[i-3]+1;
			else dp[i] = 0;
//			dp[i] = Math.min( dp[i-5]+1,dp[i-3]+1);
		}
		if(dp[N] == 0) System.out.println(-1);
		else System.out.println(dp[N]);		
	}

}
