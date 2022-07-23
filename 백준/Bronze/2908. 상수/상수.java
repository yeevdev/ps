import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        char[] a = st.nextToken().toCharArray();
        char[] b = st.nextToken().toCharArray();

        char[] adj_a = new char[a.length];
        char[] adj_b = new char[b.length];
        for(int i = 0; i < a.length; i++) {
            adj_a[i] = a[a.length - i - 1];
        }
        for(int i = 0; i < b.length; i++) {
            adj_b[i] = b[b.length - i - 1];
        }

        int A, B;
        A = Integer.valueOf(String.valueOf(adj_a));
        B = Integer.valueOf(String.valueOf(adj_b));

        if(A > B) {
            bw.write(String.valueOf(A));
        }
        else {
            bw.write(String.valueOf(B));
        }

        bw.flush();
        bw.close();
        br.close();

    }
}
