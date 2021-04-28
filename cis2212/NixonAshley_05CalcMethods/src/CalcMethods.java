/*Ashley Nixon
 * CIS2212-800 Java I Flex Pace
 * Assignment 05 Calculator With Methods
 * September 28, 2019
 */
import java.util.Scanner;

public class CalcMethods {
	public static int getMenuOption() {
		Scanner input = new Scanner(System.in);
		int selection;
		
		while(true) {//print the menu
			System.out.println("\nMenu\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Generate random number\n6. Quit\n" +
					"\nWhat would you like to do?");
			
				selection = input.nextInt();//get the user menu selection
				if(selection > 0 && selection < 7)//if selection is between 0 and 7
					return selection; //return that selection
				else //if not, smack the user on the hand... politely
					System.out.println("I'm sorry, " + selection + " wasn't one of the options");
		}
	};

	public static double getOperand(String prompt) { //get the operands!
		System.out.println(prompt); //print the prompt
		Scanner input=new Scanner(System.in);//get the user input
		return input.nextDouble();
	};
	
	public static double add(double operand1, double operand2) {//add
		return operand1 + operand2;
	};
	
	public static double subtract(double operand1, double operand2) {//subtract
		return operand1 - operand2;
	};
	
	public static double multiply(double operand1, double operand2) {//multiply
		return operand1 * operand2;
	};
	
	public static double divide(double operand1, double operand2) {//divide
		if(operand2==0)//if zero
		return Double.NaN;//return NaN
		return operand1 / operand2; //else divide
	};
	
	public static double random(double lowerLimit, double upperLimit) {//get random within and upper and lower limit
		return (lowerLimit + Math.random() * (upperLimit - lowerLimit));
	};
	
	/* Okay, so I started with my old case switch... but after analyzing what is needed for this project
	 * and the efficiency of what I was already doing, I decided to switch it to if/else if/else statements
	 * I struggled a bit with this, until I sat down and mapped it out, which really, I should have done
	 * in the first place, despite having part of the code written out prior. It really does help.
	 */
	
	public static void main(String[] args) { //main method
		double lowerLimit,upperLimit,operand1, operand2; //declare doubles
		while(true) { 
			int selection = getMenuOption(); //call the menu selection
			
			if(selection == 6) { //on 6 selections we wear pink... or really close the program...
				System.out.print("Goodbye!");
				System.exit(0);
			} else if (selection == 5) {//on 5 we get random
				lowerLimit = getOperand("What is the lower limit? ");//call Operand for lower limit
				upperLimit = getOperand("what is the upper limit? ");//call Operand for upper limit
				System.out.println("Answer: " + random(upperLimit,lowerLimit)); //call for random
			} else { //if it's not 5 or 6 it'll be found here.
				operand1 = getOperand("What is the first number? "); //call Operand for first number
				operand2 = getOperand("What is the second number? ");//call Operand for second number
				
				if(selection == 1) {//adding
					System.out.println("Answer: " + add(operand1,operand2));
				} else if (selection == 2) {//subtracting
					System.out.println("Answer: " + subtract(operand1,operand2));
				} else if (selection == 3) {//multiplying
					System.out.println("Answer: " + multiply(operand1,operand2));
				} else {//dividing
					System.out.println("Answer: " + divide(operand1,operand2));
				}
			}
		}
	}
}
