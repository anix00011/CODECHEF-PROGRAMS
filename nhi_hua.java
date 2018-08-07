import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

    class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

 class hp2 {
    static int calc(int n){
        int y=n;
        int x=0;
        int k=0;
        while(x!=2||k!=2){
            x=Integer.toBinaryString(n).replaceAll("0","").length();
            k=Integer.toBinaryString(y).replaceAll("0","").length();
            if(x!=2) n--;
            if(k!=2) y++;
            if(x==2) return n;
            if(k==2) return y;
        }
        return 0;
    }
    public static void main(String args[])
    {
        FastReader s1=new FastReader();
        int t=s1.nextInt();
        while(t-->0) {
            int n = s1.nextInt();
            int y , z = n;
            int s = calc(n);
            System.out.println(Math.abs(z - s));
        }
    }
}
