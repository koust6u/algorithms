import java.util.Scanner;
import java.io.FileInputStream;
import java.util.*;
/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        for(int i = 0; i < count; i++){
            int size = scanner.nextInt();
            int[][] matrix = new int[size][size];
            for(int j = 0; j < size; j++){
                for(int k = 0; k <= j; k++){
                    if(k == 0) matrix[j][k] = 1;
                    else{
                        matrix[j][k] = matrix[j-1][k] + matrix[j-1][k-1];
                    }
                }
            }
            System.out.println("#" + (i+1));
            for(int j= 0; j < size; j++){
                for(int k = 0; k< size; k++){
                    if(matrix[j][k] == 0) break;
                    System.out.print(matrix[j][k] +  " ");
                }
                System.out.println();
            }
        }
    }
}