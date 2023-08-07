import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader br;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static StringBuilder sb;

    static int N, M;
    static List<Integer> list;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= T; test_case++) {
            sb = new StringBuilder("#" + test_case + " ");
            run();
        }
        br.close();
        bw.flush();
        bw.close();
    }

    static void run() throws Exception {
        input();
        solve();
        print();
    }

    static void input() throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        list = new LinkedList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }
    }

    static void solve() {
        Collections.sort(list);
        int left = 0, right = N - 1, max = -1;
        while (left != right) {
            int sum = list.get(left) + list.get(right);
            if (sum > M) {
                right--;
            } else if (sum == M) {
                max = sum;
                break;
            } else {
                if (max < sum) {
                    max = sum;
                }
                left++;
            }
        }

        sb.append(max + "\n");

    }

    static void print() throws Exception {
        bw.write(sb.toString());
    }
}
