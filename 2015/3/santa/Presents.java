package santa;

import java.util.ArrayList;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

public class Presents {
    
    public static void main(String[] args) {
        
        ArrayList<Cell> cache = new ArrayList<>();

        int x_1 = 0;
        int y_1 = 0;
        int x_2 = 0;
        int y_2 = 0;

        Cell box_start = new Cell(x_1,y_1);
        cache.add(box_start);
        
        try (BufferedReader file = new BufferedReader(new FileReader("C:\\adv\\2015\\3\\santa\\input.txt"))) {

            String line = null;
            while((line = file.readLine()) != null) {
                String[] characters = line.split("");

                ArrayList<String> characters_1 = new ArrayList<>();
                ArrayList<String> characters_2 = new ArrayList<>();
                for (int i = 0; i < characters.length; i++) {
                    if ((int)(i%2) == 0) {
                        characters_1.add(characters[i]);
                    } else if ((int)(i%2) == 1) {
                        characters_2.add(characters[i]);
                    }
                }

                for (String dir : characters_1) {

                    if (dir.equals("<")) {

                        x_1 -= 1;

                    } else if (dir.equals("^")) {

                        y_1 += 1;

                    } else if (dir.equals(">")) {

                        x_1 += 1;

                    } else if (dir.equals("v")) {

                        y_1 -= 1;

                    } else {
                        System.out.println("Error");
                    }

                    boolean flag = true;
                    for (Cell box : cache) {
                        if (box.getX() == x_1 && box.getY() == y_1) {
                            flag = false;
                            box.index += 1;
                        }
                    }

                    if (flag) {
                        Cell box = new Cell(x_1,y_1);
                        cache.add(box);
                    }
                }

                for (String dir : characters_2) {

                    if (dir.equals("<")) {

                        x_2 -= 1;

                    } else if (dir.equals("^")) {

                        y_2 += 1;

                    } else if (dir.equals(">")) {

                        x_2 += 1;

                    } else if (dir.equals("v")) {

                        y_2 -= 1;

                    } else {
                        System.out.println("Error");
                    }

                    boolean flag = true;
                    for (Cell box : cache) {
                        if (box.getX() == x_2 && box.getY() == y_2) {
                            flag = false;
                            box.index += 1;
                        }
                    }

                    if (flag) {
                        Cell box = new Cell(x_2, y_2);
                        cache.add(box);
                    }
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println(cache.size());
    }
}