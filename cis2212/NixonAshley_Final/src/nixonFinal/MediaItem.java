package nixonFinal;
/* Ashley Nixon
 * CIS 2212-800 Java I Flex Pace
 * Final - Personal Lending Library
 * November 28, 2019
 */
public class MediaItem {

    private String title;
    private String format;
    private boolean onLoan;
    private String loanedTo;
    private String dateLoaned;

    //default values
    public MediaItem() {
        title = null;
        format = null;
        onLoan = false;
        loanedTo = null;
        dateLoaned = null;
    }

    //given title and format
    public MediaItem(String title, String format) {
        this.title = title;
        this.format = format;
        onLoan = false;
        loanedTo = null;
        dateLoaned = null;
    }

    public void markOnLoan(String name, String date) throws ItemIsAlreadyOnLoanException {
        if (!onLoan) {
            loanedTo = name;
            dateLoaned = date;
            onLoan = true;
        } else {
            throw new ItemIsAlreadyOnLoanException();
        }
    }

    public void markReturned() throws ItemIsNotOnLoanException {
        if (onLoan) {
            loanedTo = null;
            dateLoaned = null;
            onLoan = false;
        } else {
            throw new ItemIsNotOnLoanException();
        }
    }

    //create string message about all initialized text fields in the class
    public String getDescription() {
        String itemDescription = String.format("%s (%s)", title, format);
        if (isOnLoan()) {
            itemDescription+=String.format(" loaned to %s on %s", loanedTo, dateLoaned);
        }
        return  itemDescription;
    }

    public String getDescriptionForFile() {
        char separator = 127;
        return String.format("%s%c%s%c%s%c%s%c%s\n", title, separator, format, separator, onLoan, separator, loanedTo, separator, dateLoaned);
    }

    @Override
    public String toString() {
        return getDescription();
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getFormat() {
        return format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public boolean isOnLoan() {
        return onLoan;
    }

    public void setOnLoan(boolean onLoan) {
        this.onLoan = onLoan;
    }

    public String getLoanedTo() {
        return loanedTo;
    }

    public void setLoanedTo(String loanedTo) {
        this.loanedTo = loanedTo;
    }

    public String getDateLoaned() {
        return dateLoaned;
    }

    public void setDateLoaned(String dateLoaned) {
        this.dateLoaned = dateLoaned;
    }
}
