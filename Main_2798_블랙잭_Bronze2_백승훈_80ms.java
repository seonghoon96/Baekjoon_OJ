import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2798_블랙잭_Bronze2_백승훈_80ms {

	private static int N;
	private static int[] cards;
	private static int M;

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		cards = new int[N];
		result = 0;
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			cards[i] = Integer.parseInt(st.nextToken());
		}
		combination(0, 0, 0);
		System.out.println(result);
	}// end of main

	private static int result;
	
	public static void combination(int cnt, int start, int sum){
		if(cnt == 3) {
			if(sum <= M) {
				result = Math.max(result, sum);
				return;
			}
		} else {
			for(int i=start; i<N; i++) {
				combination(cnt+1, i+1, sum + cards[i]);
			}
		}
	}
	
	
}// end of class
