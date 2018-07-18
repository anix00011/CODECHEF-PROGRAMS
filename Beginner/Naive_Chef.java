package any;

import java.util.*;
class NAICHEF
{
    public static void main(String args[])
    {
        Scanner s1 = new Scanner(System.in);
        System.out.println("Enter no. of test cases: ");
        int t = s1.nextInt();
        StringBuffer sb = new StringBuffer();
        while (t-->0)
        {
            double n;
            int a,b;
            System.out.println("Enter no. of faces of die: ");
            n = s1.nextDouble();
            System.out.println("Enter no. on first toss: ");
            a = s1.nextInt();
            System.out.println("Enter no. on second toss: ");
            b = s1.nextInt();
            double hm[] = new double[10];
            Arrays.fill(hm,0.0);
            for(int i=0;i<n;i++)
            {
                System.out.println("Enter "+(i+1)+" no. of dice");
                int val = s1.nextInt();
                hm[val-1]++;
            }
            sb.append(hm[a-1]/n * hm[b-1]/n +"\n");
        }
        System.out.println("Probability is: ");
        System.out.println(sb);
        s1.close();
    }
}