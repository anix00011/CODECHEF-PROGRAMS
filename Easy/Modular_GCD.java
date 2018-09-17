package hp1;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

    class mgcd {
    static BigInteger mod;
    static BigInteger Y;
    static BigInteger Z;
    static BigInteger D;
    public static void main(String[] args) {
        FastReader s1=new FastReader();
        int t=s1.nextInt();
        BigInteger A;
        BigInteger B;
        BigInteger N;
        mod = new BigInteger("1000000007");
        while(t-->0){
            A=new BigInteger(s1.next());
            B=new BigInteger(s1.next());
            N=new BigInteger(s1.next());
            D=A.subtract(B);
            if(D.longValue()==0){
                    Y=A.modPow(N,mod).add(B.modPow(N,mod));
                    Z=Y;
            }else{
                Y=(A.modPow(N,D).add(B.modPow(N,D)));
                Z=Y.gcd(D);
            }
            System.out.println(Z);
        }
    }
}
