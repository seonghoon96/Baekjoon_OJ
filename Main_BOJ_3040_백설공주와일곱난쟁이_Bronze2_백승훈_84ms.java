import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_BOJ_3040_백설공주와일곱난쟁이_Bronze2_백승훈_84ms {

	private static int[] arr;
	private static int[] value = new int[9];
	private static int[] result;
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		arr = new int[7];
		for(int i=0; i<9 ;i++) {
			value[i] = Integer.parseInt(br.readLine());
		}
		combination(0, 0, 0);
		for (Integer index : result) {
			System.out.println(index);
		}
		
		
	}
	
	public static void combination(int cnt, int start, int sum) {
		
		if(cnt == 7) {
			if(sum == 100) {
				result = new int[7];
				for(int i=0; i<7; i++) result[i] = arr[i];
			}
			return;
		}
		for(int i=start; i<9; i++) {
			arr[cnt] = value[i];
			combination(cnt+1, i+1, sum+value[i]);
			combination(cnt, i+1, sum);
		}
	}
	
}
