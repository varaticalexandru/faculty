import java.util.Scanner;


public class Main {
	
	private static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {
		// citeste 2 nr. de la tastatura si afiseaza suma lor
		
		int x, y;
		
		System.out.print("x: ");
		x = scan.nextInt();
		
		System.out.print("y: ");
		y = scan.nextInt();
		
		System.out.println("\n" + x + " + " + y + " = " + (x+y));

	}

}
