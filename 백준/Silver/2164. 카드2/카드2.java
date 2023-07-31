import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            dq.addLast(i);
        }
        while (dq.size() != 1) {
            dq.pollFirst();
            int tmp = dq.peekFirst();
            dq.pollFirst();
            dq.addLast(tmp);
        }
        System.out.println(dq.peek());
        sc.close();
    }
}