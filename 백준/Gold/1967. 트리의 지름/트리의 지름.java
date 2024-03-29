import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static final int MAX = 10001;
    static int N, maxIdx, res;
    static List<Node>[] list = new ArrayList[MAX];
    static boolean[] visited;

    static class Node {
        int next, dist;

        public Node(int next, int dist) {
            this.next = next;
            this.dist = dist;
        }
    }

    public static void main(String[] args) throws Exception {
        run();
    }

    static void run() throws Exception {
        input();
        dfs(1);
        dfs(maxIdx);
        System.out.println(res);
    }

    static void dfs(int start) {
        visited = new boolean[N + 1];

        Queue<Node> q = new ArrayDeque<>();
        q.add(new Node(start, 0));
        visited[start] = true;
        int max = 0;

        while (!q.isEmpty()) {
            Node cur = q.poll();

            if (cur.dist > max) {
                max = cur.dist;
                maxIdx = cur.next;
            }

            for (Node n : list[cur.next]) {
                if (!visited[n.next]) {
                    visited[n.next] = true;
                    q.add(new Node(n.next, n.dist + cur.dist));
                }
            }
        }

        res = res > max ? res : max;
    }

    static void input() throws Exception {
        // init list
        N = Integer.parseInt(br.readLine());
        if (N == 1) {
            System.out.println(0);
            System.exit(0);
        }
        
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
        }

        int cur, next, dist;
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            cur = Integer.parseInt(st.nextToken());
            next = Integer.parseInt(st.nextToken());
            dist = Integer.parseInt(st.nextToken());

            list[cur].add(new Node(next, dist));
            list[next].add(new Node(cur, dist));
        }
    }
}
