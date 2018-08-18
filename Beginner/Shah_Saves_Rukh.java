
import java.util.*;
import java.io.*;

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
class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
        writer.flush();
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
        writer.flush();
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }
}

    class mgcd {
    static long f1(long n){
        if(n==1) return 1;
        if(n%2==1) return 2*f1(n/2)+1;
        else return 2*f1(n/2)-1;
    }
    static long f2(long n){
        if(n==2) return 2;
        if(n==3) return 1;
        if(n%2==1) return 2*f2(n/2)+1;
        else return 2*f2(n/2)-1;
    }
    public static void main(String[] args) {
        FastReader s1 = new FastReader();
        OutputWriter out=new OutputWriter(System.out);
        int t = s1.nextInt();
        while (t-- > 0) {
            long n=s1.nextLong();
            out.printLine(f1(n)+" "+f2(n));
        }
    }
}
