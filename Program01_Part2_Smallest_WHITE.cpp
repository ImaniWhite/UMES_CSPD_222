#include <iostream>

using namespace std;


int main() {

	int num, greatest, smallest;

	cout << "You will enter a series of integers and\nIwill then tell you the largest and\nthe smallest numbers you entered." << endl;
	cout << "Enter -99 to terminate the series." << endl;
	cout << "Enter an integer (-99 to quit):";
	cin >> num;
	greatest = num;
	smallest = num;

	while (num != -99) {

		if (num > greatest)
			greatest = num;

		if (num < smallest)
			smallest = num;

		cout << "Enter a number or -99 to quit: ";
		cin >> num;
	}

	cout << "The greatest value entered was " << greatest << endl;
	cout << "The smallest value entered was " << smallest << endl;

	return 0;
}
