package chap11;
/* Ashley Nixon
 * CIS 2212-Java I Flex Pace
 * Assignment 09 Employee Class
 * October 30,2019
 */
public class Employee {
	//Employee first name, last name, phone number
	private String firstName;
	private String lastName;
	private String phoneNumber;
	
	// # Default Constructor
	// # -------------------
	public Employee() {
		this.firstName = "default";
		this.lastName = "default";
		this.phoneNumber = "default";
	}
	
	// # Overloaded Constructor
	// # ----------------------
	public Employee(String firstName, String lastName, String phoneNumber) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.phoneNumber = phoneNumber;
	}
	
	// # Accessor and Mutator Methods
	// # -----------------------------
	
	// get and set first name
	public String getFirstName() {
		return firstName;
	}
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	// get and set last name
	public String getLastName() {
		return lastName;
	}
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	// get and set phone number
	public String getPhoneNumber() {
		return phoneNumber;
	}
	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}
	
	// Overridden toString method to display the employee's full name and phone number
	@Override
	public String toString() {
		return "Name: " + this.firstName + " " + this.lastName + "\n" +
				"  Phone: " + this.phoneNumber;
	}
	

}
