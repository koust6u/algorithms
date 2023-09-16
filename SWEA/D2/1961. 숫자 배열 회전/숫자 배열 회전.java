import java.util.*;
import java.util.stream.Collectors;

class Solution{
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1 ; t <= T; t++){
            int N = sc.nextInt();
            int[][][] answer = new int[3][N][N];
            int[][] matrix = new int[N][N];
            for (int i =0; i < N ; i++){
                for (int j = 0; j< N; j++){
                    matrix[i][j]= sc.nextInt();
                }
            }
            answer[0] = rotate(matrix);
            answer[1] = rotate(answer[0]);
            answer[2] = rotate(answer[1]);
            System.out.println("#"+ t);
            for (int i = 0; i < N; i++){
                StringBuilder a = new StringBuilder();
                StringBuilder b = new StringBuilder();
                StringBuilder c = new StringBuilder();
                for (int j = 0; j< N; j++){
                    a.append(answer[0][i][j]);
                    b.append(answer[1][i][j]);
                    c.append(answer[2][i][j]);
                }
                System.out.println(a+ " "+ b+" " +c);
            }
        }
    }

    private static int[][] rotate(int[][] matrix){
        int [][] answer = new int[matrix.length][matrix.length];
        for (int i = 0; i < matrix.length; i++){
            for (int j= 0; j< matrix.length; j++){
                answer[i][j]= matrix[matrix.length -1 -j][i];
            }
        }
        return answer;
    }
}