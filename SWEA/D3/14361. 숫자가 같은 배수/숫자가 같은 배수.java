import java.util.*;
class Solution{

    private static String target;
    private static List<String> list;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = Integer.parseInt(sc.nextLine());
        for (int t = 1; t <=T ;t++){
            list = new ArrayList<>();
            target = sc.nextLine();
            permutation("", target);
            if (isDividable()) System.out.println("#"+t+" possible");
            else System.out.println("#"+t+ " impossible");
        }
    }

    private static boolean isDividable(){
        for (String s : list) {
            if(Integer.parseInt(s) %Integer.parseInt(target) == 0) return true;
        }
        return false;
    }
    private static void permutation(String prefix,String remainder) {
        int n = remainder.length();
        if (n == 0 && Integer.parseInt(target) < Integer.parseInt(prefix)) list.add(prefix);
        else {
            for (int i =0 ; i< n ; i++){
                permutation(prefix + remainder.charAt(i), remainder.substring(0, i) + remainder.substring(i+1,n));
            }
        }
    }
}