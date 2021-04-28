package nixonFinal;
/* Ashley Nixon
 * CIS 2212-800 Java I Flex Pace
 * Final - Personal Lending Library
 * November 28, 2019
 */

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.geometry.Insets;
import javafx.geometry.Orientation;
import javafx.scene.Scene;

import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Dialog;
import javafx.scene.control.ListView;
import javafx.scene.control.TextInputDialog;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Optional;

public class LibraryGUI extends Application {

	private final int MIN_WIDTH = 100;
	private final int MAX_WIDTH = 175;
    private Library data;

    public static void main(String[] args) {
        launch(args);
    }

    //method to create dialog with input and get input from an user
    public String createAndProcessDialog(String title, String headerText) {
        Dialog textInputDialog = new TextInputDialog();
        textInputDialog.setTitle(title);
        textInputDialog.setHeaderText(headerText);
        Optional<String> itemTitle;
        do {
            itemTitle = textInputDialog.showAndWait();
            if (!itemTitle.isPresent()) { //cancel or close window
            	break;
            }
        } while (!itemTitle.isPresent() || itemTitle.get().isEmpty());
        return itemTitle.get();
    }

    //method to display error alert with given window title and text
    public void displayAlert(String title, String headerText) {
        Alert errorAlert = new Alert(Alert.AlertType.ERROR);
        errorAlert.setTitle(title);
        errorAlert.setHeaderText(headerText);
        errorAlert.showAndWait();
    }

    @Override
    public void start(Stage primaryStage) {
        //creating a list with library items
        ObservableList<MediaItem> items = FXCollections.observableArrayList(data.getItems());
        ListView<MediaItem> itemsList = new ListView<>(items);
        itemsList.setOrientation(Orientation.VERTICAL);
        //add button with action listener
        Button addButton = new Button();
        addButton.setText("Add Item");
        addButton.setStyle("-fx-background-color: #9C89B8; -fx-text-fill: #F0E6EF; -fx-border-width: 1px; -fx-border-color: #B8BEDD;");
        addButton.setMinWidth(MIN_WIDTH);
		addButton.setMaxWidth(MAX_WIDTH);
		addButton.setFont(Font.font("Tahoma", 20));
        addButton.setOnAction(event -> {
            String title = createAndProcessDialog("Add Item", "Enter a title for the new item:");
            String format = createAndProcessDialog("Add Item", "What is the format?");
            data.addNewItem(title, format);
            items.add(data.getItems().get(data.getItems().size()-1));
        });
        //delete button with action listener
        Button deleteButton = new Button();
        deleteButton.setText("Delete Item");
        deleteButton.setStyle("-fx-background-color: #9C89B8; -fx-text-fill: #F0E6EF; -fx-border-width: 1px; -fx-border-color: #B8BEDD;");
        deleteButton.setMinWidth(MIN_WIDTH);
		deleteButton.setMaxWidth(MAX_WIDTH);
		deleteButton.setFont(Font.font("Tahoma", 20));
        deleteButton.setOnAction(event -> {
            MediaItem selectedItem = itemsList.getSelectionModel().getSelectedItem();
            String title;
            if (selectedItem == null) {
            	title = createAndProcessDialog("Delete Item", "Enter the title of the item:");
            	if (title == null) {
            		return;
            	}
            	FilteredList<MediaItem> filteredList = itemsList.getItems().filtered(item -> item.getTitle().equals(title));
            	if (!filteredList.isEmpty()) {
            		selectedItem = filteredList.get(0);
            	}
            } else {
            	title = selectedItem.getTitle();
            }
            try {
            	data.delete(title);
            	items.remove(selectedItem);
            } catch (ItemNotFoundInLibraryException e) {
            	displayAlert("Library error", String.format("Item %s was not found.", title));
            }
            
        });
        //checkout button with action listener
        Button loanButton = new Button();
        loanButton.setText("Checkout");
        loanButton.setStyle("-fx-background-color: #9C89B8; -fx-text-fill: #F0E6EF; -fx-border-width: 1px; -fx-border-color: #B8BEDD;");
        loanButton.setMinWidth(MIN_WIDTH);
		loanButton.setMaxWidth(MAX_WIDTH);
		loanButton.setFont(Font.font("Tahoma", 20));
        loanButton.setOnAction(event -> {
            MediaItem selectedItem = itemsList.getSelectionModel().getSelectedItem();
            String title;
            if (selectedItem == null) {
                title = createAndProcessDialog("Loan A Item", "What is the title of the item being loaned?");
            } else {
                title = selectedItem.getTitle();
            }
            String loanerName = createAndProcessDialog("Checkout", "Who are you loaning it to?");
            String loanDate = createAndProcessDialog("Checkout", "When did you loan it to them?");
            try {
                data.markItemOnLoan(title, loanerName, loanDate);
                itemsList.refresh();
            } catch (ItemNotFoundInLibraryException e) {
                displayAlert("Library error", String.format("The title %s was not found", title));
            } catch (ItemIsAlreadyOnLoanException e) {
                displayAlert("Library error", String.format("The title %s is already on loan", title));
            }
        });
        //check in button with action listener
        Button returnLoanedButton = new Button();
        returnLoanedButton.setText("Check-in");
        returnLoanedButton.setStyle("-fx-background-color: #9C89B8; -fx-text-fill: #F0E6EF; -fx-border-width: 1px; -fx-border-color: #B8BEDD;");
        returnLoanedButton.setMinWidth(MIN_WIDTH);
		returnLoanedButton.setMaxWidth(MAX_WIDTH);
		returnLoanedButton.setFont(Font.font("Tahoma", 20));
        returnLoanedButton.setOnAction(event -> {
            MediaItem selectedItem = itemsList.getSelectionModel().getSelectedItem();
            String title;
            if (selectedItem == null) {
                title = createAndProcessDialog("Check-in", "What is the title of the item being returned?");
            } else {
                title = selectedItem.getTitle();
            }
            try {
                data.markItemReturned(title);
            } catch (ItemNotFoundInLibraryException e) {
                displayAlert("Library error", String.format("The title %s was not found", title));
            } catch (ItemIsNotOnLoanException e) {
                displayAlert("Library error", String.format("The title %s is not on loan", title));
            }
            itemsList.refresh();
        });
        //set application layout
        GridPane root = new GridPane();
        itemsList.setMinWidth(300);
        root.add(itemsList, 0 ,0, 1, 5);
        root.add(addButton, 1, 0);
        root.add(deleteButton, 1, 1);
        root.add(loanButton, 1, 2);
        root.add(returnLoanedButton, 1, 3);
        root.setStyle("-fx-background-color: #F0A6CA;");
        root.setPadding(new Insets(25, 25, 25, 25));
        Scene scene = new Scene(root, 500, 500);
        primaryStage.setTitle("Library GUI application");
        primaryStage.setScene(scene);
        primaryStage.setOnCloseRequest(event -> {
            try {
                data.save();
            } catch (IOException e) {
                displayAlert("Filesystem error", "There was a problem saving the library to the file library.txt");
            }
        });
        primaryStage.show();
    }

    public LibraryGUI() {
        super();
        data = new Library();
        try {
            data.open();
        } catch (FileNotFoundException e) {
            displayAlert("Filesystem error", "Can't find library.txt file. Starting with empty library");
        }
    }
}
