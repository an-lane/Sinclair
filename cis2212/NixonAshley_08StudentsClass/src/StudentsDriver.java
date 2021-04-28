/* Ashley Nixon
 * CIS 2212-800 JavaI flex Pace
 * Assignment 08 - Students Driver
 * October 25, 2019
 */
import java.util.Scanner;
public class StudentsDriver {

	public static void main(String[] args) {
		//Scanner
		Scanner input = new Scanner(System.in);
		String firstName, lastName;
		int studentID = -1, birthYear = -1;
		
		//one object is initialized with user input using the Students class setters
		Students newStudent = new Students();
		
		//get First Name from user
		System.out.print("Enter First Name: ");
		firstName = input.nextLine();
		//get Last Name from user
		System.out.print("Enter Last Name: ");
		lastName = input.nextLine();
		//set first name
		newStudent.setFirstName(firstName);
		//set last name
		newStudent.setLastName(lastName);
		
		boolean isCorrectValue = false;
		//get Student ID from user
		System.out.print("\nEnter Student ID: ");
		studentID = input.nextInt();
		while(!isCorrectValue) {
			newStudent.setStudentID(studentID);
			//check if the Student ID is correct
			if(newStudent.getStudentID() != studentID) {
				studentID = input.nextInt(); //if student id is not correct set to false
				isCorrectValue = false;
			} else {
				isCorrectValue = true; //if student id IS correct set to true
			}
		}
			
		isCorrectValue = false;
		//get a 4-Digit Year of birth from the user
		System.out.print("\nEnter 4-Digit Year of Birth: ");
		birthYear = input.nextInt();
		while(!isCorrectValue) {
			//set birth year
			newStudent.setBirthYear(birthYear);
			//check if year of birth is correct
			if(newStudent.getBirthYear() != birthYear) {
				birthYear = input.nextInt();//if birth year is not correct set to false
				isCorrectValue = false;
			} else {
				isCorrectValue = true; //if it is correct set to true
			}
		}
		
		/*two objects are initialized using the Students class overloaded constructor.
		 *create & initialize 2 objects of the Students class using the overloaded constructor.
		 *Personal note:I'm Fairly certain this is exactly what is being asked for
		 */
		//first name = Lisa Ann; last name = Larraby; student id= 54321; birth year =1993
		Students student1 = new Students("Lisa Ann", "Larraby", 54321, 1993);
		//first name = Karl; last name = Van der Hutten; student id= 54123; birth year =1983
		Students student2 = new Students("Karl", "Van der Hutten", 54123, 1983);
		//call the class toString to display the output for each object as noted in sample output
		System.out.println("\n" + newStudent.toString()); //print student entered
		System.out.println(student1.toString()); //print student 1
		System.out.println(student2.toString()); //print student 2
		
		input.close(); //I noticed this in the java program at work and think somehow I missed it in the book 
						//researched more about it https://www.geeksforgeeks.org/scanner-close-method-in-java-with-examples/
	}

}
