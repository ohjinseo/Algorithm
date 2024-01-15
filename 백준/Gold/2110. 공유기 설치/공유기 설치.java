import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 *
 * 최대 거리가 m일때 [1, 2, 4, 8, 9]를 만족
 * [1, 2, 3, 4, 6, 7, 8]
 * right =
 */

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int N, C;
    static int[] arr = new int[200001];
    static int ans = 0;

    private static boolean check(int mid) {
        int s = arr[0];
        int cnt = 1;
        for(int i = 1; i < N; i++){
            if(arr[i] - s >= mid){
                cnt++;
                s = arr[i];
            }
        }


        if(cnt >= C) return true;
        return false;
    }

    public static void main(String[] args) {
        N = sc.nextInt();
        C = sc.nextInt();

        for(int i = 0; i < N; i++){
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr, 0, N);

        int left = 0;
        int right = arr[N - 1] - arr[0];

        while(left <= right){
            int mid = (left + right) / 2;

            // 거리 mid에 대해 집의 개수를 만족한다면
            if(check(mid)){
                ans = Math.max(ans, mid);
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        System.out.println(ans);
    }
}