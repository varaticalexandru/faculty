package test;

public class MainApp {
    public static void main(String[] args) {
        StringBuilder string = new StringBuilder("abcd ABCD");


        for (int i = 0; i < string.length(); i++) {
            string.setCharAt(i, (char) ( ((int)string.charAt(i)) + 1));
        }


        System.out.println(string);
    }
}
