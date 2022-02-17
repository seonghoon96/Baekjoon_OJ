import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_BOJ_1992_쿼드트리_Silver1_백승훈_80ms {

	
	
	private static int N;
	private static int[][] board;
	private static StringBuilder sb;

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		sb = new StringBuilder();
		
		N = Integer.parseInt(st.nextToken());
		board = new int[N][N];
		for(int i=0; i<N; i++) {
			String s = br.readLine();
			for(int j=0; j<N; j++) {
				board[i][j] = s.charAt(j)-'0';
			}
		}
		recursion(0, 0, N);
		System.out.println(sb);
		
		
	}

	/**
	 * 압축이 가능하면 바로 압축
	 * 안되면 () 붙이고 분할
	 */
	public static void recursion(int r, int c, int len) {
		
		// 압축이 가능
		if(possible(r, c, len)) {
			sb.append(board[r][c]);
			return;
		}
		int size = len / 2;	
		sb.append('(');	
		recursion(r, c, size);						
		recursion(r, c + size, size);			
		recursion(r + size, c, size);				
		recursion(r + size, c + size, size);	
		sb.append(')');	
			
		
	}
	
	
	// 압축 가능 여부 체크
	public static boolean possible(int r, int c, int len) {
		int value = board[r][c];
		for(int i = r; i < r+len; i++) {
			for(int j = c; j < c+len; j++) {
				if(value != board[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	
}
