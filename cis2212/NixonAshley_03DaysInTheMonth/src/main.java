import java.util.Scanner;

import java.util.*;

import java.text.*;

public class main{

public static void main(String []args){

System.out.println("Political Donations Tracker ----------------------------");
int numDonors = 2;
String []donorName=new String[numDonors];

double []amtDonated=new double[numDonors];

double []totalDonation=new double[numDonors];

int []numDonations=new int[numDonors];

double grandTotalDonations=0.0;

for(int i=0;i<numDonors;i++)

{ Scanner in = new Scanner(System.in);

System.out.print("Donor:");

donorName[i]=in.nextLine();

//System.out.println(donorName[i]);

System.out.print("Amount of Donation:");

amtDonated[i]=in.nextDouble();

//System.out.println(amtDonated[i]);

while(amtDonated[i]<5.0)

{

System.out.println("Minimum donation is $5.00.");

System.out.print("Please try again:");

amtDonated[i]=in.nextDouble();

// System.out.println(amtDonated[i]);

}

System.out.print("Number of Donations:");

numDonations[i]=in.nextInt();

//System.out.println(numDonations[i]);

while(numDonations[i]<1)

{

System.out.println("There must be at least 1 donation.");

System.out.print("Please try again:");

numDonations[i]=in.nextInt();

// System.out.println(numDonations[i]);

}

totalDonation[i]=numDonations[i]*amtDonated[i];

grandTotalDonations = grandTotalDonations + totalDonation[i];

}

System.out.println("Political Donations-------------------------");

for(int i=0;i<numDonors;i++)

{ System.out.print("Donor #"+(i+1)+"Donor:"+donorName[i]);

System.out.print("Amount of Donation: $"+amtDonated[i]);

System.out.println("Total from Donor: $"+totalDonation[i]);

}

NumberFormat nf = NumberFormat.getInstance(Locale.US);   

System.out.println("Grand Total of Donations: $"

                    + nf.format(grandTotalDonations));

}

}