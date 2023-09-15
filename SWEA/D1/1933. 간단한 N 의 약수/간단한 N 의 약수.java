import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        
        for(int i = 1 ; i <= count/2; i++){
            if(count % i == 0) System.out.print(i + " "); 
        }
        System.out.print(count);
	}
}