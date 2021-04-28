package chap11;
/* Ashley Nixon
 * CIS 2212-Java I Flex Pace
 * Assignment 09 Employee Class
 * October 30,2019
 */
import java.text.DecimalFormat; //javarevisited.blogspot.com/2012/03/how-to-format-decimal-number-in-java.html
import java.text.NumberFormat; //tutorials.jenkov.com/java-internationalization/numberformat.html

public class ShiftWorker extends Employee {
	// Employee shift number. The workday is divided into two shifts: day & night
	// Day shift is represented by the number 1 and night shift is rep by the number 2.
	// Night shift workers get paid 1.5 times their rate of pay
	// Example: if Sam works day shift and he earns $20/hr, he would earn $30/hr on night shift.
	private int shiftWorked;
	// Employee pay rate per hour and hours worked
	private double payRatePerHour;
	private double hoursWorked;
	
	// # Default Constructor
	// # -------------------
	public ShiftWorker() {}
	
	// # Overloaded Constructor
	// # ----------------------
	public ShiftWorker(String firstName, String lastName, String phoneNumber, int shiftWorked, double payRatePerHour, double hoursWorked) {
		super(firstName, lastName, phoneNumber);
		this.shiftWorked = shiftWorked;
		this.payRatePerHour = payRatePerHour;
		this.hoursWorked = hoursWorked;
	}
	
	// # Accessor & mutator methods
	// # --------------------------
	// get and set shift worked
	public int getShiftWorked() {
		return shiftWorked;
	}
	public void setShiftWorked(int shiftWorked) {
		this.shiftWorked = shiftWorked;
	}
	
	// get and set pay rate per hour
	public double getPayRatePerHour() {
		return payRatePerHour;
	}
	public void setPayRatePerHour(double payRatePerHour) {
		this.payRatePerHour = payRatePerHour;
	}
	
	//get and set hours worked
	public double getHoursWorked() {
		return hoursWorked;
	}
	public void setHoursWorked(double hoursWorked) {
		this.hoursWorked = hoursWorked;
	}
	
	// Method to calculate employee's total pay for the period (pay rate * shift differential * hours worked)
	public double calculateEmployeeTotalPayPeriod() {
		double shiftDifferential = 1;
		if(shiftWorked == 2) {
			shiftDifferential = 1.5;
		}
		return payRatePerHour * shiftDifferential * hoursWorked;
	}
	
	/*Overridden toString Method to display the employee's full name, phone number, shift number, hourly pay, 
	 * hours worked, and total pay for the period according to their shift. Format the hourly pay and total
	 * pay for currency. Format the hours worked to 2 decimal places.
	 */
	@Override
	public String toString() {
		double totalPayPeriod = calculateEmployeeTotalPayPeriod();
		DecimalFormat df = new DecimalFormat("#.00"); 
		NumberFormat currencyFormat = new DecimalFormat("#,###.00");
		return super.toString() + "\n" +
				"  Shift Worked: " + shiftWorked + "\n" +
				"  Pay Rate: $" + df.format(payRatePerHour) + "\n" + 
				"  Hours Worked: " + df.format(hoursWorked) + "\n" +
				"  Total Pay for Period: $" + currencyFormat.format(totalPayPeriod);
		
	}
}
