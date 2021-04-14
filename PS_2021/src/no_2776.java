import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class no_2776 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t, n, m, temp;
        t = sc.nextInt();
        while (t-- > 0) {
            HashSet<Integer> set = new HashSet<Integer>();
            ArrayList<Integer> list = new ArrayList<Integer>();
            n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                temp = sc.nextInt();
                set.add(temp);
            }
            m = sc.nextInt();
            for (int i = 0; i < m; i++) {
                temp = sc.nextInt();
                list.add(temp);
            }
            for(int i = 0;i < m; i++){
                if(set.contains(list.get(i))){
                    System.out.println(1);
                }else{
                    System.out.println(0);
                }
            }
        }
    }
}
