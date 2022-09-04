import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;

public class Paper {
    
    public static void main(String[] args) {

        try (BufferedReader file = new BufferedReader(new FileReader("C:\\adv\\2015\\2\\input.txt"))) {

            int area = 0;
            int ribbon = 0;

            String line = null;
            while ((line = file.readLine()) != null) {
                area += area(line.split("x"));
                ribbon += ribbon(line.split("x"));
            }

            System.out.println(area);
            System.out.println(ribbon);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static int area(String[] dim) {

        int area = 0;
        
        ArrayList<Integer> dimensions = new ArrayList<Integer>();
        for (String string : dim) {
            dimensions.add(Integer.parseInt(string));
        }
        
        for (int length_1 : dimensions) {
            for (int length_2 : dimensions) {
                area += length_1 * length_2;
            }
            area -= length_1 * length_1;
        }
        
        int slack = slack(dimensions);

        return (area + slack);
    }

    public static int slack(ArrayList<Integer> dimensions) {

        int slack = 1;

        ArrayList<Integer> smallest = smallest(dimensions, dimensions.size() - 1);

        for (int small : smallest) {
            slack *= small;
        }

        return slack;
    }

    public static int ribbon(String[] dim) {

        int ribbon = 1;

        ArrayList<Integer> dimensions = new ArrayList<Integer>();
        for (String string : dim) {
            dimensions.add(Integer.parseInt(string));
        }

        for (int length : dimensions) {
            ribbon *= length;
        }

        ArrayList<Integer> smallest = smallest(dimensions, dimensions.size() - 1);
        
        for (int small : smallest) {
            ribbon += 2 * small;
        }

        return ribbon;
    }

    public static ArrayList<Integer> smallest (ArrayList<Integer> dimensions, int dim) {

        ArrayList<Integer> result = new ArrayList<Integer>();

        for (int i = 0; i < dim; i++) {
            int[] smallest = smallest(dimensions);
            result.add(smallest[1]);
            dimensions.remove(smallest[0]);
        }

        return result;
    }

    public static int[] smallest(ArrayList<Integer> dimensions) {

        for (int i = 0; i < dimensions.size(); i++) {
            boolean flag = true;
            for (int comparison : dimensions) {
                if (dimensions.get(i) != comparison && dimensions.get(i) > comparison) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                int[] result = { i, dimensions.get(i) };
                return result;
            }
        }

        return null;
    }
}
