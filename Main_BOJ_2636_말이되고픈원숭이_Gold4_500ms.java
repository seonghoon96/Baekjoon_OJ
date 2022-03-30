package workshop;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_BOJ_2636_말이되고픈원숭이_Gold4_500ms{

	
	private static int K;
	private static int M;
	private static int N;
	private static int[][] board;
	private static boolean[][][] visited;
	private static int result;
	private static int[] dr= {1,-1,0,0};
	private static int[] dc= {0,0,1,-1};
	private static int[] hr= {-2,-1,1,2,2,1,-1,-2};
	private static int[] hc= {1,2,2,1,-1,-2,-2,-1};
	
	
	/*
	 * 처음 아이디어 : DFS로 점프하는경우와 걸어가는 경우 모두 탐색해서
	 * 목적지에 도착했 때 result를 가장 작은 값으로 갱신=> 바로 시간초과!!
	 * 
	 * 
	 *  - - - 1 - - -
	 *  - - - 1 - - - 
	 *  => 점프를 무조건 사용해야 되는 구간이 생길 수 있음
	 *     완전탐색은 안할순 없다. => 백트래킹 필요?
	 *     
	 * 다음 아이디어 : 거리 3을 이동할때 1+2 2+1로 이동할 수 있는 것 처럼
	 * 점프하는 개수를 체크하면서 이미 방문한 곳이면 프루닝!!
	 * 방문배열을 3차원으로 선언해서 점프 개수에따른 방문여부를 체크
	 * bfs방식으로 접근하기 때문에 도착지에 가장 먼저 도착한 경우 return
	 * 
	 * 
	 */
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		K =Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine(), " ");
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		visited = new boolean[N][M][K+1];
		result = -1;
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		} // end of input
		
		bfs();
		System.out.println(result);
		
		
		
	} // end of main

	private static void bfs() {
		Queue<Node> q = new LinkedList<>();
		q.offer(new Node(0,0,0,K));
		visited[0][0][K] = true;
		
		while(!q.isEmpty()) {
			Node node = q.poll();
			if(node.r==N-1 && node.c==M-1) {
				result = node.count;
				break;
			}
			
			for(int i=0; i<4; i++) {
				int nr = node.r+dr[i];
				int nc = node.c+dc[i];
				if(0<=nr && nr<N && 0<=nc && nc<M && !visited[nr][nc][node.k] && board[nr][nc]!=1) {
					visited[nr][nc][node.k] = true;
					q.offer(new Node(nr,nc,node.count+1, node.k));
				}
			}
			
			if(node.k>0) {
				for(int i=0; i<8; i++) {
					int nr = node.r+hr[i];
					int nc = node.c+hc[i];
					if(0<=nr && nr<N && 0<=nc && nc<M && !visited[nr][nc][node.k-1] && board[nr][nc]!=1) {
						visited[nr][nc][node.k-1] = true;
						q.offer(new Node(nr,nc,node.count+1, node.k-1));
					}
					
				}
			}
		}
	}

	

} // end of class


class Node implements Comparable<Node>{
	int r,c,count,k;

	public Node(int r, int c, int count, int k) {
		super();
		this.r = r;
		this.c = c;
		this.count = count;
		this.k = k;
	}

	@Override
	public int compareTo(Node o) {
		return this.count-o.count;
	}
	
	
	
}
