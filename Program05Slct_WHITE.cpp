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
#include <vector>//Since I do not know the size of my input file (it was given to me late), I need "dynamic" arrays.
                 //I used the textbook for guidance.
#include <ctime>

using namespace std;

// Selection Sorting: Function prototypes
void selectionSort(vector<int>&, int, ofstream&);
void showArray(vector<int>, int, ofstream&);

int main(){
	ifstream Infile;
	ofstream SelectionOutfile;
	Infile.open("Prob5.dat");
	SelectionOutfile.open("selection_IW.dat");
	clock_t T;//Timer
	vector<int> Values;
	int number;
	int amount;

	while (Infile >> number) {
		Values.push_back(number);
	}

	amount = Values.size();

	 // Display the values.
	 SelectionOutfile << "The unsorted values are\n";
	 showArray(Values, amount, SelectionOutfile);
	
	 T = clock();
	 // Selection Sort the values.
	 selectionSort(Values, amount, SelectionOutfile);
	 T = clock() - T;
	 SelectionOutfile <<"This took this many secs: "<< ((float)T)/CLOCKS_PER_SEC;

	 //Closing all the files
	 Infile.close();
	 SelectionOutfile.close();
	 //Ending the program
	 system("pause");
	 return 0;
}

// Definition of function selectionSort. This is a modification of the selection sort function from the textbook.
void selectionSort(vector<int>& vect, int size, ofstream& output){
	 int startScan, minIndex, minValue;
	
	 for (startScan = 0; startScan < (size-1); startScan++){
		minIndex = startScan;
		minValue = vect.at(startScan);
		 for (int index = (startScan + 1); index < size; index++){
			if (vect.at(index) < minValue){
				minValue = vect.at(index);
				minIndex = index;
				}
		 }
		swap(vect.at(minIndex),vect.at(startScan));
		vect.at(startScan) = minValue;
		}
	 // Display the sorted values.
	 output << "The sorted values are\n";
	 for (int count = 0; count < size; count++)
		 output << vect.at(count) << " " << endl;
	}

// Definition of function showArray. This function displays the contents of vect.
void showArray(vector<int> vect, int size, ofstream& output){
 for (int count = 0; count < size; count++)
	 output << vect.at(count) <<" "<< endl;
	}