import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_정올_1681_해밀턴순환회로_백승훈_126ms {

	private static BufferedReader br;
	private static int N;
	private static int[][] board;
	private static boolean[] visited;
	private static int cost;

	public static void main(String[] args) throws IOException {
		
		br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		board = new int[N][N];
		visited = new boolean[N];
		cost = Integer.MAX_VALUE;
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		
		DFS(0, 0, 0);
		
		
		if(cost == Integer.MAX_VALUE) System.out.println(0);
		else System.out.println(cost);
		
		
	}

	private static void DFS(int node, int cnt, int sum) {

		if(cnt == N-1) {
			if(board[node][0] != 0) {
				cost = Math.min(cost, sum+board[node][0]);
			}
			return;
		}
		
		for(int i=1; i<N; i++) {
			if(!visited[i] && board[node][i] != 0) {
				if(sum+board[node][i] > cost) continue;
				visited[i] = true;
				DFS(i, cnt+1, sum+board[node][i]);
				visited[i] = false;
			}
		}
		
		
		
	}// end of dfs
} // end of class
