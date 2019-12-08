//Imani White

//1. Let the users enter the number of test the program will me looking at to average
//2. Read the input file and put that number of test scores into an array
//3. Sort that array with a function
//4. Calculate the average with a function
//  a. Drop the lowest score.
//5. Display all the information to the user

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void bubbleSort(double*&, int);
double Average(double*&, int);

int main() {
	ifstream Infile;
	Infile.open("Prob_6_grades.txt");
	if (!Infile){
		cout << "Could not open file. Program Terminated." << endl;
		return 1;
	}

	double *test = NULL;
	int score, size = 0, value;

	//************************************
	//This part makes and fills the array
	//************************************
	while (Infile>>score) {//Getting the size of the array
		size++;
	}
	test = new double[size];
	Infile.close();//This little part is to make sure the file is not read two times
	Infile.open("Prob_6_grades.txt");
	cout << "The unsorted test grades are:\n";
	for (int i = 0; i <= size; i++) {//filling the array
		Infile >> value;
		if (value < 0) {
			cout << "There is an invalid test score.\nModify your file so that it does not include negative integers and try again.";
				return -1;
		}
		test[i] = value;
		cout << test[i] << "\t";
	}
	cout << "\n"<<endl;
	Infile.close();
	
	bubbleSort(test, size);	//This sorts and displays the array without the lowest score

	cout << "\nAfter dropping the lowest score, the test average is " << fixed << showpoint << setprecision(2)<< Average(test, size)<<endl;//display

	system("pause");
    return 0;
}

//Modified bubble sort using pointers
void bubbleSort(double*& Test, int amt) {
	bool change;
	int temp;
	do {
		change = false;
		for (int count = 0; count < (amt - 1); count++) {
			if (*(Test + count) < *(Test + (count + 1))) {
				temp = *(Test + count);
				*(Test + count) = *(Test + (count + 1));
				*(Test + (count + 1)) = temp;
				change = true;
			}
		}
	} while (change);

	// Display the sorted values.
	cout << "The sorted values are:\n";
	for (int count = 0; count < amt; count++)
		cout << *(Test + count) << " " << endl;
}

//Average function
double Average(double*& Test, int amt) {
	int cnt=0, total = 0;
	double avg = 0;
	for (int count = 0; count < (amt - 1); count++) {//This will not read the last (the lowest) score in the array
		total += *(Test + count);
		cnt++;
	}
	avg = double(total)/double(cnt);
	return avg;
}