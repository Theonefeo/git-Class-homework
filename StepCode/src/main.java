import java.util.Arrays;
import java.util.Locale;
/**
 * Checks if given <code>text<code/> is a palindrome
 * @param text any sting
 * @return <code>true<code/> when <code>text<code/> is a palindrome, <code>false<code/> otherwise
 * @author !FeodorKarpov!
 * @Step10.Part2.3 in 2.
 */


import static java.lang.System.out;

public class main {
    public static void main(String[] args) {
        String Madam = "Madam, I'm Adam!";
        Madam = Madam.replaceAll("[^A-Za-zA-Яа-а0-9]*", "");
        String madam = Madam.toLowerCase();
        String reverseMadam = new StringBuilder(madam).reverse().toString();
        boolean equals = madam.equals(reverseMadam);
        String result = Boolean.toString(equals);
        out.println(result);

        out.println("Programm this fine!:-)");
    }
}