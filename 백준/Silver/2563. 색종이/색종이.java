import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int MAX = 101;
    static int N, ans = 0;
    static int[][] board = new int[MAX][MAX];

    public static void main(String[] args) throws Exception {
        run();
    }

    static void run() throws Exception {
        input();
        solve();
        print();
    }

    static void cover(int x, int y) {
        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                board[i][j] = 1;
            }
        }
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            cover(x, y);
        }
        br.close();
    }

    static void solve() {
        for (int i = 1; i < MAX; i++) {
            for (int j = 1; j < MAX; j++) {
                if (board[i][j] == 1)
                    ans++;
            }
        }
    }

    static void print() throws Exception {
        sb.append(ans + "");
        System.out.println(sb);
    }
}
