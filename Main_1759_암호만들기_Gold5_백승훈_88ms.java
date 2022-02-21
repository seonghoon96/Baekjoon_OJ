import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_1759_암호만들기_Gold5_백승훈_88ms {

	private static int L;
	private static int C;
	private static char[] ch;
	private static StringBuilder sb;

	/*
	 * 서로다른 L개의 알파벳 소문자로 구성
	 * 최소 한개의 모음(aeiou)와 최소 2개의 자음으로 구성
	 * 증가하는 순서로 배열
	 * 
	 * 아이디어 : 
	 * 입력되는 문자를 자음 모음 구분 (x) => 조합을 만들면서 확인
	 * 입력받은 문자를 정렬 후 조합 시작 => 사전순 출력을 위해( 그리디한 접근..? )
	 * 앞에서부터 뒤로가며 조합을 생성
	 * 증가하는 순서가 흐트러지면 백트래킹
	 * 최종적으로 길이가 L이 되었을 때 조건에 맞는지 체크
	 * 
	 * 
	 */
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		sb = new StringBuilder();
		L =Integer.parseInt(st.nextToken());
		C =Integer.parseInt(st.nextToken());
		ch = new char[C];
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=0; i<C; i++) ch[i] = st.nextToken().charAt(0);

		Arrays.sort(ch);		// 정렬 해놓고 시작 => 그리디한 접근
		combination(0,0,"");
		System.out.println(sb);
		
		
		
		
		
		
		
	} // end of main
	
	
	/**조합에 사용할 변수, 현재까지 만들어진 암호문 */
	public static void combination(int cnt, int start, String numbers) {
		if(cnt==L) { 	// 길이가 L일 경우
			int check1 = 0, check2 = 0;				// check1 : 모음, check2 : 자음 체크
			
			// 완성된 numbers문자열을 처음부터 다 탐색
			for(int i=0; i<numbers.length(); i++) {
				if(numbers.charAt(i)=='a' || numbers.charAt(i)=='e'|| numbers.charAt(i)=='i'|| numbers.charAt(i)=='o' || numbers.charAt(i)=='u' )
					check1++;
				else check2++;
			}
			
			if(check1 >=1 && check2 >=2)			// 암호 기준 통과 
				sb.append(numbers).append("\n");	// string builder로 이어붙임
			
			return;
		}
		for(int i=start; i<C; i++) {
			// 처음 입력이 아니고, 문자가 증가하는 순서인 경우
			if(numbers.length()>0 && numbers.charAt(numbers.length()-1) < ch[i]) {
				combination(cnt+1, i+1, numbers+ch[i]);
			// 처음 문자입력을 받았을 때 
			} else if(numbers.length() == 0) {
				combination(cnt+1, i+1, numbers+ch[i]);				
			// 위에 모두 해당 안되면 탈출
			} else {
				break;
			}
		}
	}
	
	
	
} // end of class
