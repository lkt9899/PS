import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.util.Scanner;
import java.util.StringTokenizer;

class Solution
{
	static int N;
    static int[][] arr;
    static int[] di = { 0, 1, 0, -1 };
    static int[] dj = { 1, 0, -1, 0 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int test_case = 1; test_case <= T; test_case++) {
            N = sc.nextInt();
            arr = new int[N][N];
            snail();
            print(test_case);
        }
        sc.close();
    }

    static void snail() {
        int num = 1;
        int i = 0, j = 0, dir = 0, ni, nj;
        while (num <= N * N) {
            arr[i][j] = num++;
            ni = i + di[dir];
            nj = j + dj[dir];
            if (ni < 0 || ni >= N || nj < 0 || nj >= N || arr[ni][nj] != 0)
                dir = (dir + 1) % 4;
            i += di[dir];
            j += dj[dir];
        }
    }

    static void print(int t) {
        System.out.printf("#%d\n", t);
        for (int[] a : arr) {
            for (int n : a) {
                System.out.printf("%d ", n);
            }
            System.out.println();
        }
    }
}