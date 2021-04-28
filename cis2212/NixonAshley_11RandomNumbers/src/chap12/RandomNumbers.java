package chap12;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/* Ashley Nixon
 * CIS 2212-800 Java I Flex Pace
 * Assignment 11 Random Numbers
 * 11/07/2019
 */


public class RandomNumbers {
	public static void main(String[] args) {
		Locale.setDefault(new Locale("en-US", "en-US"));
		Scanner keyBoard = new Scanner(System.in);
		//create an array of 25 random numbers between 0 & 250, formatted to a field width of 10 & 4 decimal places
		double[] randomNumbers=new double[25];
		String absolutePath="";
		try {
			PrintWriter printWriter = null;
			try {
				//open file "randNums.txt"
				File file = new File("randNums.txt");
				printWriter = new PrintWriter(file);
				//display the array of a random number on the console and write to a file
				for(int i=0;i<25;i++) {
					randomNumbers[i] = Math.random() * 250;
					//random numbers are formatted with field width of 10 & 4 decimal places
					System.out.printf("%10.4f\n", randomNumbers[i]);
					//save to file "randNums.txt"
					printWriter.printf("%10.4f\n", randomNumbers[i]);
				}
				//get absolute path
				absolutePath = file.getAbsolutePath();
			} catch (IOException e) {
				System.out.println("File not found\n"+e);
			} finally {
				//close file
				printWriter.close();
			}
			System.out.print("\nEnter an index: ");
			int index = keyBoard.nextInt();
			System.out.printf("\nThe element at index %d is %.4f\n", index,randomNumbers[index]);
		} catch(IndexOutOfBoundsException exp) {
			System.out.println("The index chosen is out of bounds");
			System.out.println(exp+"\n");
		} finally {
			keyBoard.close();
			System.out.println("(finally clause) Scanner object is closed");
		}
		//full file path is displayed
		System.out.println("File path: "+absolutePath);
	}

}
