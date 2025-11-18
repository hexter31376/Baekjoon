
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        // IO
        BufferedReader reader = new BufferedReader(new java.io.InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new java.io.OutputStreamWriter(System.out));

        // Input
        int inputNumber = Integer.parseInt(reader.readLine());

        // Process
        for (int line = 1; line <= inputNumber; line++) {
            for (int space = 1; space <= inputNumber - line; space++) {
                writer.write(" ");
            }
            for (int star = 0; star - 1 < (2 * line - 2); star++) {
                writer.write("*");
            }
            writer.newLine();
        }
        for (int line = inputNumber - 1; line >= 1; line--) {
            for (int space = 1; space <= inputNumber - line; space++) {
                writer.write(" ");
            }
            for (int star = 0; star - 1 < (2 * line - 2); star++) {
                writer.write("*");
            }
            writer.newLine();
        }
        writer.flush();
    }
}
