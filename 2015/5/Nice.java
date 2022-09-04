import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Nice {

    public static void main(String[] args) {

        int counter = 0;

        try (BufferedReader file = new BufferedReader(new FileReader("input.txt"))) {

            String line = null;
            while((line = file.readLine()) != null) {
                if (isNice(line)) {
                    counter++;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println(counter);
    }

    public static boolean isNice(String input) {

        boolean flag_1 = false;
        boolean flag_2 = false;

        ArrayList<String> string = new ArrayList<>();
        for (String character : input.split("")) {
            string.add(character);
        }
        
        for (int i = 0; i < (string.size() - 2); i++) {
            if ((string.get(i)).equals(string.get(i+2))) {
                flag_1 = true;
                break;
            }
        }
        
        for (int i = 0; i < (string.size() - 1); i++) {
            ArrayList<String> array = string;
            String char_1 = array.get(0);
            String char_2 = array.get(1);
            array.remove(0);
            array.remove(1);

            for (int n = 0; n < (array.size() - 1); n++) {
                if ((char_1 + char_2).equals(array.get(n) + array.get(n+1))) {
                    flag_2 = true;
                    break;
                }
            }
        }

        if (flag_1 && flag_2) {
            return true;
        } else {
            return false;
        }
    }
}