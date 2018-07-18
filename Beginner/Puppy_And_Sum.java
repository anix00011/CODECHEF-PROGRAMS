package any;

import java.util.*;

public class PUPPYANDSUM {
    static int sum(int D,int N){
        int s=0;
        for(int i=1;i<=N;i++){
            s=s+i;
        }
        if(D>1){ s=sum(D-1,s);}
        return s;
    }
    public static void main(String args[])
    {
        Scanner s1=new Scanner(System.in);
        System.out.println("Enter no. of test cases: ");
        int t=s1.nextInt();
        while(t-->0){
            System.out.println("Enter no. of times sum to be applied then enter no. to apply over: ");
            int D=s1.nextInt();
            int N=s1.nextInt();
            int sum=sum(D,N);
            System.out.println("Sum is: "+sum);
        }
    }
}
