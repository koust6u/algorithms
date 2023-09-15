
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        int result = 0;
        for(int i = 1; i <= number; i++){
            result += i;
        }
        System.out.println(result);
	}
}