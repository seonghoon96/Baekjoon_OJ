import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_BOJ_1987_알파벳_Gold4_백승훈_768ms {

	
	
	private static int R;
	private static int C;
	private static char[][] board;
	private static int result;
	private static int[] dr = {-1, 0, 1, 0}; // 상 우 하 좌 시계방향
	private static int[] dc = {0, 1, 0, -1}; // 상 우 하 좌 시계방향
	private static boolean[] alpha;

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		board = new char[R+2][C+2];
		alpha = new boolean[26];
		Arrays.fill(alpha, false);

		
		// padding 벽을 -로 표시 
		for(int i=0; i<R+2; i++) board[i][0] = board[i][C+1] = '-';
		for(int i=0; i<C+2; i++) board[0][i] = board[R+1][i] = '-';
		
		for(int i=1; i<=R; i++) {
			String line = br.readLine();
			for(int j=1; j<=C; j++) {
				board[i][j] = line.charAt(j-1);
			}
		}
			
		// 시작좌표 visit check
		result = 1;		
		alpha[board[1][1]-'A'] = true;
		dfs(1, 1, 1);
		System.out.println(result);
	} // end of main

	private static void dfs(int r, int c, int cnt) {

		result = Math.max(result, cnt); // 매번 새로운 알파벳을 찾을때 마다 dfs실행하므로 갱신
		
		for(int i=0; i<4; i++) {
			int nr = r + dr[i];	// 다음에 방문하게될 행 좌표
			int nc = c + dc[i]; // 다음에 방문하게 될 열 좌표
			char ch = board[nr][nc]; // 해당 좌표의 알파벳
			
			if(board[nr][nc]!='-' && !alpha[ch-'A']) { // 벽이아니고 방문하지 않은 알파벳일 경우
				alpha[ch-'A'] = true;
				dfs(nr,nc,cnt+1);
				alpha[ch-'A'] = false;
				
			}
		}
	}

}







