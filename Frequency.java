import java.util.*;

public class Frequency {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the word to be counted");
        String preword = s.nextLine();
        String word = preword.toLowerCase();
        s.close();
        while (!word.equals("")) {
            char letter = word.charAt(0);
            int i = 0, count = 0;
            while (i < word.length()) {
                if (word.charAt(i) == letter) {
                    count++;
                }
                i++;
            }
            System.out.println(letter + " is " + count + " times");
            word = word.replaceAll(String.valueOf(letter), "");
        }
    }
}
