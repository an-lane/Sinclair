/* Ashley Nixon
 * CIS 2212-800 Java I Flex Pace
 * Midterm - Personal Lending Library
 * October 20, 2019
 */
public class MediaItem {
	
	private String title;//string title
	
	private String format;//string format
	
	private boolean onLoan;//boolean onLoan
	
	private String loanedTo;//string loanedTo
	
	private String dateLoaned;//string dateLoaned
	
	//init with default values
	public MediaItem() {
		title = null;
		format = null;
		onLoan = false;
		loanedTo = null;
		dateLoaned = null;
	}
	
	//init with given title and format
	public MediaItem(String title, String format) {
		this.title = title;
		this.format = format;
		onLoan = false;
		loanedTo = null;
		dateLoaned = null;
	}
	
	public void markOnLoan(String name, String date) {
		if(!onLoan) { //if not already on lone, get name of who it is loaned to, and date it was loaned, and mark it as onLoan
			loanedTo = name;
			dateLoaned = date;
			onLoan = true;
		} else { //if it is already on loan, say who it was loaned to.
			System.out.println(title + " is already on loan to " + loanedTo);
		}
	}
	
	public void markReturned() {
		if (onLoan) { //if it is marked onLoan, clear name and date, and turn onLoan boolean to false
			loanedTo = null;
			dateLoaned = null;
			onLoan = false;
		} else { //if not onLoan, reminder that it is not on loan.
			System.out.println(title+" is not currently on loan");
		}
	}
	
	//create string message about all initialized text fields in the class
	public String getDescription() {
		String itemDescription = String.format("%s (%s)", title, format);
		if (isOnLoan()) { //hey look, it's on loan, 
			itemDescription += String.format(" loaned to %s on %s", loanedTo, dateLoaned);
		}
		return itemDescription;
	}
	
	//below are the getter and setter methods for each
	//get and set title
	public String getTitle() { 
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}
	
	//get and set format
	public String getFormat() {
		return format;
	}
	
	public void setFormat(String format) {
		this.format = format;
	}
	
	//get and set if it is on loan
	public boolean isOnLoan() {
		return onLoan;
	}
	
	public void setOnLoan(boolean onLoan) {
		this.onLoan = onLoan;
	}
	
	//get and set who is it loaned to
	public String getLoanedTo() {
		return loanedTo;
	}
	
	public void setLoanedTo(String loanedTo) {
		this.loanedTo = loanedTo;
	}
	
	//get and set the date loaned on
	public String getDateLoaned() {
		return dateLoaned;
	}
	
	public void setDateLoaned(String dateLoaned) {
		this.dateLoaned = dateLoaned;
	}
}
