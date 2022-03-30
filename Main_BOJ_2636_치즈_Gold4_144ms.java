package workshop;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


/**

 * 
 *  기본 아이디어 : 
 *  1. 구멍을 먼저 찾아 2로 표시 : 주변이 치즈로만 둘러쌓여있어야함
 *  2. bfs 탐색을 통해 가장자리 치즈를 list에 담아 모든 탐색이 끝났을 때 한번에 제거
 *  3. 구멍으로 표시한 부분 다시 0으로 변환
 *
 */

public class Main_BOJ_2636_치즈_Gold4_144ms {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	private static int N;
	private static int M;
	private static int[][] board;
	private static boolean[][] visited;
	private static int[][] clone;
	private static int[] dr= {1,-1,0,0};
	private static int[] dc= {0,0,1,-1};
	private static boolean[][] hole;
	private static boolean done;
	private static ArrayList<Node> list;

	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		for(int i=0; i<N; i++) {
			st= new StringTokenizer(br.readLine(), " ");
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int time = 0;
		int prev = 0;
		while(true) {
			time++;
			visited = new boolean[N][M];
			
			// 구멍 체크
			for(int i=1; i<N-1; i++) {
				for(int j=1; j<M-1; j++) {
					if(!visited[i][j] && board[i][j] == 0) {
						serachHole(i,j);
					}
				}
			}
			
			list = new ArrayList<>();	 // 가장자리 치즈를 담열 리스트
			visited = new boolean[N][M]; // 구멍찾는데 사용한 방문배열 초기화
			
			for(int i=1; i<N-1; i++) {
				for(int j=1; j<M-1; j++) {
					if(!visited[i][j] && board[i][j] == 1) {
						bfs(i,j);		// 방문하지 않은 치즈 bfs 탐색
					}
				}
			}
			
			
			// 구멍으로 표시해뒀던 2를 다시 0으로 변환
			for(int i=1; i<N-1; i++) {
				for(int j=1; j<M-1; j++) {
					if(board[i][j] == 2) board[i][j] = 0;
					
				}
			}
			
			
			// 탐색하면서 가장자리 치즈를 녹이지 않고, 배열에 담아 한번에 녹인다 => count편하게 하기위해
			int count = 0;
			for (Node node : list) {
				if(board[node.r][node.c]==1 ) {
					board[node.r][node.c] = 0;
					count++;
				}
			}
			
			// 녹은 치즈가 없으면 종료!
			if(count == 0) {
				System.out.println((time-1));
				System.out.println(prev);
				break;
			} else {
				// 녹은치즈가 존재하면 치즈 개수를 prev에 저장
				prev= count;
			}
		}
	} // end of main

	/** 치즈를 bfs로 돌면서 가장자리 치즈를 list에 담아주는 함수 */
	private static void bfs(int r, int c) {
		Queue<Node> q = new LinkedList<Node>();
		q.offer(new Node(r,c));
		visited[r][c] = true;
		
		while(!q.isEmpty()) {
			Node node = q.poll();
			for(int i=0; i<4; i++) {
				int nr = node.r+dr[i];
				int nc = node.c+dc[i];
				if(nr<0 || nr>N-1 || nc<0 || nc>M-1) continue;
				
				if(!visited[nr][nc] && board[nr][nc] >0) {
					visited[nr][nc] = true;
					q.offer(new Node(nr,nc));
				} else if(board[nr][nc] == 0){
					list.add(new Node(node.r, node.c));
				}
			}
		} // end of while
	} // end bfs

	/** 구멍을 체크하는 bfs 함수 */
	private static void serachHole(int r, int c) {
		
		Queue<Node> q = new LinkedList<Node>();
		ArrayList<Node> li = new ArrayList<>();
		
		q.offer(new Node(r,c));
		boolean isHole = true;
		
		
		while(!q.isEmpty()) {
			Node node = q.poll();
			
			for(int i=0; i<4; i++) {
				int nr = node.r+dr[i];
				int nc = node.c+dc[i];
				
				if(nr<1 || nr>N-1 || nc<1 || nc>M-1) {
					// 벽과 맞닿은 부분은 홀이 아니다
					isHole = false;
					continue;
				} else if(!visited[nr][nc] && board[nr][nc] == 0) {
					visited[nr][nc] = true;
					li.add(new Node(nr,nc));
					q.offer(new Node(nr,nc));
				}
			}
		} // end of while
		if(isHole) {
			for (Node node : li) {
				board[node.r][node.c] = 2; 
			}
		}
		
	}
	
	
	
	
	
	
} // end of class

class Node{
	int r, c;

	public Node(int r, int c) {
		super();
		this.r = r;
		this.c = c;
	}
	
}

