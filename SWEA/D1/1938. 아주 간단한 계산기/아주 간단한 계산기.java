import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		
		Scanner scanner = new Scanner(System.in);
        int lhs = scanner.nextInt();
        int rhs = scanner.nextInt();
       
        System.out.println(lhs+rhs);
        System.out.println(lhs-rhs);
        System.out.println(lhs*rhs);
        System.out.println(lhs/rhs);
	}
}