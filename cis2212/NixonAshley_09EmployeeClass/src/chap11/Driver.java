package chap11;
/* Ashley Nixon
 * CIS 2212-Java I Flex Pace
 * Assignment 09 Employee Class
 * October 30,2019
 */
import java.util.ArrayList;
import java.util.Scanner;
public class Driver {

	// # Main Method
	// # -----------
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//I usually put the following in the same line if possible, but I caught the 
		//book saying that keeping it on different lines is better for easier reading.
		String firstName;
		String lastName;
		String phoneNumber;
		int shiftWorked;
		double payRatePerHour;
		double hoursWorked;
		
		//create an instance of a Shiftworker object & init the object with the user input using the class setter methods
		ShiftWorker shiftWorker=new ShiftWorker();
		//get user input either in the console or with dialog boxes for employee name, phone number, shift, hourly payrate
		//and hours worked this period.
		//get first name from user
		System.out.print("Employee's first name: ");
		firstName = input.nextLine();
		//get last name from user
		System.out.print("Employee's last name: ");
		lastName = input.nextLine();
		//phone number
		System.out.print("Employee's phone (937-555-1212): ");
		phoneNumber = input.nextLine();
		//get shift from user
		System.out.print("Shift (1-day or 2-night): ");
		shiftWorked = input.nextInt();
		while(shiftWorked < 1 || shiftWorked > 2) {
			System.out.print("Shift number is 1 or 2. Please try again: ");
			shiftWorked = input.nextInt();
		}
		
		//get pay rate per hour from user
		System.out.print("Pay rate per hour: ");
		payRatePerHour = input.nextDouble();
		while(payRatePerHour < 0) {
			if(payRatePerHour < 0) {
				System.out.print("Pay rate per hour should be 0 or greater. Please try again: ");
				payRatePerHour = input.nextDouble();
			}
		}
		
		//hours worked this period from user
		System.out.print("Hours worked this period: ");
		hoursWorked = input.nextDouble();
		while(hoursWorked < 0) {
			//hours worked should be 0 or greater
			if(hoursWorked < 0) {
				System.out.print("Hours worked should be 0 or greater. Please try again: ");
				hoursWorked = input.nextDouble();
			}
		}
		
		//set name, phone, shift, pay rate and hours
		shiftWorker.setFirstName(firstName);
		shiftWorker.setLastName(lastName);
		shiftWorker.setPhoneNumber(phoneNumber);
		shiftWorker.setShiftWorked(shiftWorked);
		shiftWorker.setPayRatePerHour(payRatePerHour);
		shiftWorker.setHoursWorked(hoursWorked);
		
		//create at least one more instance of a ShiftWorker object & initialize the objects for a different employee.
		//This time, initialize the objects using the overloaded constructor.
		Employee employee1 = new ShiftWorker("Don","Griffith","937-222-1234",2,18.75,40.00);
		Employee employee2 = new ShiftWorker("Chuck","Banner","937-898-4567",1,25.00,41.75);
		
		//to demonstrate polymorphism & dynamic binding, create at least 1 more instance of an object using Employee or Object as
		//the declared type and ShiftWorker as the actual type. Initialize the objects using the overloaded constructor
		Employee employee3 = new Employee("Peter","Smith","937-222-8954");
		
		//Create an arraylist named employeelist of the objects created in your program. thn display the size of the arraylist and the
		//elements. reminder: you may need to cast objects.
		ArrayList<Employee> employeeList = new ArrayList<Employee>();
		employeeList.add(shiftWorker);
		employeeList.add(employee1);
		employeeList.add(employee2);
		employeeList.add(employee3);
		
		//to display ArrayList objects i chose a for loop
		System.out.println("\nEmployee List contains " + employeeList.size() + " elements:\n[");
		for (int i = 0; i < employeeList.size()-1; i++) {
			System.out.println(employeeList.get(i).toString() + ",");
		}
		System.out.println(employeeList.get(employeeList.size()-1).toString() + "\n]");
		
		//close keyboard
		input.close();
	}
}
