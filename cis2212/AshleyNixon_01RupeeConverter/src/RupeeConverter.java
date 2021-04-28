/*Ashley Nixon
 * CIS2212-800 Java I Flex Pace
 * Assignment 01 - Rupee Converter
 * August 30, 2019
 */
import java.util.Scanner;

public class RupeeConverter {

	public static void main(String[] args) {
		//set exchange rate constant
		final double USD = 1;
		final double INR = 71.23;
		// print assumed exchange rate
		System.out.println("Exchange rate assumed to be " + USD + " US Dollar to " + INR + " Rupee.\n");
		
		//scanner class to get input
		Scanner value = new Scanner(System.in);
		
		//Ask how many dollars to rupees and get user input
		System.out.println("How many dollars would you like to convert to rupees: ");
		double dollarValue = value.nextDouble();
		
		//return and print the amount converted
		double dollarToRupee = dollarValue * INR;
		System.out.println("You will receive " + dollarToRupee + " rupee(s) for " + dollarValue + " dollar(s). \n");
		
		//Ask how many rupees to dollars and get user input
		System.out.println("How many rupees would you like to convert to dollars: ");
		double rupeeValue = value.nextDouble();
		
		//return and print the amount converted
		double rupeeToDollar = rupeeValue / INR;
		System.out.println("You will receive " + rupeeToDollar + " dollar(s) for " + rupeeValue + " rupee(s).");

	}

}
