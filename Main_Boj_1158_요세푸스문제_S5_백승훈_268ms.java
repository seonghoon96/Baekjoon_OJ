import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
 
public class Main_Boj_1158_요세푸스문제_S5_백승훈_268ms {
     

	static int N, K;
	static int[] arr;
	static StringTokenizer st;
    public static void main(String[] args) throws NumberFormatException, IOException {
         
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
         
        // queue를 사용해서 K번째 에 해당하면 pop
        // K번째 이전의 값들은 다시 offer 
        // 가지치기 : 큐의 크기가 K의 값보다 작아지는경우 한바퀴를 돌고나서도 똑같이 진행됨
        // K = K%q.size()사용
        
        //K = 12
        //1 2 3 4 5
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        
        Queue<Integer> q = new LinkedList<>();
        
        // 1부터 N까지 차례대로 queue offer
        for(int i=1; i<=N; i++) {
        	q.offer(i);
        }
        
        int index; // q의 사이즈만큼 나눴을 때 나머지를 저장하 변수
        sb.append("<");
        K--; // zerobase로 스타트
        while(!q.isEmpty()) {
        	index = K%(q.size());
        	while(index-->0) { // index 만큼 poll
        		q.offer(q.poll());
        	}
        	sb.append(q.peek()).append(", ");
        	
        	q.poll();
        }
        sb.setLength(sb.length()-2); // 마지막에 ", "제거
        sb.append(">");
        
        System.out.println(sb);     
    }// end of main 
     
}// end of class