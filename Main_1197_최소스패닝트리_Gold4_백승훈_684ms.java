import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


/*
 * 기본적인 MST문제
 * 음의 간선이 주어지긴 하지만 Kruskal, Prim알고리즘 사용할 경우 상관 없다.
 * Prim알고리즘을 활용해서 풀이
 * priority queue를 사용해서 풀이했는데 음의 간선이 들어가도 가중치 연산에 영향 x
 * 
 * Edge class를 만들어서 사용 { 도착 노드 번호, 가중치 } 조합으로 생성
 * pqueue 선언 시 comparator를 사용 => 가장 distance가 작은 간선이 peek에 오도록 설정
 * 
 */
public class Main_1197_최소스패닝트리_Gold4_백승훈_684ms {

	private static StringBuilder sb;
	private static int V;
	private static int E;
	private static ArrayList<ArrayList<Edge>> map;
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
		
		map = new ArrayList<>();
		visited = new boolean[V];
		for(int i=0; i<V; i++) map.add(new ArrayList<>());
		
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int node1 = Integer.parseInt(st.nextToken())-1;
			int node2 = Integer.parseInt(st.nextToken())-1;
			int weight = Integer.parseInt(st.nextToken());
			map.get(node1).add(new Edge(node2, weight));
			map.get(node2).add(new Edge(node1, weight));
		}
		
		pq = new PriorityQueue<Edge>(new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return o1.distance-o2.distance;
			}
		});		
		
		pq.offer(new Edge(0,0));
		int result = 0;
		
		while(!pq.isEmpty()) {
			Edge edge = pq.poll();
			if(visited[edge.node]) continue;
			visited[edge.node] = true;
			result += edge.distance;
			for (Edge e : map.get(edge.node)) {
				if(!visited[e.node]) pq.offer(e);
			}
		}
		System.out.println(result);
		
	} // end of main
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} // end of class
