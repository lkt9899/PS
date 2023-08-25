import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int N;
    static List<Integer>[] list;
    static int[] depth;

    public static void main(String[] args) throws Exception {
        run();
    }

    static void run() throws Exception {
        input();
        bfs(1);
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());

        list = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++)
            list[i] = new ArrayList<>();

        depth = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 2; i <= N; i++) {
            int p = Integer.parseInt(st.nextToken());
            list[p].add(i);
        }
    }

    static void bfs(int start) {
        Deque<Integer> q = new ArrayDeque<>();
        q.add(start);

        int dep = 1;
        int s = 0;
        int e = 0;
        while (!q.isEmpty()) {
            int len = q.size();
            e = s;
            while (len-- != 0) {
                int cur = q.poll();

                if (depth[e] != 0) {
                    depth[e++] = -1;
                } else {
                    depth[e++] = dep;
                }

                for (int next : list[cur]) {
                    q.add(next);
                }
            }

            dep++;
            while (depth[s] == -1) {
                s++;
            }
        }
        System.out.println(e);
    }
}
