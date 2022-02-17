import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * 1은 켜져있음, 0 꺼져있음
 * 남학생 : 스위치번호가 받은수의 배수, 스위치의 상태 변경
 * 여학생 : 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우가 대칭이면서 
 * 가장 많은 스위치를 포함하는 구간을 찾아서 그 구간에 스위치 상태를 모두 변경
 */
public class Main_1244_스위치켜고끄기_Silver3_백승훈_76ms {

	private static int N;
	private static boolean[] switches;
	private static int tc;
	private static int[] sw;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		sw = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=N; i++) {
			sw[i] =  Integer.parseInt(st.nextToken());
		}
			
		tc = Integer.parseInt(br.readLine());
		for(int test = 0; test<tc; test++) {
			st = new StringTokenizer(br.readLine(), " ");
			int gender = Integer.parseInt(st.nextToken());
			int number = Integer.parseInt(st.nextToken());
			int index = number;
			if(gender == 1) { // 남학생
				
				for(int i=number; i<=N; i+=number)
					sw[i] = sw[i]^1;
				
			} else { // 여학생의 경우
				sw[number] = sw[number]^1;
				int len = 1;
				while(0<index-len && index+len<=N) {
					if(sw[index-len] == sw[index+len]) {
						sw[index-len] = sw[index-len]^1;
						sw[index+len] = sw[index+len]^1;
						len++;
					} else break;
				}
				
			}
		}
		
		int index = 1;
		StringBuilder sb = new StringBuilder();
		while(index <=N) {
			sb.append(sw[index]).append(" ");
			if(index%20 == 0) sb.append("\n");
			index++;
		}
		
		System.out.println(sb);
	} // end of main
}// end of class
