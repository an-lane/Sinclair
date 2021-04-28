/*Ashley Nixon
 * CIS2212-800 Java I Flex Pace
 * Assignment 06 Donations Array
 * October 12, 2019
 */
import java.util.Scanner;
import java.text.NumberFormat;

public class DonationsArray {

	public static void main(String[] args) {
		
		
		NumberFormat currency = NumberFormat.getCurrencyInstance();//currency object
		
		System.out.print("Political Donations Tracker\n---------------------------");
		
		int NUM_DONORS = 17; //declares the variable number for donors. 
		/*Because the instructions said don't write it in but the output example 
		 * didn't have a 'get the number from the user'. I went with this, though part
		 * of me wanted to ask the user, it really isn't that many more steps, but 
		 * wanted to make sure I followed the expected output.
		 */

		// donorName: a String array to hold the first and last names of donors.
		String []donorName = new String[NUM_DONORS];
		//amtDonated: an array of doubles to hold the amount of the donation.
		double [] amtDonated = new double [NUM_DONORS];
		//numDonations: an array of integers to hold the number of times the donation will be made
		int [] numDonations = new int [NUM_DONORS];
		//totalDonation: an array of doubles to hold the total donation made by each donor
		double [] totalDonation = new double [NUM_DONORS];
		//grandTotalDonations: a double to hold the sum of all donations from all donors
		double grandTotalDonations = 0.00;
		
		//looping below to get donation information
		for (int i = 0; i < NUM_DONORS; i++) {
			//scanner object
			Scanner input = new Scanner(System.in);
			
			System.out.println("\nDonor #" + (i + 1));
			System.out.print("Donor name: ");
			donorName[i] = input.nextLine(); //What's my donors name?
			//System.out.println(donorName[i]); debug line!
			
			System.out.print("Amount of Donation: ");
			amtDonated[i] = input.nextDouble(); //How much they gimme?
			//input.nextLine();
				//this needs validated, because it cannot be less than $5.00
				while(amtDonated[i] < 5.00) {
					System.out.print("\tMinimum donation is $5.00. Please try again: ");
					amtDonated[i] = input.nextDouble();
				}
			
			System.out.print("Number of Donations: ");
			numDonations[i] = input.nextInt(); //How many donations did they make?
				//once again needs validated because it cannot be less than 1.
				while(numDonations[i] < 1) {
					System.out.print("\tThere must be at least 1 donation. Please try again: ");
					numDonations[i] = input.nextInt();
				}
			
			//calculate the total donations for the donor
			totalDonation[i] = (amtDonated[i] * numDonations[i]);
		} //!--End of Loop--!
		
		System.out.println("\nPolitical Donations\n--------------------");
		//loop that will display all the donors and donations
		for (int i = 0; i < NUM_DONORS; i++ ) {
			System.out.println("Donor #" + (i + 1));
			System.out.println("  Donor: " + donorName[i]);
			System.out.println("  Amount of Donation: " + currency.format(amtDonated[i]));
			System.out.println("  Number of Donations: " + numDonations[i]);
			System.out.println("  Total from Donor: " + currency.format(totalDonation[i]));
			System.out.println("---------------------");
			
			//calculate all the donations from all donors
			grandTotalDonations += totalDonation[i];
		} //!--End of Loop--!
		
		//finally print the final grand total of the donations.
		System.out.println("\nGrand Total of Donations: " + currency.format(grandTotalDonations));

	}

}
