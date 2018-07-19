package any;

import java.util.*;

class strikeorspare {
    public static void main(String args[])
    {
        int P=0,p=1,q=9;
        Scanner s1=new Scanner(System.in);
        int T=s1.nextInt();
        while(T-->0){
            int N=s1.nextInt();
            for (int j=1;j<N;j++){
                p=p*10;
                q=q*10+9;
            }
            for(int i=p;i<=q;i++){
                StringBuffer s = new StringBuffer(i+"");
                s.reverse();
                String r = s.toString();
                int x=Integer.valueOf(r);
                if(i==x) P++;
            }
            System.out.println(P/P+" "+((q+1)-p)/P);
        }
    }
}
