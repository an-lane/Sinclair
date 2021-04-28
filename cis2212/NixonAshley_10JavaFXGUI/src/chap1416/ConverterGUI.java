package chap1416;
/* Ashley Nixon
 * CIS 2212-800 Java I Flex Pace
 * Assignment 10 JavaFX GUI
 * November 02, 2019
 */

/* I was having a TON of issues getting Eclipse IDE to recognize the javafx library and allow me to actually use it.
 * I did have to google-troubleshoot it and found a solution that would work for me
 * stackoverflow.com/questions/25222811/access-restriction-the-type-application-is-not-api-restriction-on-required-l
 */
import javafx.application.Application;
import javafx.event.*;
import javafx.geometry.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class ConverterGUI extends Application {
	//Buttons and all textfields should have minimum width of 75 and maximum width of 150
	//use constants for these so they are easily changed in one place
	private final int MIN_WIDTH = 810;
	private final int MAX_WIDTH = 150;
	
	private TextField txtUSDollars;
	private TextField txtIndianRupee;
	private TextField txtEuro;
	private TextField txtBritishPounds;
	private TextField txtJapaneseYen;
	private TextField txtKoreanWon;
	
	@Override
	public void start(Stage primaryStage) {
		//title should be JavaFX GUI
		primaryStage.setTitle("JavaFX GUI");
		//GUI should NOT be resizable
		primaryStage.setResizable(false);
		//pane should be positioned in the center
		GridPane gridPane = new GridPane();
		gridPane.setAlignment(Pos.CENTER);
		
		//pane bg WHITESMOKE #F5F5F5 rgb(245, 245, 245)
		gridPane.setStyle("-fx-background-color: #F5F5F5;");
		//padding at 15px top&bottom 10px left&right
		gridPane.setPadding(new Insets(15, 15, 10, 10));
		//horz gap 11
		gridPane.setHgap(11);
		//vert gap 10
		gridPane.setVgap(10);
		
		//label for currency converter should be horizontally positioned in the center (line break)
		//font sz 20pt, family: Rockwell, color: FireBrick #B22222 RGB(178,34,34)
		Label lblCurrencyConverter = new Label("Currency\nConverter");
		GridPane.setHalignment(lblCurrencyConverter, HPos.CENTER);
		lblCurrencyConverter.setFont(Font.font("Rockwell", 20));
		lblCurrencyConverter.setStyle("-fx-text-fill: #B22222");
		
		Label lblUSDollars = new Label("US Dollars");
		//labels for all currencies should be horizontally positioned to the right
		GridPane.setHalignment(lblUSDollars, HPos.RIGHT);
		txtUSDollars = new TextField();
		txtUSDollars.setMinWidth(MIN_WIDTH);
		txtUSDollars.setMaxWidth(MAX_WIDTH);
		GridPane.setHalignment(txtUSDollars, HPos.LEFT);
		
		Label lblIndianRupee = new Label("Indian Rupee");
		GridPane.setHalignment(lblIndianRupee, HPos.RIGHT);
		txtIndianRupee = new TextField();
		//Textfields for foreign currencies should be uneditable
		txtIndianRupee.setEditable(false);
		//textfield bg for currencies should be #A8A8A8 RBG(168, 168, 168)
		txtIndianRupee.setStyle("-fx-background-color: #A8A8A8;");
		txtIndianRupee.setMinWidth(MIN_WIDTH);
		txtIndianRupee.setMaxWidth(MAX_WIDTH);
		GridPane.setHalignment(txtIndianRupee, HPos.LEFT);
		
		Label lblEuro = new Label("EU Euro");
		GridPane.setHalignment(lblEuro, HPos.RIGHT);
		txtEuro = new TextField();
		txtEuro.setEditable(false);
		txtEuro.setStyle("-fx-background-color: #A8A8A8;");
		txtEuro.setMinWidth(MIN_WIDTH);
		txtEuro.setMaxWidth(MAX_WIDTH);
		GridPane.setHalignment(txtEuro, HPos.LEFT);
		
		Label lblBritishPounds = new Label("British Pounds");
		GridPane.setHalignment(lblBritishPounds, HPos.RIGHT);
		txtBritishPounds = new TextField();
		txtBritishPounds.setEditable(false);
		txtBritishPounds.setStyle("-fx-background-color: #A8A8A8;");
		txtBritishPounds.setMinWidth(MIN_WIDTH);
		txtBritishPounds.setMaxWidth(MAX_WIDTH);
		GridPane.setHalignment(txtBritishPounds, HPos.LEFT);
		
		Label lblJapaneseYen = new Label("Japanese Yen");
		GridPane.setHalignment(lblJapaneseYen, HPos.RIGHT);
		txtJapaneseYen = new TextField();
		txtJapaneseYen.setEditable(false);
		txtJapaneseYen.setStyle("-fx-background-color: #A8A8A8;");
		txtJapaneseYen.setMinWidth(MIN_WIDTH);
		txtJapaneseYen.setMaxWidth(MAX_WIDTH);
		GridPane.setHalignment(txtJapaneseYen, HPos.LEFT);
		
		Label lblKoreanWon = new Label("Korean Won");
		GridPane.setHalignment(lblKoreanWon, HPos.RIGHT);
		txtKoreanWon = new TextField();
		txtKoreanWon.setEditable(false);
		txtKoreanWon.setStyle("-fx-background-color: #A8A8A8;");
		txtKoreanWon.setMinWidth(MIN_WIDTH);
		txtKoreanWon.setMaxWidth(MAX_WIDTH);
		GridPane.setHalignment(txtKoreanWon, HPos.LEFT);
		
		//buttons on all text fields should be horizontally positioned left
		//button for convert should be:
		//BG color FireBrick #B22222 RGB(178,34,34) fontsize: 10
		//Family: Papyrus, text color White #FFFFFF rgb(225,225,225)
		Button btnConvert = new Button();
		btnConvert.setText("Convert");
		btnConvert.setStyle("-fx-background-color: #B22222; -fx-text-fill: #FFFFFF");
		btnConvert.setFont(Font.font("Papyrus", 10));
		btnConvert.setMinWidth(MIN_WIDTH);
		btnConvert.setMaxWidth(MAX_WIDTH);
		btnConvert.setPrefHeight(30);
		btnConvert.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				
			}
		});
		
		//Buttons for Clear and Exit
		//Background color DarkSlateGrey #2F4F4F rgb(47,79,79)
		//size 10, family Papyrus
		//text Yellow #FFFF00 rgb(225,225,0)
		Button btnClear = new Button();
		btnClear.setText("Clear");
		btnClear.setStyle("-fx-background-color: #2F4F4F; -fx-text-fill: #FFFF00");
		btnClear.setFont(Font.font("Papyrus", 10));
		btnClear.setMinWidth(MIN_WIDTH);
		btnClear.setMaxWidth(MAX_WIDTH);
		btnClear.setPrefHeight(30);
		btnClear.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				
			}
		});
		
		Button btnExit = new Button();
		btnExit.setText("Exit");
		btnExit.setStyle("-fx-background-color: #2F4F4F; -fx-text-fill: #FFFF00");
		btnExit.setFont(Font.font("Papyrus", 10));
		btnExit.setMinWidth(MIN_WIDTH);
		btnExit.setMaxWidth(MAX_WIDTH);
		btnExit.setPrefHeight(30);
		btnExit.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				
			}
		});
		
		gridPane.add(lblCurrencyConverter, 1, 0);
		
		gridPane.add(lblUSDollars, 0, 2);
		gridPane.add(txtUSDollars, 1, 2);
		
		gridPane.add(lblIndianRupee, 0, 4);
		gridPane.add(txtIndianRupee, 1, 4);
		
		gridPane.add(lblEuro, 0, 5);
		gridPane.add(txtEuro, 1, 5);
		
		gridPane.add(lblBritishPounds, 0, 6);
		gridPane.add(txtBritishPounds, 1, 6);
		
		gridPane.add(lblJapaneseYen, 0, 7);
		gridPane.add(txtJapaneseYen, 1, 7);
		
		gridPane.add(lblKoreanWon, 0, 8);
		gridPane.add(txtKoreanWon, 1, 8);
		
		gridPane.add(btnConvert, 1, 9);
		gridPane.add(btnClear, 1, 10);
		gridPane.add(btnExit, 1, 11);
		
		Scene scene = new Scene(gridPane);
		
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	// # @param args the command land arguments
	public static void main(String[] args) {
		launch(args);
	}

}
