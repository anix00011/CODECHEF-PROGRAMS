import java.io.IOException;
import java.math.BigInteger;
import java.util.*;
    class t5 {
    public static void main(String[] args)throws IOException {
        try {
            Scanner s1 = new Scanner(System.in);
            int t = s1.nextInt();
            String x;
            String y;
            while (t-- > 0) {
                int c1 = 0;
                x = s1.next();
                y = s1.next();
                for (int i = 0; i < x.length(); i++)
                    if (x.charAt(i) == '1')
                        c1++;
                int c2 = 0;
                for (int i = 0; i < y.length(); i++)
                    if (y.charAt(i) == '1')
                        c2++;
                if (c1 > 0 && c2 > 0) {
                    char[] a = new char[c1];
                    Arrays.fill(a, '1');
                    char[] b = new char[c2];
                    Arrays.fill(b, '1');
                    System.out.println(new BigInteger(String.valueOf(a)).multiply(new BigInteger(String.valueOf(b))));
                }else System.out.println("0");
            }
        }
        catch (Exception e){}
    }
}
