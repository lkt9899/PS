import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int MAX = 5;

    static int[] p = new int[MAX * MAX];
    static char[][] map = new char[MAX][MAX];

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
        run();
    }

    static void run() throws Exception {
        int ans = 0;
        for (int i = MAX * MAX - 1; i > MAX * MAX - 8; i--)
            p[i] = 1;
        do {
            if (check())
                ans++;
        } while (nextPermutation());

        System.out.println(ans);
    }

    static boolean nextPermutation() {
        int i = MAX * MAX - 1;
        while (i > 0 && p[i] <= p[i - 1])
            i--;

        if (i == 0)
            return false;

        int j = MAX * MAX - 1;
        while (p[j] <= p[i - 1])
            j--;

        swap(i - 1, j);

        int k = MAX * MAX - 1;
        while (i < k)
            swap(i++, k--);

        return true;
    }

    static void swap(int i, int j) {
        int tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
    }

    static boolean check() {
        int[][] tmp = new int[MAX][MAX];
        for (int i = 0; i < MAX; i++) {
            tmp[i] = Arrays.copyOfRange(p, i * MAX, (i + 1) * MAX);
        }

        int si = -1;
        int sj = -1;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (tmp[i][j] == 1) {
                    si = i;
                    sj = j;
                    break;
                }
            }
            if (si >= 0)
                break;
        }

        int cnt = 0;
        int sCnt = 0;
        Deque<Axis> dq = new ArrayDeque<>();
        boolean[][] visited = new boolean[MAX][MAX];
        
        dq.add(new Axis(si, sj));
        visited[si][sj] = true;
        while (!dq.isEmpty()) {
            Axis cur = dq.poll();
            cnt++;
            if (map[cur.x][cur.y] == 'S')
                sCnt++;

            for (int d = 0; d < 4; d++) {
                int ni = cur.x + di[d];
                int nj = cur.y + dj[d];

                if (ni < 0 || ni >= MAX || nj < 0 || nj >= MAX || visited[ni][nj])
                    continue;

                if (tmp[ni][nj] == 1) {
                    visited[ni][nj] = true;
                    dq.push(new Axis(ni, nj));
                }
            }
        }

        if (cnt == 7 && sCnt > 3)
            return true;

        return false;
    }

    static void input() throws Exception {
        for (int i = 0; i < MAX; i++)
            map[i] = br.readLine().toCharArray();
    }
}