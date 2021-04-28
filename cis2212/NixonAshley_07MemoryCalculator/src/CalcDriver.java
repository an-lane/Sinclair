/*Ashley Nixon
 * Cis 2212-800 Java I Felx Pace
 * Assignment 07- Memory Calculator
 * October 15, 2019
 */
public class CalcDriver {
	public static void main(String[] argv) {
		Calculator calc = new Calculator();
		
		System.out.println("The current value is " + calc.getCurrentValue());
		
		int userOption = Calculator.getMenuOption();
		
		while (userOption != 6) {
			double secondOperand = 0;
			//five is clear. no need to for the second operand.
			if (userOption != 5) {
				secondOperand = Calculator.getOperand("What is the second number? ");
			}
			switch (userOption) {
			case 1:
				calc.add(secondOperand);
				break;
			case 2:
				calc.subtract(secondOperand);
				break;
			case 3:
				calc.multiply(secondOperand);
				break;
			case 4:
				calc.divide(secondOperand);
				break;
			case 5:
				calc.clear();
				break;
			}
			System.out.println("\nThe current value is " + calc.getCurrentValue());
			userOption = Calculator.getMenuOption();
		}
		System.out.println("Thanks for using the memory calculator!");
	}
	
	
}
