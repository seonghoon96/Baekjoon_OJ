import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main_BOJ_3109_빵집_Gold2_백승훈_332ms {

	
	private static int R;
	private static int C;
	private static int[][] board;
	private static int[] visit;
	private static int result;
	private static int[] dr = {-1, 0, 1};
	private static int[] dc = {1, 1, 1};


	/**
	 * 문제 설명
	 * 첫번째 열 : 근처 빵집의 가스관
	 * 마지막 열 : 원웅이의 빵집 
	 * 빵집과 가스관 사이에는 건물이 존재 가능
	 * 건물이 있을 경우 파이프를 놓을 수 없다
	 * 파이프라인은 첫째 열에서 시작, 마지막 열에서 끝
	 * 각 칸은 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선
	 * 가스관과 빵집을 연결하는 파이프라인을 여러개 설치
	 * 경로는 겹칠 수 없고, 서로 접할수도 없다 => 각 칸을 지나는 파이프는 하나
	 * 	
	 *  5 5
		.xx..
		..x..
		.....
		...x.
		...x.

		아이디어 : 
		이동방향의 우선순위가 오른쪽위, 오른쪽, 오른쪽 아래로 설정
		최종 열에 도착했때 카운트하고, 지나온 길에 건물을 세울예정
		만약에 최종 열에 도착하기 전에 아무 방향으로도 이동하지 못하면 가지치기
	 * @throws IOException 
		
	 */
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		board = new int[R+2][C+2];
		result = 0;		
		
		// padding 벽을 -1로 표시 
		for(int i=0; i<R+2; i++) board[i][0] = board[i][C+1] = -1;
		for(int i=0; i<C+2; i++) board[0][i] = board[R+1][i] = -1;
		
		// board 입력 시작
		for(int i=1; i<=R; i++) {
			String line = br.readLine();
			for(int j=1; j<=C; j++) {
				char c = line.charAt(j-1);
				if(c == '.') board[i][j] = 0;	// 파이프 설치 가능한 위치 0
				else board[i][j] = 1;			// 건물 위치 1
			}
		}
			
		// 열마다 시작지점부터 search 실행
		for(int i=1; i<=R; i++) {
			if(search(i, 1)) {	// 끝지점에 도달할 경우 체크
				result++;
			}
		}
		System.out.println(result);	
	} // end of main

	private static boolean search(int r, int c) {
		board[r][c] = 1;	// 지나온길 표시 => 그전에 지나간 길은 이미 가망이 없는 길이므로 건물 세움 
							//				&& 파이프가 설치되어도 건물 세움
		if(c == C) {		// 마지막에 도달한 경우
			return true;
		} 
		for(int i=0; i<3; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];		
			if(board[nr][nc] == 0)	// 지나가지 않은 길인 경우
				if(search(nr, nc)) return true;
		}	
		return false;
	}
} // end of class













