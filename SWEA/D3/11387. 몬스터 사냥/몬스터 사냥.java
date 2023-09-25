import java.util.*;
class Solution{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <=T ;t++){
            int D,L,N;
            D = sc.nextInt();
            L = sc.nextInt();
            N = sc.nextInt();
            long answer = (long) D *N;
            for (int i = 0; i < N; i++){
                answer += (D*((double)i * (double)L/100));
            }
            System.out.println("#"+t+" "+ answer);
        }
    }

}