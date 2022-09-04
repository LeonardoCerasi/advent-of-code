import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Floors {

    public static void main(String[] args) {

        try (BufferedReader file = new BufferedReader(new FileReader("C:\\adv\\2015\\1\\input.txt"))) {

            String condition = "()";

            int floor = 0;
            
            String line= null;
            while((line = file.readLine()) != null) {
                for (int i = 0; i < line.length(); i++) {
                    if (line.charAt(i) == condition.charAt(0)) {
                        floor++;
                    } else if (line.charAt(i) == condition.charAt(1)) {
                        floor--;
                    } else {
                        System.out.println("Input error");
                    }

                    if (floor == -1) {
                        System.out.println(i+1);
                    }
                }
            }

            System.out.println(floor);

        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}