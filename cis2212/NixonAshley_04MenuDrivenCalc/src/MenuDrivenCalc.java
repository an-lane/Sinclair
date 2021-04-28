/*Ashley Nixon
 * CIS2212-800 Java I Flex Pace
 * Assignment 04 Menu Driven Calculator
 * September 18, 2019
 */
import java.util.Scanner;

public class MenuDrivenCalc {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double lower, upper, one, two;
		int selection, count = 0;
		
		//Menu loop
		while (true) {
			System.out.println("Menu\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Generate Random Number\n6. Quit\n" +
					"\nWhat would you like to do?");
			
				selection = input.nextInt();
		
				switch (selection) {
				case 1:{//Add two numbers
					System.out.println("What is the first number?"); 
					one = input.nextDouble(); //get user input of first number
					System.out.println("What is the second number?");
					two = input.nextDouble(); //get user input of second number
					System.out.println("Answer: " + (one+two) + "\n"); //print first plus second number
					count = 0;
					break;
				}
				case 2:{//Subtract two numbers
					System.out.print("What is the first number?");
					one = input.nextDouble();
					System.out.println("What is the second number?");
					two = input.nextDouble();
					System.out.println("Answer: " + (one-two) + "\n"); //print first minus second number
					count = 0;
					break;
				}
				case 3:{//Multiply two numbers
					System.out.println("What is the first number?");
					one = input.nextDouble();
					System.out.println("What is the second number?");
					two = input.nextDouble();
					System.out.println("Answer: " + (one*two) + "\n"); //print first times second number
					count = 0;
					break;
				}
				case 4:{//Divide two numbers
					System.out.println("What is the first number?");
					one = input.nextDouble();//get user input for first number
					System.out.println("What is the second number?");
					two = input.nextDouble();//get user input for second number
					
					if(two == 0)//may not divide by zero.
						System.out.println("I'm sorry, you can't divide by zero.\n"); //reject zero
					else
						System.out.println("Answer: " + (one/two) + "\n"); //if not zero, divide
					count =0;
					break;
				}
				case 5:{//Generate random number within a given range
					System.out.println("What is the lower limit?");
					lower = input.nextDouble(); //take the users lower limit input
					System.out.println("What is the Upper limit?");
					upper = input.nextDouble(); //take the users upper limit input
					System.out.println("Answer: " + (lower + Math.random() * (upper - lower)) + "\n");
					count = 0;
					break;
				}
				case 6:{
					System.out.print("Goodbye!");
					System.exit(0);
				}
				default:{//count for the loop
					count++;
					System.out.println("I'm sorry " + selection + " wasn't one of the options.\n");	
				}
				}
				if(count == 3) {
					System.out.print("Please try again later.");
					System.exit(0);
				}
		}
	}
}
