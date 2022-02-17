import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_BOJ_2961_도영이가만든맛있는음식_Silver1_백승훈_76ms {

	private static int n;
	private static int[][] menu;
	private static int result;
	private static boolean[] visited;
	/**
	 * 원소가 최소 1개는 들어가야하고
	 * 부분집합을 구하면서 신맛과 단맛계산
	 * 
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		n = Integer.parseInt(br.readLine());
		result = Integer.MAX_VALUE;
		visited = new boolean[n];
		menu = new int[n][2];
		
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			menu[i][0] = Integer.parseInt(st.nextToken());
			menu[i][1] = Integer.parseInt(st.nextToken());
		}
		subset(0,1,0);
		System.out.println(result);
		
	} // end of main

	public static void subset(int cnt, int mul, int sum) {
		if(cnt == n) {
			if(sum != 0) result = Math.min(result, Math.abs(mul-sum));
			return;
		}
		subset(cnt+1, mul*menu[cnt][0], sum+menu[cnt][1]);
		subset(cnt+1, mul, sum);
	}
	

} // end of class
