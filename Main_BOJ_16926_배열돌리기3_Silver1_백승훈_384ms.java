import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


/**
 * 
 * 	★ 주의 :	board의 가로세로 길이가 다르게 주어지는 경우 존재 => 90도 회전하는 경우 N * M -> M * N 으로 배열을 변경해줘야함
 * 			따라서 모든 메서드 작성 시, 현재 배열의 가로, 세로길이를 한번더 확인하고 해당 변수로 메서드 진행
 * 
 *  MEMO : 	메서드가 실행될 때마다 배열의 가로길이, 세로길이의 절반값을 연산하는 부분이 많아 halfRow, halfCol변수를 사용해서 연산시간 감소
 *
 */
public class Main_BOJ_16926_배열돌리기3_Silver1_백승훈_384ms {

	
	static int N, M, R;
	static StringBuilder sb = new StringBuilder();
	static int[][] board;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// n m,r 입력
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		board = new int[N][M];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<R; i++) {
			switch(Integer.parseInt(st.nextToken())) {
			case 1:
				operator1();
				break;
			case 2:
				operator2();				
				break;
			case 3:
				operator3();
				break;
			case 4:
				operator4();
				break;
			case 5:
				operator5();
				break;
			case 6:
				operator6();
				break;
			}		
		}
		
		
		for(int i=0; i<board.length; i++) {
			for(int j=0; j<board[i].length; j++) {
				sb.append(board[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
		
	}
	
	
	private static void operator1() {
		// TODO 상하 반전
		int row = board.length;
		int col = board[0].length;
		int halfRow = row/2;
		int halfCol = col/2;
		
		int temp;
		for(int i=0; i<halfRow; i++) {
			for(int j=0; j<col; j++) {
				temp = board[i][j];
				board[i][j] = board[row-i-1][j];
				board[row-i-1][j] = temp;
			}
		}
		
	}

	private static void operator2() {
		// TODO 좌우반전
		int row = board.length;
		int col = board[0].length;
		int halfRow = row/2;
		int halfCol = col/2;

		int temp;
		for(int i=0; i<row; i++) {
			for(int j=0; j<halfCol; j++) {
				temp = board[i][j];
				board[i][j] = board[i][col-j-1];
				board[i][col-j-1] = temp;
			}
		}
		
		
	}

	private static void operator3() {
		// TODO 오른쪽 90도 회전
		int row = board.length;
		int col = board[0].length;
		int[][] copy = new int[col][row];
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				copy[j][row-i-1] = board[i][j];
			}
		}
		board = copy;
		
	}

	private static void operator4() {
		// TODO 왼쪽 90도 회전
		int row = board.length;
		int col = board[0].length;
		int[][] copy = new int[col][row];
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				copy[col-j-1][i] = board[i][j];
			}
		}
		board = copy;		
	}

	private static void operator5() {
		// TODO 부분 시계방향 회전
		int row = board.length;
		int col = board[0].length;
		int halfRow = row/2;
		int halfCol = col/2;
		
		/* 1 2 -> 4 1
		 * 4 3 -> 3 2
		 */
		
		int[][] start = new int[halfRow][halfCol];
		
		// 1번 부분배열 start에 복사
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				start[i][j] = board[i][j];
		
		int r = halfRow, c = halfCol;
		
		// 4 => 1 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[i][j] = board[halfRow+i][j];
		
		// 3 => 4 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[halfRow+i][j] = board[halfRow+i][halfCol+j];
		
		// 2 => 3 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[halfRow+i][halfCol+j] = board[i][halfCol+j];
		
		// start => 2 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[i][halfCol+j] = start[i][j];
		
		
	}

	private static void operator6() {
		// TODO 부분 반시계방향 회전
		int row = board.length;
		int col = board[0].length;
		int halfRow = row/2;
		int halfCol = col/2;
		
		/* 1 2 -> 2 3
		 * 4 3 -> 1 4
		 */
		
		int[][] start = new int[halfRow][halfCol];
		
		// 1번 부분배열 start에 복사
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				start[i][j] = board[i][j];
		int r = halfRow, c = halfCol;
		
		// 2 => 1 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[i][j] = board[i][halfCol+j];
		
		// 3 => 2 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[i][halfCol+j] = board[halfRow+i][halfCol+j];
		
		// 4 => 3 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[halfRow+i][halfCol+j] = board[halfRow+i][j];
		
		// start => 4 이동
		for(int i=0; i<halfRow; i++)
			for(int j=0; j<halfCol; j++)
				board[halfRow+i][j] = start[i][j];
		
		
	}

	
}











