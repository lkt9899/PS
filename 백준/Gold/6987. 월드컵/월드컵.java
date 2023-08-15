import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int R_MAX = 4;
    static final int C_MAX = 3;
    static final int T_MAX = 6;
    static final int G_MAX = 15;

    static final int WIN = 0;
    static final int DRAW = 1;
    static final int LOSE = 2;

    static int[][][] result = new int[R_MAX][T_MAX][C_MAX];
    static int[] ans = new int[4];
    static int[] t1 = new int[G_MAX];
    static int[] t2 = new int[G_MAX];

    public static void main(String[] args) throws Exception {
        run();
    }

    static void run() throws Exception {
        input();
        makeGame();
        check();
        print();
    }

    static void makeGame() {
        int idx = 0;
        for (int i = 0; i < T_MAX; i++) {
            for (int j = i + 1; j < T_MAX; j++) {
                t1[idx] = i;
                t2[idx] = j;
                idx++;
            }
        }
    }

    static void check() {
        for (int i = 0; i < R_MAX; i++) {
            int[][] res = new int[T_MAX][C_MAX];
            simulation(i, res, 0);
        }
    }

    static void simulation(int simulationNum, int[][] res, int cnt) {
        if (cnt == 15) {
            for (int i = 0; i < T_MAX; i++) {
                if (res[i][WIN] != result[simulationNum][i][WIN] || res[i][DRAW] != result[simulationNum][i][DRAW]
                        || res[i][LOSE] != result[simulationNum][i][LOSE])
                    return;
            }
            ans[simulationNum] = 1;
            return;
        }

        int home = t1[cnt];
        int away = t2[cnt];

        // t1 win, t2 lose
        res[home][WIN]++;
        res[away][LOSE]++;
        simulation(simulationNum, res, cnt + 1);
        res[home][WIN]--;
        res[away][LOSE]--;

        // t1 lose, t2 win
        res[home][LOSE]++;
        res[away][WIN]++;
        simulation(simulationNum, res, cnt + 1);
        res[home][LOSE]--;
        res[away][WIN]--;

        // t1, t2 draw
        res[home][DRAW]++;
        res[away][DRAW]++;
        simulation(simulationNum, res, cnt + 1);
        res[home][DRAW]--;
        res[away][DRAW]--;
    }

    static void input() throws Exception {
        for (int i = 0; i < R_MAX; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < T_MAX; j++) {
                result[i][j][0] = Integer.parseInt(st.nextToken());
                result[i][j][1] = Integer.parseInt(st.nextToken());
                result[i][j][2] = Integer.parseInt(st.nextToken());
            }
        }

        br.close();
    }

    static void print() throws Exception {
        for (int i = 0; i < R_MAX; i++)
            sb.append(ans[i] + " ");
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }
}
