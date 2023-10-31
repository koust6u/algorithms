import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static int numberOfOperands;

    private static int[] operators = new int[4];
    private static List<Integer> operands= new ArrayList<>();
    private static Scanner scanner;

    private static int max = Integer.MIN_VALUE;
    private static int min = Integer.MAX_VALUE;
    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        numberOfOperands = scanner.nextInt();
        for (int i = 0; i< numberOfOperands; i++){
            operands.add(scanner.nextInt());
        }
        for (int i = 0 ; i < 4; i++){
            operators[i] = scanner.nextInt();
        }
        backTracking(operands.get(0), 1);
        System.out.println(max);
        System.out.println(min);
        scanner.close();
    }

    private static void backTracking(int answer, int index){
        if (index == numberOfOperands){
            if (min > answer){
                min = answer;
            }
            if (max < answer){
                max = answer;
            }
        }
        for (int i = 0 ; i < 4; i++){
            if (operators[i] != 0){
                operators[i]--;
                if (i == 0){
                    backTracking(answer + operands.get(index), index+1);
                }
                else if (i == 1){
                    backTracking(answer - operands.get(index), index+1);
                }
                else if (i == 2){
                    backTracking(answer * operands.get(index), index+1);
                }
                else{
                    backTracking(answer / operands.get(index), index+1);
                }
                operators[i]++;
            }
        }
    }
}