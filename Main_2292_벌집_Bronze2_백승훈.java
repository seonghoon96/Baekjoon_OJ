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
public class Main_2292_벌집_Bronze2_백승훈 {


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int value = 1;
		int index = 1;
		while(value < N) {
			value += 6*index++;
		}
		System.out.println(index);
	} // end of main
}// end of class
