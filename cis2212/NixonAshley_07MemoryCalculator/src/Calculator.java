/*Ashley Nixon
 * Cis 2212-800 Java I Felx Pace
 * Assignment 07- Memory Calculator
 * October 15, 2019
 */
import java.util.Scanner;

public class Calculator {
	private double currentValue; //private double currentValue
	
	public Calculator() {
		currentValue = 0;
	}
	//public static int getMenuOption()
	public static int getMenuOption() {
		//-allow the user to pick from options: add, subtract, multiply, divide, clear and quit.
		boolean isValidOption = false;
		int result = 0;
		Scanner scanner = new Scanner(System.in);
		do {
			System.out.println("\nMenu");
			System.out.println("1. Add");
			System.out.println("2. Subtract");
			System.out.println("3. Multiply");
			System.out.println("4. Divide");
			System.out.println("5. Clear");
			System.out.println("6. Quit");
			System.out.print("\nWhat would you like to do? ");
			String input = scanner.nextLine();
			//verify that the selection is valid
			if (input.isEmpty()) {
				System.out.println("Please select an option.");
			} else {
				if (input.length() > 1) {
					System.out.println("Your selection must contain only one digit. Please try again");	
				} else {
					if (Character.isDigit(input.charAt(0))) {
						result = Integer.parseInt(input);
						if (result > 0 && result <= 6) {
							isValidOption = true;
						} else {
							System.out.println("Your selection must be a digit between 1 and 6. Please try again");
						}
					} else {
						System.out.println("Your selection must be a digit between 1 and 6. Please try again");
					}
				}
			}
		} while (!isValidOption);
		return result;
	}
		
		//public static double getOperand(String prompt)
		public static double getOperand(String prompt) {
			Scanner scanner = new Scanner(System.in);
			System.out.print(prompt);
			double result = scanner.nextDouble();
			return result;
		}
	
	//public double getCurrentValue()
		public double getCurrentValue() {
			return currentValue;
		}
	//-returns the number stored in the currentValue data field
	//-not static
	//public void add(double operand2)
		public void add(double operand2) {
			currentValue += operand2;
		}
	//public void subtract(double operand2)
		public void subtract(double operand2) {
			currentValue -= operand2;
		}
	//public void multiply(double operand2)
		public void multiply (double operand2) {
			currentValue *= operand2;
		}
	//public void divide(double operand2)
		public void divide(double operand2) {
			if (operand2 == 0) {
				currentValue = Double.NaN;
			}else {
				currentValue/=operand2;
			}
		}
	//public void clear()
		public void clear() {
	//-reset the currentValue to Zero
			currentValue = 0;
		}
}
