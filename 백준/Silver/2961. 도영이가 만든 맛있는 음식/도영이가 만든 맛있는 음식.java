import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static final int MAX = 10;
	static int N;
	static int[] sour = new int[MAX];
	static int[] bitter = new int[MAX];
	static int ans = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws Exception {
		input();
		run();
	}
	
	static void input() throws Exception {
		N = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < N; i++) {
			String[] s = br.readLine().split(" ");
			sour[i] = Integer.parseInt(s[0]);
			bitter[i] = Integer.parseInt(s[1]);			
		}
		br.close();
	}
	
	static void run() throws Exception {
		for(int i = 0; i < N; i++) {
			mix(i, sour[i], bitter[i]);
		}
		
		bw.write(ans + "");
		bw.flush();
		bw.close();
	}
	
	static void mix(int idx, int s, int b) {
		ans = Math.min(ans, Math.abs(b - s));
		for(int i = idx + 1; i < N; i++) {
			mix(i, s * sour[i], b + bitter[i]);
		}
	}
}
