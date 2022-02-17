import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main_BOJ_1074_Z_Silver1_백승훈	 {

	
	
	
	
	private static int N;
	private static int R;
	private static int C;
	private static int index;

	/**
	 * 
	 * 재귀를 사용해서 4번 호출
	 * 함수에는 좌표정보와 현재 좌표정보와 해당 사각형의 길이를 넘김
	 * 기저조건은 길이가 1일 경우
	 * 해당 좌표에 다음에 들어가야할 숫자를 입력
	 * r행 c열에 도착했을 떄 인덱스 정보를 출력하고, exit(0)?
	 *
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		index = 0;
		int length = (int)Math.pow(2, N);
		if(N==1) System.out.println("0");
		else System.out.println(divide2(0, 0, length, length*length)-1);
//		divide(0,0,(int)Math.pow(2, N)); // 시간초과
		
	}

	private static int divide2(int r, int c, int len, int value) {

		System.out.println(r+" "+c+" "+len+" "+value);
		if(r == R && c == C) {
			return value;
		}
		if(r<=R && R<r+len/2 && c<=C && C<=c+len/2) {  // 1사분면
			System.out.println("move 1");
			return divide2(r, c, len/2, value - len*3);
		} else if(r<=R && R<r+len/2 && c+len/2<=C && C<c+len) {
			System.out.println("move 2");
			return divide2(r, c+len/2, len/2, value - len*2);			
		} else if(r+len/2<=R && R<r+len && c<=C && C<c+len/2) {
			System.out.println("move 3");
			return divide2(r+len/2, c, len/2, value - len);			
		} else if(r+len/2<=R && R<r+len && c+len/2<=C && C<c+len) {
			System.out.println("move 4");
			return divide2(r+len/2, c+len/2, len/2, value);			
		} else {
			return -1;
		}
	}
	
	private static void divide(int r, int c, int len) {
		
		if(len <= 1) {
//			System.out.println(r+" "+c+" : "+index);
			index++;
			if(R==r && C==c) {
				System.out.println(index-1);
				System.exit(0);
			}
			return;
		} else {
			divide(r, c, len/2);
			divide(r, c+len/2, len/2);
			divide(r+len/2, c, len/2);
			divide(r+len/2, c+len/2, len/2);
		}
	}
	

}
