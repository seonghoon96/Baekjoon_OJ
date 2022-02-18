import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_2567_색종이2_Silver4_백승훈_88ms {

	private static int N;
	private static boolean[][] board;
	private static int[] dr = {1, -1, 0, 0};
	private static int[] dc = {0, 0, 1, -1};

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(st.nextToken());
		board = new boolean[101][101];
		for(int i=0; i<101; i++) Arrays.fill(board[i], false);
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			for(int a=r; a<r+10; a++) {
				for(int b=c; b<c+10; b++) {
					board[a][b] = true;
				}
			}
		}
		
		int len = 0;
		for(int r=1; r<=100; r++) {
			for(int c=1; c<=100; c++) {
				if(!board[r][c]) continue;
				for(int d=0; d<4; d++) {
					int nr = r + dr[d];
					int nc = c + dc[d];
					if(!board[nr][nc] || nr<1 || nr>100 || nc<1 || nc>100) {
						len++;
					}
				}
			}
		}
		System.out.println(len);
	}
	
	
}
