import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {

    private static int totalNumberOfMembers;
    private static int numberOfTeamMembers;
    private static final Scanner scanner= new Scanner(System.in);
    private static int answer = Integer.MAX_VALUE;
    private static int[][] matrix;
    public static void main(String[] args) {

        inputFromConsole();
        backTrack(new ArrayList<>(), 0);
        System.out.println(answer);
    }


    private static void inputFromConsole(){
        totalNumberOfMembers = scanner.nextInt();
        matrix = new int[totalNumberOfMembers][totalNumberOfMembers];
        for (int i = 0 ; i < totalNumberOfMembers; i++){
            for (int j = 0 ; j < totalNumberOfMembers; j++){
                matrix[i][j] = scanner.nextInt();
            }
        }
        numberOfTeamMembers = totalNumberOfMembers/2;
    }
    private static void backTrack(List<Integer> list, int idx){
        if (list.size() == numberOfTeamMembers){
            int result  = getDifference(list);
            if (result < answer){
                answer = result;
            }
            return;
        }
        for (int i = idx ; i < totalNumberOfMembers; i++){
            List<Integer> param = new ArrayList<>(list);
            param.add(i);
            backTrack(param, i+1);
        }
    }

    private static int getDifference(List<Integer> list){
        List<Integer> exclusive= IntStream.range(0, totalNumberOfMembers)
                .filter(e -> !list.contains(e)).boxed()
                .collect(Collectors.toList());
        int a = totalPoint(list);
        int b = totalPoint(exclusive);
        return Math.abs(a-b);
    }


    private static int totalPoint(List<Integer> list){
        int answer = 0;
        for (int i = 0 ; i < list.size(); i++){
            for (Integer integer : list) {
                answer += matrix[list.get(i)][integer];
            }
        }
        return answer;
    }


}