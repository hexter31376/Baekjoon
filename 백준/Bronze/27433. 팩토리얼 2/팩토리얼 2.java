import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long input = Integer.parseInt(st.nextToken());
        bw.write(Long.toString(factorial(input))+"\n");
        bw.flush();
    }

    public static long factorial(long n) {
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
    }
}