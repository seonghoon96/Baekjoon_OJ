import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_10026_적록색약_백승훈_100ms {

	private static StringBuilder sb;
	private static int N;
	private static char[][] board;
	private static int bfsResult;
	private static boolean[][] visited;
	private static int[] dr = {-1, 0, 1, 0};
	private static int[] dc = {0, 1, 0, -1};
	private static int redGreenBfsResult;

	
	/**
	 *  R,G,B 
	 *  적록색약 : 빨간색과 초록색의 구분이 힘듬
	 */
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		sb = new StringBuilder();
		
		N = Integer.parseInt(st.nextToken());
		board = new char[N][N];
		for(int i=0; i<N; i++) 
			board[i] = br.readLine().toCharArray();
		
		 
		bfsResult = 0;
		redGreenBfsResult = 0;
		visited = new boolean[N][N];
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++) {
				if(visited[i][j]) continue;
				bfs(i,j);
				bfsResult++;
			}
			
		visited = new boolean[N][N];
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++) {
				if(visited[i][j]) continue;
				redGreenBfs(i,j);
				redGreenBfsResult++;
			}
		
		sb.append(bfsResult).append(" ").append(redGreenBfsResult).append("\n");
		System.out.println(sb);
	} // end of main


	private static void bfs(int R, int C) {
		Queue<int[]> queue = new LinkedList<int[]>();
		queue.offer(new int[] {R,C});
		visited[R][C] = true;
		char color = board[R][C];
		
		while(!queue.isEmpty()) {
			int r = queue.peek()[0];
			int c = queue.peek()[1];
			queue.poll();
			for(int i=0; i<4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(nr>=0 && nr<N && 0<=nc && nc<N && !visited[nr][nc] && board[nr][nc] == color) {
					visited[nr][nc] = true;
					queue.offer(new int[] {nr,nc});
				}
			}
		
		}
		
	}
	
	private static void redGreenBfs(int R, int C) {
		Queue<int[]> queue = new LinkedList<int[]>();
		queue.offer(new int[] {R,C});
		visited[R][C] = true;
		char color = board[R][C];
		
		while(!queue.isEmpty()) {
			int r = queue.peek()[0];
			int c = queue.peek()[1];
			queue.poll();
			
			for(int i=0; i<4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				
				if(nr>=0 && nr<N && 0<=nc && nc<N && !visited[nr][nc]) {
					if(color == 'B' && board[nr][nc] == color) {						
						visited[nr][nc] = true;
						queue.offer(new int[] {nr,nc});
					} else if(color != 'B' && board[nr][nc] != 'B') {		// 시간차이 크게 안남
//					} else if((color == 'R' || color == 'G') && (board[nr][nc] == 'R' || board[nr][nc] == 'G')) {
						visited[nr][nc] = true;
						queue.offer(new int[] {nr,nc});
					}
				}
			}
		}
	}
	
} // end of class
