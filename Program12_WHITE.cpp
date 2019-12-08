/*Imani White
Program 12
1. Use and modify the FeetInches program for the textbook
2. Get the user input for the feet and inches then +, -, and *
3. Output the results
*/

#include <iostream>
using namespace std;
class FeetInches {//This is a modified version of the FeetInches program on the textbook
private:
	int feet;
	int inch;
	void simplify();
public:
	FeetInches(int feet = 0, int inch = 0) {//Constructor
		this->feet = feet;
		this->inch = inch;
		simplify();
	}
	FeetInches(const FeetInches &);//Copy Constructor
	void setFeet(int feet) { this->feet = feet; }
	int getFeet() { return feet; }
	void setInches(int inch) { this->inch = inch; simplify(); }
	int getInches() { return inch; }
	FeetInches operator + (const FeetInches &);
	FeetInches operator - (const FeetInches &);
	FeetInches operator * (const FeetInches &);
};

FeetInches::FeetInches(const FeetInches &ruler) {//Copy Constructor will set the feet and inches to themselves
	feet = ruler.feet;
	inch = ruler.inch;
}

void FeetInches::simplify() {
	if (inch >= 12) {
		feet += (inch / 12);
		inch = inch % 12;
	}
	else if (inch < 0) {
		feet -= ((abs(inch) / 12) + 1);
		inch = 12 - (abs(inch) % 12);
	}
}

FeetInches FeetInches::operator + (const FeetInches &mesure) {
	FeetInches temp;
	temp.inch = inch + mesure.inch;
	temp.feet = feet + mesure.feet;
	temp.simplify();
	return temp;
}

FeetInches FeetInches::operator - (const FeetInches &mesure) {
	FeetInches temp;
	temp.inch = inch - mesure.inch;
	temp.feet = feet - mesure.feet;
	temp.simplify();
	return temp;
}

FeetInches FeetInches::operator * (const FeetInches &mesure) {
	FeetInches temp;
	temp.inch = inch * mesure.inch;
	temp.feet = feet * mesure.feet;
	temp.simplify();
	return temp;
}

int main() {
	int feet1, inch1, feet2, inch2; //These will hold the user input
	//User Input and Feedback
	cout << "Hello! This program will take given measurements (in FEET and INCHES) and ADD, SUBTRACT, and MULTIPLY." << endl;
	cout << "Please enter the FEET of your first mesurement: ";
	cin >> feet1;
	cout <<endl << "Please enter the INCHES of your first mesurement: ";
	cin >> inch1;
	FeetInches Mesure1(feet1, inch1);
	cout << "Great! The first measurement has been taken." << endl;
	cout << "\nPlease enter the FEET of your second mesurement: ";
	cin >> feet2;
	cout << endl << "Please enter the INCHES of your second mesurement: ";
	cin >> inch2;
	FeetInches Mesure2(feet2, inch2);
	
	//Using the operators on the objects
	FeetInches addLine = Mesure1 + Mesure2;
	FeetInches subLine = Mesure1 - Mesure2;
	FeetInches Box = Mesure1 * Mesure2;

	//Output
	cout << "\nAdded together, your mesurments is: " << addLine.getFeet() << " feet and " << addLine.getInches() << " inches." << endl;
	cout << "Subtracted from one another, your mesurments is: " << subLine.getFeet() << " feet and " << subLine.getInches() << " inches." << endl;
	cout << "Multiplied together, your mesurments is: " << Box.getFeet() << " feet and " << Box.getInches() << " inches." << endl;

	system("pause");
	return 0;
}