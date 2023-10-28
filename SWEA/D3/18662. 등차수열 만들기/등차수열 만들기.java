import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Solution {

    private static Scanner sc = new Scanner(System.in);

    private static double calculateTheGap(int []arr){
        double number;
        int a= arr[0], b = arr[1], c = arr[2];
        // first a & c
        number = (double)(a + c) /2;
        double answer1 = makeEqual(arr[1], number);
        //second a & b
        number = b + (b - a);
        double answer2 = makeEqual(arr[2], number);
        //second b & c
        number = b - (c -b);
        double answer3 = makeEqual(arr[0], number);
        return Math.min(answer1, Math.min(answer2, answer3));
    }

    private static double makeEqual(double target, double number){
        return ((target > number)? target- number: (number - target));
    }
    public static void main(String[] args) {
        int T = sc.nextInt();

        for(int t = 1; t <= T; t++){
            int[] arr= new int[3];
            arr[0] = sc.nextInt();
            arr[1] = sc.nextInt();
            arr[2] = sc.nextInt();

            double answer = calculateTheGap(arr);
            if (answer == 0) {
                System.out.printf("#%d 0.0\n", t);
            }else{
                System.out.printf("#%d %.1f\n", t, answer);
            }
        }
    }
}