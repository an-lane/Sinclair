/*Ashley Nixon
 *CIS2212-800 Java I Flex Pace
 *Assignment 02 Basic Calculator
 *September 3, 2019 
 */
import java.util.Scanner;

public class BasicCalculator {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		//Menu
		System.out.println("Menu\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Generate Random Number\n" +
		"\nWhat would you like to do?");
		
		int selection = input.nextInt();
		double lower, upper, one, two;
		
		switch (selection) {
		case 1:{//Add two numbers
			System.out.println("What is the first number?"); 
			one = input.nextDouble(); //get user input of first number
			System.out.println("What is the second number?");
			two = input.nextDouble(); //get user input of second number
			System.out.println("Answer: " + (one+two)); //print first plus second number
			break;
		}
		case 2:{//Subtract two numbers
			System.out.print("What is the first number?");
			one = input.nextDouble();
			System.out.println("What is the second number?");
			two = input.nextDouble();
			System.out.println("Answer: " + (one-two)); //print first minus second number
			break;
		}
		case 3:{//Multiply two numbers
			System.out.println("What is the first number?");
			one = input.nextDouble();
			System.out.println("What is the second number?");
			two = input.nextDouble();
			System.out.println("Answer: " + (one*two)); //print first times second number
			break;
		}
		case 4:{//Divide two numbers
			System.out.println("What is the first number?");
			one = input.nextDouble();//get user input for first number
			System.out.println("What is the second number?");
			two = input.nextDouble();//get user input for second number
			
			if(two == 0)//may not divide by zero.
				System.out.println("I'm sorry, you can't divide by zero."); //reject zero
			else
				System.out.println("Answer: " + (one/two)); //if not zero, divide
			break;
		}
		case 5: {//Generate a random number within a given range
			System.out.println("What is the lower limit?");
			lower = input.nextDouble(); //take the users lower limit input
			System.out.println("What is the Upper limit?");
			upper = input.nextDouble(); //take the users upper limit input
			System.out.println("Answer: " + (lower + Math.random() * (upper - lower)));
			break;
		}
		default:
			System.out.println("I'm sorry " + selection + " wasn't one of the options.");
			
		}System.exit(0);	
	}
}
