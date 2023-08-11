import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws Exception {
        int N = Integer.parseInt(br.readLine());
        
        int[] dp = new int[5001];
        Arrays.fill(dp, -1);
        dp[3] = dp[5] = 1;
        
        for (int i = 6; i <= N; i++) {
            if (dp[i - 3] != -1)
                dp[i] = dp[i - 3] + 1;
            if (dp[i - 5] != -1)
                dp[i] = dp[i] != -1 ? Math.min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
        }
        System.out.println(dp[N]);
        br.close();
    }
}