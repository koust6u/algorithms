import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

class Solution{
    private static final Scanner sc = new Scanner(System.in);
    private static int[] building;
    public static void main(String[] args) throws IOException {
        for (int t= 1; t <= 10; t++){
            int dump = sc.nextInt();
            int[] arr = new int[100];
            for (int i = 0; i < 100; i++){
                arr[i] = sc.nextInt();
            }

            for (int i = 0 ; i <dump; i++){
                int max = maxIdx(arr);
                int min = minIdx(arr);
                dumping(arr, min, max);
            }
            int max = arr[maxIdx(arr)];
            int min = arr[minIdx(arr)];
            System.out.println("#"+t +" " + (max-min));
        }
    }

    private static int minIdx(int [] arr){
        int min = Integer.MAX_VALUE;
        int idx = 0;
        for (int i = 0 ; i <100;i++){
            if (min > arr[i]){
                min = arr[i];
                idx = i;
            }
        }
        return idx;
    }

    private static int maxIdx(int[] arr){
        int max = Integer.MIN_VALUE;
        int idx = 0;
        for (int i = 0 ; i < 100 ;i++){
            if (max < arr[i]){
                max = arr[i];
                idx = i;
            }
        }
        return idx;
    }

    private static void dumping(int[] arr,int min, int max){
        arr[min]++;
        arr[max]--;
    }

}