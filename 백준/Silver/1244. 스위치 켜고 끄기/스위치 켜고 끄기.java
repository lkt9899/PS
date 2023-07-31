import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static final int MAX = 101;
    static int N;
    static int[] arr = new int[MAX];

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(in.readLine());
        st = new StringTokenizer(in.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int M = Integer.parseInt(in.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(in.readLine());
            int gen = Integer.parseInt(st.nextToken());
            int num = Integer.parseInt(st.nextToken());

            toggle(gen, num);
        }
        print();
    }

    static void toggle(int gen, int num) {
        if (gen == 1) {
            for (int i = num; i <= N; i += num) {
                arr[i] ^= 1;
            }
        } else {
            int idx = num;
            arr[idx] ^= 1;
            int cnt = 1;
            while (true) {
                if (idx - cnt <= 0 || idx + cnt > N)
                    break;
                if (arr[idx + cnt] == arr[idx - cnt]) {
                    arr[idx + cnt] ^= 1;
                    arr[idx - cnt] ^= 1;
                    cnt++;
                } else
                    break;
            }
        }
    }

    static void print() {
        for (int i = 1; i <= N; i++) {
            System.out.printf("%d ", arr[i]);
            if (i % 20 == 0)
                System.out.println();
        }
    }
}