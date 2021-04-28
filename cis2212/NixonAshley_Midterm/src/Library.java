/* Ashley Nixon
 * CIS 2212-800 Java I Flex Pace
 * Midterm - Personal Lending Library
 * October 20, 2019
 */
import java.util.Scanner;

public class Library {
	//maxium possible amount of items in the library
	final private static int MAX_ITEMS = 100;
	
	private MediaItem[] items; //array to hold all the items in the Library. (100 items)
	
	private int numberOfItems; //number of items actually stored in the array. increases whenever an item is added
	
	private static Scanner scanner;
	
	public Library() {
		items = new MediaItem[MAX_ITEMS];
		numberOfItems = 0;
	}
	
	//ask user for the input and perform string validation
	//I only programmed the only not empty validation since instructions were unclear
	private static String askUserForString(String outputLine, String name) {
		String typedValue;
		do {
			System.out.print(outputLine);
			typedValue = scanner.nextLine();
			if (typedValue.isEmpty()) {//if it's empty re-prompt
				System.out.println(String.format("Sorry, the %s can't be empty", name));
			}
		} while (typedValue.isEmpty());
		return typedValue;
	}
	
	public static void main(String[] argv) {
		Library myLibrary = new Library();
		scanner = new Scanner(System.in);
		int userOption = myLibrary.displayMenu();
		
		//if user types 5 - we close the program
		while (userOption != 5) {
			switch (userOption) {
			//add new item
			case 1: 
				String title = askUserForString("What is the title? ", "title"); //get title
				String format = askUserForString("What is the format? ", "format"); //get format
				myLibrary.addNewItem(title, format);//add to the library
				break;
			//loan an item
			case 2: 
				title = askUserForString("Witch item?(enter the title) ", "title");//get title
				String loanedTo = askUserForString("Who are you loaning it to? ", "loaner name");//who loaned to
				String loanDate = askUserForString("When did you loan it to them? ", "loan date");//on what date
				myLibrary.markItemOnLoan(title, loanedTo, loanDate);//add to library
				break;
			//print all items
			case 3:
				String[] itemsDescription = myLibrary.listAllItems();
				for (String itemDesc : itemsDescription) {
					System.out.println(itemDesc);//print out the arrays based on what is already in the library
				}
				break;
			//return an item
			case 4:
				title = askUserForString("Which item?(enter the title) ", "title");
				myLibrary.markItemReturned(title);
				break;
			}
			userOption = myLibrary.displayMenu();
		}
		System.out.println("Goodbye!");
	}
	
	public int displayMenu() {
		boolean isValidOption = false;
		int result = 0;
		Scanner scanner = new Scanner(System.in);
		do {
			System.out.println("\n1. Add New Item");
			System.out.println("2. Mark an item as on loan");
			System.out.println("3. List all items");
			System.out.println("4. Mark an item as returned");
			System.out.println("5. Quit");
			System.out.print("\nWhat would you like to do? ");
			String userInput = scanner.nextLine();
			//verify that the option is valid
			if (userInput.isEmpty()) {
				System.out.println("No selection was made, please select an option");
			} else {
				if (userInput.length() > 1) {
					System.out.println("Selection must contain only one digit. Please try again");
				} else {
					if (Character.isDigit(userInput.charAt(0))) {
						result = Integer.parseInt(userInput);
						if (result > 0 && result <= 5) {
							isValidOption = true;
						} else {
							System.out.println("Selection must be a digit between 1 and 5. Please try again");
						}
					} else {
						System.out.println("Selection must be a digit between 1 and 5. Please try again");
					}
				}
			}
		} while (!isValidOption);
		return result;
	}
	
	public void addNewItem(String title, String format) {
		if (numberOfItems >= MAX_ITEMS) {
			System.out.println("Sorry, the library is already full");
		} else {
			MediaItem newItem = new MediaItem(title, format);
			items[numberOfItems] = newItem;
			numberOfItems++;
		}
	}
	
	public void markItemOnLoan(String title, String name, String date) {
		for (int i=0; i < numberOfItems; i++) {
			if (items[i].getTitle().equals(title)) {
				items[i].markOnLoan(name, date);
				return;
			}
		}
		System.out.println(String.format("I'm sorry, I couldn't find %s in the library", title));
	}
	
	public String[] listAllItems() {
		String[] results = new String[numberOfItems];
		for (int i = 0; i < numberOfItems; i++) {
			results[i] = items[i].getDescription();
		}
		return results;
	}
	
	public void markItemReturned(String title) {
		for (int i= 0; i < numberOfItems; i++) {
			if (items[i].getTitle().equals(title)) {
				items[i].markReturned();
				return;
			}
		}
		System.out.println(String.format("I'm sorry, I couldn't find %s in the library", title));
	}
}
