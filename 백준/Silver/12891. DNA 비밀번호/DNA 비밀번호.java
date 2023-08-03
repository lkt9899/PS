import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static final int A = 0;
	static final int C = 1;
	static final int G = 2;
	static final int T = 3;
	static int S, P, ans = 0;
	static char[] string;
	static int[] count = new int[4];
	static int[] cnt = new int[4];
	
	public static void main(String[] args) throws Exception {
		input();
		run();
	}

	static void input() throws Exception {
		String[] tmp = br.readLine().split(" ");
		S = Integer.parseInt(tmp[0]);
		P = Integer.parseInt(tmp[1]);
		
		string = br.readLine().toCharArray();
		
		tmp = br.readLine().split(" ");
		for(int i = 0; i < 4; i++) {
			count[i] = Integer.parseInt(tmp[i]);
		}
		br.close();
	}
	
	static void run() throws Exception {
		for(int i = 0; i < P; i++) {
			if(string[i] == 'A') cnt[A]++;
			if(string[i] == 'C') cnt[C]++;
			if(string[i] == 'G') cnt[G]++;
			if(string[i] == 'T') cnt[T]++;
		}
		
		if(check())
			ans++;
		
		int s = -1;
		for(int e = P; e < S; e++) {
			s++;
			if(string[s] == 'A') cnt[A]--;
			else if(string[s] == 'C') cnt[C]--;
			else if(string[s] == 'G') cnt[G]--;
			else cnt[T]--;
			
			if(string[e] == 'A') cnt[A]++;
			else if(string[e] == 'C') cnt[C]++;
			else if(string[e] == 'G') cnt[G]++;
			else cnt[T]++;
			
			if(check())
				ans++;
		}
		
		bw.write(ans + "");
		bw.flush();
		bw.close();
	}
	
	static boolean check() {
		for(int i = 0; i < 4; i++) {
			if(cnt[i] < count[i])
				return false;
		}
		
		return true;
	}
}
