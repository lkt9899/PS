import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int N, L, R, tmp, ans;
    static boolean flag;

    static int[][] map;
    static int[][] visited;

    static int[] di = { 0, 1, 0, -1 };
    static int[] dj = { 1, 0, -1, 0 };

    static class Axis {
        int x, y;

        public Axis(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        input();
        while (true) {
            flag = true;
            run();
            if (flag)
                break;
            ans++;
        }
        System.out.println(ans);
    }
    
    static void run() throws Exception {
        visitInit();
        tmp = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == -1) {
                    bfs(new Axis(i, j));
                    tmp++;
                }
            }
        }
    }

    static void visitInit() {
        for (int i = 0; i < N; i++)
            Arrays.fill(visited[i], -1);
    }
    
    static void bfs(Axis start) {
        Deque<Axis> dq = new ArrayDeque<>();

        int sum = map[start.x][start.y];
        int cnt = 1;

        visited[start.x][start.y] = tmp;
        dq.add(start);
        while (!dq.isEmpty()) {
            Axis cur = dq.poll();

            for (int d = 0; d < 4; d++) {
                int ni = cur.x + di[d];
                int nj = cur.y + dj[d];

                if (isNotValid(ni, nj))
                    continue;
                
                int diff = Math.abs(map[cur.x][cur.y] - map[ni][nj]);
                if(diff < L || diff > R)
                    continue;
                    
                sum += map[ni][nj];
                cnt++;
                visited[ni][nj] = tmp;
                dq.add(new Axis(ni, nj));
            }
        }

        if (cnt > 1)
            flag = false;

        int newVal = sum / cnt;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (cnt == 0)
                    break;
                
                if (visited[i][j] == tmp) {
                    map[i][j] = newVal;
                    cnt--;
                }
            }
        }
    }

    static boolean isNotValid(int i, int j) {
        return (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] != -1);
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        visited = new int[N][N];
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }
}
