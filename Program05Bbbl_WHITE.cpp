//Imani White
//
//1.Define variables and files
//  a. Open files
//  b. Make the "clock"
//  c. The vecor
//2. Show the unsorted data
//3. Sort the data and start timer
//4. Stop timer and how the sorted data
//5. Done

#include <iostream>
#include <fstream>
#include <vector>//Since I do not know how many elements are my input file (it was given to me late), I need "dynamic" arrays.
				 //I used the textbook for guidance.
#include <ctime>

using namespace std;

// Bubble Sorting: Function prototypes
void bubbleSort(vector<int>&, int, ofstream&);
void showArray(vector<int>, int, ofstream&);

int main() {
	//Creating and Opening Files
	ifstream Infile;
	ofstream BubbleOutfile;
	Infile.open("Prob5.dat");
	BubbleOutfile.open("bubble_IW.dat");
	clock_t T;//Timer
	//Making the Vector
	vector<int> Values;
	int number;//numbers from the document
	int amount;//now may elements are the the vector

	while (Infile >> number) {//This fills the vector
		Values.push_back(number);
	}

	amount = Values.size();

	// Display the values.
	BubbleOutfile << "The unsorted values are\n";
	showArray(Values, amount, BubbleOutfile);
	T = clock();
	// Bubble Sort the values.
	bubbleSort(Values, amount, BubbleOutfile);
	T = clock() - T;
	BubbleOutfile << "This took this many secs: " << ((float)T)/ CLOCKS_PER_SEC;

	//Closing all the files
	Infile.close();
	BubbleOutfile.close();
	//Ending the program
	system("pause");
	return 0;
}

// Definition of function bubbleSort. This is a modification of the bubble sort function from the textbook.
void bubbleSort(vector<int>& vect, int size, ofstream& output) {
	bool change;
	int temp;
	do {
		change = false;
		for (int count = 0; count <(size-1); count++) {
			if (vect.at(count) > vect.at(count + 1)) {
				temp = vect.at(count);
				swap(vect.at(count), vect.at(count + 1));
				vect.at(count + 1) = temp;
				change = true;
			}
		}
	} while (change);

	// Display the sorted values.
	output << "The sorted values are\n";
	for (int count = 0; count < size; count++)
		output << vect.at(count) << " " << endl;
	//output << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}

// Definition of function showArray. This function displays the contents of vect.
void showArray(vector<int> vect, int size, ofstream& output){
	for (int count = 0; count < size; count++)
		output << vect.at(count) << " " << endl;
}