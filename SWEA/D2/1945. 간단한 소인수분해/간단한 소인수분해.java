import java.util.*;
import java.util.stream.Collectors;

class Solution{
    private final static List<Integer> list = Arrays.asList(2,3,5,7,11);
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++){
            int target = scanner.nextInt();
            int index = 0;
            int[] answer = new int[5];
            while(index < 5){
                while(target % list.get(index) == 0){
                    answer[index] = answer[index]+1;
                    target /= list.get(index);
                }
                index++;
            }
            System.out.print("#"+t+ " ");
            for (int i =0 ; i< 5; i++){
                if (i != 4){
                    System.out.print(answer[i]+ " ");
                }
                else{
                    System.out.println(answer[i]);
                }
            }
        }
    }
}