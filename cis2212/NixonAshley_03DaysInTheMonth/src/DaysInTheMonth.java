/* Ashley Nixon
 * CIS2212-800 Java I Flex Pace
 * Assignment 03 Days In The Month
 * September 10, 2019
 */
import java.util.Scanner;

public class DaysInTheMonth {

	public static void main(String[] args) {
		//ints and strings
		int year = 0; String month;
		Scanner input = new Scanner(System.in);
		//print title of program
		System.out.print("How Many Days in a Month\n");
		// Ask user for 4 digit year
		System.out.print("Enter a 4-digit year (ex: 2018, 2019): ");
		year = input.nextInt();
		input.nextLine(); /*<-Makes sure that the end of the line that contained the 
		 				   *int is consumed before it tries to read more input!
		 				   *stackoverflow.com/questions/27717503/why-does-my-scanner-repeat
		 				   */
		// Ask user for Month
		System.out.print("Enter a month (ex: Jan Feb Mar): ");
		month = input.nextLine();
		
		// debug statement below meant to help figure out why nextInt was repeating on line 25 instead of taking new data. 
		//System.out.println(year + " " + month); 
		
		/*while I like case, since we're working with 3 letter months and not numbers. 
		 * else/if statements would be better.*/

		//NOTE to self: == compares identity, not value, so use the .equals(string) method
		//First check off the months that would have 31 days. 
		if ( month.equals("Jan")|| month.equals("Mar") || month.equals("May") || month.equals("Jul") || month.equals("Aug") || month.equals("Oct") || month.equals("Dec") ) {
			System.out.println( month + " " + year + " = 31 days");
		} else if (month.equals("Apr") || month.equals("Jun") || month.equals("Sep") || month.equals("Nov") ){
		//second check off the months that would have 30 days
			System.out.println( month + " " + year + " = 30 days");
		} else if (month.equals("Feb") ) {
		//third get my birth month February and determine if it's a leap year or not
			if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 !=0))) {
				System.out.println( month + " " + year + " = 29 days");
			} else {
				System.out.println( month + " " + year + " = 28 days");
			}
		} else {
		//else this is the wrong way to enter a month, and this should return an error
			System.out.println( month + " is not a correct month name");
		}
		

	}

} 
