/* Ashley Nixon
 * CIS 2212-800 JavaI flex Pace
 * Assignment 08 - Students Driver
 * October 25, 2019
 */
public class Students {
	private String firstName;
	private String lastName;
	private int studentID;
	private int birthYear;
	private final int CURRENT_YEAR = 2019;
	//range for students age is from 13 years old to 100 years old, inclusive
	private final int YOUNGEST_AGE = 13;
	private final int OLDEST_AGE = 100;
	//range for student ID is 54000 to 54999, inclusive
	private final int LOW_ID = 54000;
	private final int HIGH_ID = 54999;
	
	//The students class using the no-arg constructor
	public Students() {
		this.firstName = "deafult";
		this.lastName = "default";
		this.studentID = LOW_ID;
		this.birthYear = YOUNGEST_AGE;
	}
	
	//the students class using the arg constructor: param first, param last, param studentID, param birthYear
	public Students(String first, String last, int studentID, int birthYear) {
		setFirstName(first);
		setLastName(last);
		setStudentID(studentID);
		setBirthYear(birthYear);
	}
	//get user input for student objects: first name, last name, studentID, birth year 
	//and then populate the object using setters
	//function allowing to return first name
	
	//get and set first name
	public String getFirstName() {
		return this.firstName;
	}
	
	public void setFirstName (String firstName) {
		this.firstName = firstName;
	}
	
	//get and set last name
	public String getLastName() {
		return this.lastName;
	}
	
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	//get and set ID
	public int getStudentID() {
		return this.studentID;
	}
	
	public void setStudentID (int studentID) {
		if(validateID(studentID) != -1) {
			this.studentID = studentID;
		}
	}
	
	//get and set birth year
	public int getBirthYear() {
		return this.birthYear;
	}
	
	public void setBirthYear(int birthYear) {
		if(validateYr(birthYear) != -1) {
			this.birthYear = birthYear;
		}
	}
	
	//get current year
	public int getCurrentYear() {
		return this.CURRENT_YEAR;
	}
	
	//get youngest age
	public int getYoungestAge() {
		return this.YOUNGEST_AGE;
	}
	
	//get oldest age
	public int getOldestAge() {
		return this.OLDEST_AGE;
	}
	
	//get lowest ID
	public int getLowID() {
		return this.LOW_ID;
	}
	
	//get Highest Id
	public int getHighId() {
		return this.HIGH_ID;
	}
	
	//validate ID
	public int validateID(int id) {
		//if the id is lower OR higher than the range, then request again
		if(id < LOW_ID || id > HIGH_ID) {
			System.out.print("ID range is " + LOW_ID + " to " + HIGH_ID + ". Please try again: ");
			return -1;
		}
		return id;
	}
	
	//validate year
	public int validateYr(int yr) {
		int startYear = CURRENT_YEAR - OLDEST_AGE;
		int endYear = CURRENT_YEAR - YOUNGEST_AGE;
		//if the year is less than or greater than the range, request again
		if(yr < startYear || yr > endYear) {
			System.out.print("Range is " + startYear + " to " + endYear + ". Please try agian: ");
			return -1;
		}
		return yr;
	}
	
	//calculate age
	public int calcAge() {
		return this.CURRENT_YEAR - 	birthYear;
	}
	
	//return info about student
	public String toString() {
		return this.firstName + " " + this.lastName + "\n" +
				"  Student ID: " + this.studentID + "\n" +
				"  Age in " + CURRENT_YEAR + ": " + calcAge() + " years old\n";
	}
}
