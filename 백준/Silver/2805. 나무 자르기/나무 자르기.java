import java.io.*;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc =new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] tree = new int[n];
        int min = 0;
        int max = 0;
        for(int i = 0 ; i < n ; i++){
            tree[i] = sc.nextInt();
            if(tree[i] > max) max = tree[i];
        }

        while(min < max){
            int mid = (min + max )/2;
            long sum = 0;
            for(int treeHeight : tree){
                if(treeHeight - mid > 0) sum += (treeHeight - mid);
            }

            if(sum < m) max = mid;
            else min = mid+1;
        }
        System.out.println(min -1);
    }
}