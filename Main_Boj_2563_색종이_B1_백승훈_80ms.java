import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
 
public class Main_Boj_2563_색종이_B1_백승훈_80ms {
     
//ㅁㄴ
	static int N, result;
	static boolean[][] paper;
	static StringTokenizer st;
	
    public static void main(String[] args) throws NumberFormatException, IOException {
         
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        result = 0;
        paper = new boolean[100][100];
          
        for(int i=0; i<N; i++) {
        	st = new StringTokenizer(br.readLine());
        	write(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        
        System.out.println(result);
        
        
    }// end of main 
    public static void write(int left, int under) {
    	for(int i=left; i<left+10; i++) {
    		for(int j=under; j<under+10; j++) {
    			if(paper[i][j] == false) {
    				result++;
    				paper[i][j] = true;
    			}
    		}
    	}
    }
    
    
}// end of class