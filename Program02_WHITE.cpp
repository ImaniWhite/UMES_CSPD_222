//Imani White
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	//Definition of Variables
	const int NUM = 100; //The limit of the Pythagoran Triples
	int first, second, last; //the a^2 + b^2 = c^2
	int a, b, c; //User's a^2 + b^2 = c^2
	int A[NUM];//Each Pythagoran Theorm (PTheorm) variable gets an array of its own
	int B[NUM];
	int C[NUM];

	//Making the outputfile. The file is in the same folder as my program.
	ofstream Outfile;
	Outfile.open("Program02_Output.txt");
	if (!Outfile){
		cout << "Could not open file. Program Terminated." << endl;
		return 1;
	}
	
	//Introducing the user and prompting thier input.
	cout << "A Pythagorean Triple is a set of positive integers, a, b and c, that fits the rule a^2 + b^2 = c^2. \nPlease Enter an A, B, and C and this program will check if it is a Pythagorean triple. Enter integers between 1 and 100." << endl;
	cout << "Check out Program02_Output.txt for your result and for a list of all the Pythagorean triples between 1, 1, 1 and 100, 100, 100." << endl;
	cout << "A: ";
	cin >> a;
		while (a < 1 || a > 100) {//input validation
		cout << "Please Enter a valid, natural number between 1 and 100.\nA: ";
		cin >> a;
		}
	cout << "B: ";
	cin >> b;
		while (b < 1 || b > 100) {//input validation
		cout << "Please Enter a valid, natural number between 1 and 100.\nB: ";
		cin >> b;
		}
	cout << "C: ";
	cin >> c;
		while (c < 1 || c > 100) {//input validation
		cout << "Please Enter a valid, natural number between 1 and 100.\nC: ";
		cin >> c;
		}
	//This will check if the user's value is a Pythagorean triple and output to the screen AND file
	if (((a*a) + (b*b)) == (c*c)) {
		cout << "The value you entered, "<<a<<", "<<b<<", "<<c<<" is a Pythagorean triple" << endl;
		Outfile << "The value you entered, " << a << ", " << b << ", " << c << " is a Pythagorean triple" << endl;
		}
	else
		cout << "The value you entered, " << a << ", " << b << ", " << c << " is NOT a Pythagorean triple" << endl;
		Outfile << "The value you entered, " << a << ", " << b << ", " << c << " is NOT a Pythagorean triple" << endl;

	//Filling the Arrays to NUM
	for (int x = 0; x <= NUM; x++)
		A[x] = x;
	for (int y = 0; y <= NUM; y++)
		B[y] = y ;
	for (int z = 0; z <= NUM; z++)
		C[z] = z;

	//This checks the elements of the array to see if they are Pythagorean triples. If they are, they will output to the file along with a messege
	for (first = 1; first <= NUM; first++) {
		for (second = (first+1); second <= NUM; second++) {//The (first+1) stops repeats
			for (last = 3; last <= NUM; last++) {
				if ((A[first] * A[first] + B[second] * B[second]) == (C[last] * C[last])) {
					Outfile << A[first] << " " << B[second] << " " << C[last] << "  is a Pythagorean triple." << endl;
				}
			}
		}
	}

	cout << "The Program ran successfully. Please check Program02_Output.txt." << endl;//Letting the user know the program ended
	Outfile.close();//Closing the output file
	return 0;
}