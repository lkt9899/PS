import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	public static final int MAX_SIZE = 20;
	public static int[][] arr = new int[MAX_SIZE][MAX_SIZE];
	public static int[] di = {1, 1, 1, 0};
	public static int[] dj = {1, 0, -1, -1}; // 우하부터 시계방향
	
	public static void main(String[] args) throws Exception {
		//////////////////////////////////////////////////////////////
		// 테스트 후 아래 파일 입력을 표준입력으로 처리하는 문장은 주석 처리해주세요!!!! ( System.setIn처리 코드 )
		//////////////////////////////////////////////////////////////
//		System.setIn(new FileInputStream("Test5.txt"));
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 1; i < MAX_SIZE; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 1; j < MAX_SIZE; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}		
		check();
		br.close();
	}
	
	public static void check() {
		for(int i = 1; i < MAX_SIZE; i++) {
			for(int j = 1; j < MAX_SIZE; j++) {
				if(arr[i][j] == 0) continue;
				
				for(int k = 0; k < 4; k++) {
					List<Axis> list = new ArrayList<Axis>();
					list.add(new Axis(i, j));
					int ni = i + di[k];
					int nj = j + dj[k];
					int pi = i - di[k];
					int pj = j - dj[k];
					
					while (ni > 0 && ni < MAX_SIZE && nj > 0 && nj < MAX_SIZE && arr[ni][nj] == arr[i][j]) {
						list.add(new Axis(ni, nj));
						ni += di[k];
						nj += dj[k];
					}

					while (pi > 0 && pi < MAX_SIZE && pj > 0 && pj < MAX_SIZE && arr[pi][pj] == arr[i][j]) {
						list.add(new Axis(pi, pj));
						pi -= di[k];
						pj -= dj[k];
					}
					
					if(list.size() == 5) {
						list.sort((Axis o1, Axis o2) -> {
							if(o1.y == o2.y) {
								return Integer.compare(o1.x, o2.x);
							}
							return Integer.compare(o1.y, o2.y);
						});
						
						System.out.println(arr[i][j]);
						System.out.printf("%d %d", list.get(0).x, list.get(0).y);
						return;
					}
				}
			}
		}
		System.out.println(0);
	}
	
	public static class Axis {
		int x, y;
		
		public Axis(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}

