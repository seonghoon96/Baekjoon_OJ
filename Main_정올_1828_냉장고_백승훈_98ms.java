import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Main_정올_1828_냉장고_백승훈_98ms {

	private static int N;
	private static int[][] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N][2];
		
		StringTokenizer st;
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr, new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				return o1[1]-o2[1];
			}
		});
		
		int max = arr[0][1];
		int count = 1;
		for(int i=0; i<N; i++) {
//			System.out.println(arr[i][0]+" "+arr[i][1]);
			if(arr[i][0] > max) {
				max = arr[i][1];
				count++;
			}
		}
		System.out.println(count);
		
	}
}
