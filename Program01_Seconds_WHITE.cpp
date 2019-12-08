#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	const double SECS_MIN = 60;
	const double SECS_HOUR = 3600;
	int seconds, minutes, hours;

	cout << " This program takes a number of seconds and calculates the number of minutes and hours.\nEnter the number of seconds.";
	cin >> seconds;
	cout << " There are " << seconds << " seconds" << endl;
	
	hours = seconds / SECS_HOUR;
	if ((hours % 60) > 0) {
		minutes = ((seconds-(hours * SECS_HOUR)) / SECS_MIN);
	}
	if ((minutes % 60) > 0) {
		seconds = seconds - (hours * SECS_HOUR) - (minutes*SECS_MIN);
	}
	cout << "The time is " << hours << ":" << minutes<<":"<<seconds;

	return 0;
}
