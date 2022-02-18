import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main_2477_참외밭_Silver4_백승훈 {

	private static boolean[] d;

	public static void main(String[] args) {
			
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		d = new boolean[5];
		Arrays.fill(d, false);
		for(int i=0; i<6; i++) {
			st = new StringTokenizer(br.readLine());
			int dir = Integer.parseInt(st.nextToken());
			int len = Integer.parseInt(st.nextToken());
			if(d[dir] == false) {
				System.out.println();
			}
		}
		
	
	} // end of main
}// end of class
