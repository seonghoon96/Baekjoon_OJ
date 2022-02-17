import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * 1은 켜져있음, 0 꺼져있음
 * 남학생 : 스위치번호가 받은수의 배수, 스위치의 상태 변경
 * 여학생 : 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우가 대칭이면서 
 * 가장 많은 스위치를 포함하는 구간을 찾아서 그 구간에 스위치 상태를 모두 변경
 */
public class Main_2309_일곱난쟁이_Bronze2_백승훈 {


	private static int[] input;
	private static boolean[] visit;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String str;
		input = new int[9];
		visit = new boolean[9];
		Arrays.fill(visit, false);
		int index = 0;
		for(int i=0; i<9; i++) {
			input[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(input);
		combination(0, 0, 0);
	} // end of main

	private static void combination(int cnt, int start, int sum) {

		if(cnt == 7) {
//			System.out.println(sum);
			if(sum == 100) {
				for(int i=0; i<input.length; i++) {
					if(visit[i]) System.out.println(input[i]);
				}
				System.exit(0);				
			}
			return;
		}
		for(int i=start; i<9; i++) {
			visit[i] = true;
			combination(cnt+1, i+1, sum+input[i]);
			visit[i] = false;
		}
	}
}// end of class
