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
public class Main_1592_영식이와친구들_B2_백승훈 {

	private static int N;
	private static int M;
	private static int L;
	private static int[] table;
	

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		
		table = new int[N];
		Arrays.fill(table, 0);
		
		int target = 0;
		int count = 0;
		table[target]++;
		while(true) {

//			System.out.println(target + " " + table[target]	);
			if(table[target] == M) break;
			if(table[target]%2 != 0) { // 홀수
				target = (target + L) % N;
			} else { // 짝수
				target = target -L;
				if(target < 0) target += N;
			}
			table[target]++;
			count++;
		}
		System.out.println(count);
	} // end of main
}// end of class
