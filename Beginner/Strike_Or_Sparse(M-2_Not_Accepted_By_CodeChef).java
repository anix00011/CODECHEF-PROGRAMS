package any;

import java.util.Scanner;

public class sos {
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        while(t-->0) {
            int n = s.nextInt();
            System.out.print("1 "+"1");
            for(int i=0;i<n/2;i++)
            {
                System.out.print("0");
            }
            System.out.println();
        }
    }
}
