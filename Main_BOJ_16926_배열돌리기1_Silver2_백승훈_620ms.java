import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_BOJ_16926_배열돌리기1_Silver2_백승훈_620ms {

	
	static int N, M, R;
	static StringBuilder sb = new StringBuilder();
	static int[][] board;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// n, m , r 입력
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		board = new int[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<R; i++) {
			rotate();
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				sb.append(board[i][j]).append(" ");
			}
			sb.append("\n");
		}

		
		System.out.println(sb);
		
	}

	static void rotate() {
		int r = 0, c = 0;
		int start=board[r][c], depth=0;
		int depthSize = Math.min(N/2, M/2);
		
		while(depth < depthSize) {
			start = board[r][c];

			for(; c<M-1-depth; c++) { // 왼쪽 이동
				board[r][c] = board[r][c+1];
			}
			for(; r<N-1-depth; r++) { // 위로 이동
				board[r][c] = board[r+1][c];
			}
			for(; c>depth; c--) { // 왼쪽 이동
				board[r][c] = board[r][c-1];
			}
			for(; r>depth; r--) { // 위로 이동
				board[r][c] = board[r-1][c];
			}
			board[r+1][c] = start;
			r++; c++;
			depth++;
		}
		
//		for(int i=0; i<N; i++) {
//			System.out.println(Arrays.toString(board[i]));
//		}
//		System.out.println();
		
		
	}
	
}



/*
4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/
















