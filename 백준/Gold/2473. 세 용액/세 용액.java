import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static long min = 3_000_000_001L;
    static int N;
    static long[] solutions;
    static int[] ans = new int[3];
    
    public static void main(String[] args) throws Exception {
        run();
    }
    
    static void run() throws Exception {
        input();
        find();
        print();
    }
    
    static void find() {
        for (int mid = 1; mid < N - 1; mid++) {
            int left = 0, right = N - 1;
            while (left < mid && mid < right) {
                long val = sum(left, mid, right);
                long a_val = Math.abs(val);

                if (min > a_val) {
                    min = a_val;
                    ans[0] = left;
                    ans[1] = mid;
                    ans[2] = right;
                }

                if(val < 0)
                    left++;
                else
                    right--;
            }
        }
    }

    static long sum(int l, int m, int r) {
        return solutions[l] + solutions[m] + solutions[r];
    }

    static void input() throws Exception {
        N = Integer.parseInt(br.readLine());

        solutions = new long[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            solutions[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(solutions);
    }
    
    static void print() throws Exception {
        Arrays.sort(ans);
        for(int n : ans)
            sb.append(solutions[n] + " ");
        System.out.println(sb);
    }    
}