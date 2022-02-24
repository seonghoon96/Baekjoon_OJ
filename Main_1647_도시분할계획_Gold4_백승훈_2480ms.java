import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


/*
 * 기본적인 MST문제
 * Prim알고리즘을 활용해서 풀이
 * Edge class를 만들어서 사용 { 도착 노드 번호, 가중치 } 조합으로 생성
 * pqueue 선언 시 comparator를 사용 => 가장 distance가 작은 간선이 peek에 오도록 설정
 * 
 * 최소 스패닝 트리를 구한 다음에 가중치가 작은 간선을 넣는 과정에서
 * 가장 가중치가 큰 간선의 distance를 저장하고
 * 최종 스패닝 트리의 가중치 합에서 distance값을 빼주면서 하나의 스패닝트리를 반으로 나눈다.
 */
public class Main_1647_도시분할계획_Gold4_백승훈_2480ms {

	private static StringBuilder sb;
	private static int V;
	private static int E;
	private static ArrayList<Edge>[] map;
	private static PriorityQueue<Edge> pq;
	private static boolean[] visited;

	static class Edge{
		int node, distance;
		
		public Edge(int node, int distance) {
			super();
			this.node = node;
			this.distance = distance;
		}		
	};
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		sb = new StringBuilder();
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		map = new ArrayList[V];
		visited = new boolean[V];
		for(int i=0; i<V; i++) map[i]=new ArrayList<>();
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int node1 = Integer.parseInt(st.nextToken())-1;
			int node2 = Integer.parseInt(st.nextToken())-1;
			int weight = Integer.parseInt(st.nextToken());
			map[node1].add(new Edge(node2, weight));
			map[node2].add(new Edge(node1, weight));
		}
		
		pq = new PriorityQueue<Edge>(new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return o1.distance-o2.distance;
			}
		});		
		
		pq.offer(new Edge(0,0));
		int result = 0;
		int maxDistance = 0;
		while(!pq.isEmpty()) {
			Edge edge = pq.poll();
			if(visited[edge.node]) continue;
			visited[edge.node] = true;
			maxDistance = Math.max(maxDistance, edge.distance);
			result += edge.distance;
			for (Edge e : map[edge.node]) {
				if(!visited[e.node]) pq.offer(e);
			}
		}
		System.out.println(result-maxDistance);
		
	} // end of main
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} // end of class
