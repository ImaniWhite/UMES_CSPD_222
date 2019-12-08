#include <iostream>
#include <string>

//1. Define the variables
//  a. The array of the number of pounds of feed eaten 3x7
//  b. Greatest and smallest
//  c.Average
//    i. The total of the numbers added together
//    ii. Count of how many numbers there are
//2. Fill the 2D array with the information
//   a. Prompt User
//   b. Fill the array with for loops
//   c. Make sure the user cannot enter a negative number
//3. Check for the greatest and smallest amount throughout the week for each elephant
//   a. Use two for loops
//    i. Initialize great and small to the first element in a row
//    ii. If statements for both
//       If the element we are checking is greater than the greatest/less than the smallest, then make that the now greatest/smallest
//   b. Output results
//4. Average out how much is fed per day to all three elephants
//   a. Use two for loops to add the numbers and then divise by how many numbers there are
//   b. Output results

using namespace std;

int main() {
	//VARIABLES
	double Feeding[3][7];//Each row is an elephant and each column is a day of the week

	void Naming(int, string&);//We'll have row 1 be Rollo, row 2 be Bessie, and row 3 be Gertrude
    string elephant;//Names of the elephants

	int greatest,smallest;//greatest and smallest

	double average = 0.0;//the average of the feed in a day
	double total = 0.0;//total for average
	int count = 0.0;//count for average
	int dayCount = 0;//couting the days to display

	//INPUT
	for (int x = 0; x < 3; x++) {//Filling the array with user input
		for (int y = 0; y < 7; y++) {
			Naming(x, elephant);
			cout << "Enter " << elephant << "'s feed in lbs for the week for day "<< (y+1) << endl;
			cin>>Feeding[x][y];
			while (Feeding[x][y] < 0) {//input validation
				cout << "The amount of feed must be postive. Enter again." << endl;
				cin >> Feeding[x][y];
			}
		}
	}

	cout << "\n" << "///////////////////////////////////////////" << endl;

	//GREATEST SMALLEST
	for (int a = 0; a < 3; a++) {//outer loop: rows of elephants
		greatest = Feeding[a][0];//for each row, set the greatest and smallest to the first element in that row
		smallest = Feeding[a][0];

		for (int b = 0; b < 7; b++) {//inner loop: cols of feeding days
			Naming(a, elephant);//Name the elephants

			if (Feeding[a][b] > greatest)
				greatest = Feeding[a][b];

			else if (Feeding[a][b] < smallest)
				smallest = Feeding[a][b];
		}
		cout << elephant << ": \nGreatest: " << greatest << "\nSmallest: " << smallest << "\n" <<endl;
	}

	//AVERAGE
	for (int colu = 0; colu < 7; colu++){
		for (int row = 0; row < 3; row++){
			total += Feeding[row][colu];
			count++;
		}
		average = total / count;
		dayCount++;
		cout << "The day "<< dayCount <<" average is: " << average << endl;
	}
	//END
	system("pause");
	return 0;
}

void Naming(int outerVar, string &name){//Using a switch statement, this will determine the name of the elephant of the row
	switch (outerVar) {                 //This was used to organize the input and output a little bit
		case 0:
			name = "Rollo";
			break;
		case 1:
			name = "Bessie";
			break;
		default:
			name = "Gertrude";
			break;
	}
}