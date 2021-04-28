package nixonFinal;
/* Ashley Nixon
 * CIS 2212-800 Java I Flex Pace
 * Final - Personal Lending Library
 * November 28, 2019
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Library {

    private List<MediaItem> items;

    public List<MediaItem> getItems() {
        return items;
    }

    public Library() {
        items = new ArrayList<>();
    }

    public void addNewItem(String title, String format) {
            MediaItem newItem = new MediaItem(title, format);
            items.add(newItem);
    }

    public void delete(String title) throws ItemNotFoundInLibraryException {
        int numberOfItems = items.size();
        for (int i=0; i<numberOfItems; i++) {
            if (items.get(i).getTitle().equals(title)) {
                items.remove(i);
                return;
            }
        }
        throw new ItemNotFoundInLibraryException();
    }

    public void save() throws IOException {
            FileWriter fileWriter = new FileWriter("library.txt");
            int numberOfItems = items.size();
            for (int i = 0; i < numberOfItems; i++) {
                fileWriter.write(items.get(i).getDescriptionForFile());
            }
            fileWriter.close();
    }

    public void open() throws FileNotFoundException {
            Scanner fileScanner = new Scanner(new File("library.txt"));
            fileScanner.useDelimiter("\u007F|\\R");
            while (fileScanner.hasNext()) {
                MediaItem newItem = new MediaItem();
                newItem.setTitle(fileScanner.next());
                newItem.setFormat(fileScanner.next());
                newItem.setOnLoan(fileScanner.nextBoolean());
                newItem.setLoanedTo(fileScanner.next());
                newItem.setDateLoaned(fileScanner.next());
                items.add(newItem);
            }
    }

    public void markItemOnLoan(String title, String name, String date) throws ItemNotFoundInLibraryException, ItemIsAlreadyOnLoanException {
        int numberOfItems = items.size();
        for (int i=0; i<numberOfItems; i++) {
            if (items.get(i).getTitle().equals(title)) {
                items.get(i).markOnLoan(name, date);
                return;
            }
        }
        throw new ItemNotFoundInLibraryException();
    }

    public String[] listAllItems() {
        int numberOfItems = items.size();
        String[] results = new String[numberOfItems];
        for (int i=0;i<numberOfItems;i++) {
            results[i]=items.get(i).getDescription();
        }
        return results;
    }

    public void markItemReturned(String title) throws ItemNotFoundInLibraryException, ItemIsNotOnLoanException {
        int numberOfItems = items.size();
        for (int i=0; i<numberOfItems; i++) {
            if (items.get(i).getTitle().equals(title)) {
                items.get(i).markReturned();
                return;
            }
        }
        throw new ItemNotFoundInLibraryException();
    }
}
