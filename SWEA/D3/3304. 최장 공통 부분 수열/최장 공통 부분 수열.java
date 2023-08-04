import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int MAX = 1001;
    static String s1, s2;
    static int[][] dp = new int[MAX][MAX];

    public static void main(String[] args) throws Exception {
        int T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            init();
            LCS();
            sb = new StringBuilder("#" + t + " ");
            sb.append(dp[s1.length() - 1][s2.length() - 1]);
            System.out.println(sb.toString());
        }
    }

    static void init() throws Exception {
        st = new StringTokenizer(br.readLine());
        s1 = "X" + st.nextToken();
        s2 = "X" + st.nextToken();
    }

    static void LCS() {
        for(int i = 1; i < s1.length(); i++) {
            for(int j = 1; j < s2.length(); j++) {
                if(s1.charAt(i) == s2.charAt(j)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
}
