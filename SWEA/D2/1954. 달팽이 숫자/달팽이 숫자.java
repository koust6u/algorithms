import java.util.*;
import java.util.stream.Collectors;

class Solution{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 1; t<= T; t++){
            int size = scanner.nextInt();
            if (size == 1){
                System.out.println("#"+t);
                System.out.println(1);
                continue;
            }
            int[][] map = new int[size][size];
            int orientation = 0;
            int index = 2;
            int currentX = 0, currentY = 0;
            map[currentY][currentX] = 1;
            boolean flag = true;
            while(flag){
                switch (orientation){
                    case 0:
                        if(map[currentY][currentX+1] != 0) flag = false;
                        while(currentX+1 < size && map[currentY][currentX+1]==0){
                            map[currentY][++currentX] = index++;
                        }
                        orientation = 1;
                        break;
                    case 1 :
                        if(map[currentY+1][currentX] != 0) flag = false;
                        while(currentY+1 < size && map[currentY+1][currentX]==0){
                            map[++currentY][currentX] = index++;
                        }
                        orientation = 2;
                        break;

                    case 2 :
                        if(map[currentY][currentX-1] != 0) flag = false;
                        while(currentX-1 >=0 && map[currentY][currentX-1]==0){
                            map[currentY][--currentX] = index++;
                        }
                        orientation = 3;
                        break;
                    case 3:
                        if(map[currentY-1][currentX] != 0) flag = false;
                        while(currentY-1 >= 0 && map[currentY-1][currentX]==0){
                            map[--currentY][currentX] = index++;
                        }
                        orientation = 0;
                        break;
                }
            }
            System.out.println("#" + t);
            for (int i =0 ; i < size; i++){
                for (int j = 0; j< size; j++){
                    if (j != size-1)
                        System.out.print(map[i][j] + " ");
                    else System.out.println(map[i][j]);
                }
            }
        }
    }
}