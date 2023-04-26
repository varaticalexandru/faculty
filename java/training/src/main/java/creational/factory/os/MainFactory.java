package creational.factory.os;

import java.util.Scanner;

public class MainFactory {
    public static void main(String[] args) {

        OSFactory factory = new OSFactory();
        Scanner scanner = new Scanner(System.in);
        String input = "";

        do {
            System.out.print("\nOS type ?: ");
            input = scanner.nextLine();

            OS os = factory.getInstance(input);
            os.spec();

        }
        while (!input.isBlank());

    }
}
