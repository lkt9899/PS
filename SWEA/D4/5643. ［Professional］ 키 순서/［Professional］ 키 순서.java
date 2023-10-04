import java.io.*;
import java.util.*;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static final int MAX_N = 501;

    static int N, M;
    static int[][] adj = new int[MAX_N][MAX_N];

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            sb.append("#" + test_case + " ");
            run();
        }
        print();
    }
    
    static void run() throws Exception {
        input();
        sb.append(getAns() + "\n");
    }
    
    static void init() {
        for (int i = 1; i <= N; i++) {
            Arrays.fill(adj[i], 1, N + 1, 0);
        }
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        init();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            adj[from][to] = 1;
        }
    }

    static int getAns() {
        int ans = 0;

        for (int i = 1; i <= N; i++) {
            int s = getShort(i, new boolean[N + 1]);
            int t = getTall(i, new boolean[N + 1]);
            if (s + t == N - 1)
                ans++;
        }

        return ans;
    }
    
    static int getShort(int to, boolean[] visited) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && adj[i][to] == 1) {
                visited[i] = true;
                cnt += getShort(i, visited) + 1;
            }
        }

        return cnt;
    }
    
    static int getTall(int from, boolean[] visited) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && adj[from][i] == 1) {
                visited[i] = true;
                cnt += getTall(i, visited) + 1;
            }
        }

        return cnt;
    }

    static void print() throws Exception {
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}