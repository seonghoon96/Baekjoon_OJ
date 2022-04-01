import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_BOJ_4485_녹입젤_Gold4_144ms {


	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	private static int N;
	private static int[][] map;
	private static int[][] dp;
	private static boolean[][] visited;
	private static int[] dr = {1,-1,0,0};
	private static int[] dc = {0,0,1,-1};
	private static int[][] distance;

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		
		int turn = 0;
		while(true) {
			turn++;
			N = Integer.parseInt(br.readLine());
			if(N==0) break;
			
			map = new int[N][N];
			for(int i=0; i<N; i++) {
				String str = br.readLine();
				for(int j=0, index=0; j<N; j++, index+=2) {
					map[i][j] = str.charAt(index)-'0';
				}
			}
			
			dijkstra();
			
			
			// DP로 풀이하려 했으나 실패 -> 돌아가는데 비용이 적은경우 고려 못함, 오른쪽 아래로만 이동하는게아니기 때문에
//			dp = new int[N][N];
//			for(int i=0; i<N; i++) {
//				for(int j=0; j<N; j++) {
//					if(i==0 && j==0) dp[i][j] = map[i][j];
//					else if(i==0) dp[i][j] = map[i][j] + dp[i][j-1];
//					else if(j==0) dp[i][j] = map[i][j] + dp[i-1][j];
//					else dp[i][j] = map[i][j] + Math.min(dp[i-1][j], dp[i][j-1]);
//				}
//				
//				for(int k=0; k<N; k++) System.out.println(Arrays.toString(dp[k]));
//				System.out.println();
//			}
//			sb.append("Problem ").append(N).append(": ").append(dp[N-1][N-1]).append("\n");
			
			
			sb.append("Problem ").append(turn).append(": ").append(distance[N-1][N-1]).append("\n");
		} // end of while
		
			
		System.out.println(sb);
		
		
	} // end of main

	private static void dijkstra() {
		distance = new int[N][N];
		for(int i=0; i<N; i++) Arrays.fill(distance[i], 987654321);
		distance[0][0] = map[0][0];
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.offer(new Node(0,0,map[0][0]));
		
		while(!pq.isEmpty()) {
			Node node = pq.poll();			
			for(int i=0; i<4; i++) {
				int nr = node.r + dr[i];
				int nc = node.c + dc[i];
				if(0<=nr && nr<N && 0<=nc && nc<N) {
					if(distance[nr][nc] > distance[node.r][node.c]+map[nr][nc]) {
						distance[nr][nc] = distance[node.r][node.c]+map[nr][nc];
						pq.offer(new Node(nr,nc,distance[nr][nc]));
					}
				}
				
			}
			
		}
		
		
	}
	
	static class Node implements Comparable<Node>{
		int r, c, dist;

		public Node(int r, int c, int dist) {
			super();
			this.r = r;
			this.c = c;
			this.dist = dist;
		}

		@Override
		public int compareTo(Node o) {
			return this.dist-o.dist;
		}
		
		
	}
	
	
} // end of class








