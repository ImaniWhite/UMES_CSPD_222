// Imani White
//
//1. Open the file
//  Make sure the file can open
//2. Read the file and fill the array
//  Use a for loop to do both
//3. Get rid of the vowels in the middle of the word
//  Isolate the vowels at the beginning of words to make sure those dont go too. I decided to make the uppercase
//4. Output

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	ifstream Input("testing.txt");//Opening File
	if (!Input) {//Making sure the dile can open
		cout << "Unable to open file.";
		return -1;
	}
	const int SIZE = 255;
	char message[SIZE];
	char tempChar;//This variable is for filling the array

	for (int x = 0; x < SIZE; x++) {//filling the array with the inital message
		Input.get(tempChar);
		message[x] = tempChar;
		cout << message[x];//Outputing the original message
	}
	cout << "\n";

	for (int t = 0; t < SIZE; t++) {
		if (message[t] == ' ')
			message[t + 1] = toupper(message[t + 1]);//Making the first letter of every word upper case
	}

	for (int c = 0; c < SIZE; c++) { //Idenifying the vowels
		if (message[c] == 'a' || message[c] == 'e' || message[c] == 'i' || message[c] == 'o' || message[c] == 'u')
			 message[c] = '@';
	}
	
	for (int o = 1; o < SIZE; o++) {
		if (message[o - 2] == '.')
			continue;
		message[o] = tolower(message[o]);//Makking everything lower case again
	}

	for (int z = 0; z < SIZE; z++) {
		if (message[z] == '@' || message[z] == '.')//not printing the vowels and the empty spaces left behind were filled with periods, so im also not printing those
			continue;
		cout << message[z];
	}
	cout << "\n";

	system("pause");
	return 0;
}