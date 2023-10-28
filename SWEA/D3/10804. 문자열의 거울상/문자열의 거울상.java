import java.util.Scanner;

class Solution {

    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int T = Integer.parseInt(sc.nextLine());

        for(int t = 1; t <= T; t++){
            String origin = sc.nextLine();
            StringBuilder sb = new StringBuilder(origin);
            sb = sb.reverse();
            StringBuilder answer = new StringBuilder();
            for (int i =0 ; i< sb.length(); i++){
                if (sb.charAt(i) == 'b')
                    answer.append('d');
                else if (sb.charAt(i) =='d')
                    answer.append('b');
                else if (sb.charAt(i) == 'q')
                    answer.append('p');
                else answer.append('q');
            }
            System.out.println("#"+t+" "+ answer);
        }
    }
}