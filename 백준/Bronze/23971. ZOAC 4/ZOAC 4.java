import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int H, W, N, M;

        H = sc.nextInt();
        W = sc.nextInt();
        N = sc.nextInt();
        M = sc.nextInt();

        int A = (H / (N + 1)) + (H % (N + 1) > 0 ? 1 : 0);
        int B = (W / (M + 1)) + (W % (M + 1) > 0 ? 1 : 0);

        System.out.println(A * B);
    }
}