/*Imani White

1. Read the file
2. Fill an arry with the data from the file
	a. Make an array of strings
       Dynamically allocate elements in the array to make sure it was work with any size file
3. Outout the original message
	a. Use a for loop to output
	b. Format the output with spaces
5. Modify the message according to the rules ex. 'word', 'place', 'at'
	a. Rule 1: C V
		word = ordway
	b. Rule 2: C C
		place = aceplay 
	c. Rule 3: V
		at = atway
	d. Dealing with punctuation
		If there is a punctuation at the end of the word, then it will remove the punctuation,
		apply the normal version of the rule, then add the punctuation back in
6. Output the new Pig Latin message
	a. Use a for loop to output
	b. Format the output with spaces
7. End
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

//FUNCTION PROTOTYPES
bool isVowel(string);//To check if the value is a vowel
bool isPunct(string);//To check if the value is a punctuation
int whatPunct(string);//To see what punctuation it is
void insrtPunct(string&, int, int);//This applies the rules in the cases that there is a punctuation at the end of a string

int main() {
	int punctuation;//This will be used to determine what kind of punctuation is there
	int pigRule=0;//This will be used to keep track of which Pig Latin Rule is being used
	string tempString1, tempString2;

	ifstream Input("prog08_PigLatin.txt");//Opening File prog08_PigLatin
	if (!Input) {//Making sure the file can open
		cout << "Unable to open file.";
		return -1;
	}

	string *message = NULL;//
	string tempChar, value;//This is dynamically allocating space in the string array
	int size = 0;          //

	while (Input>>tempChar) {//Getting the size of the array
		size++;
	}

	message = new string[size];

	Input.close();//This part is to make sure the file is not read two times
	Input.open("prog08_PigLatin.txt");
	cout << "The original message is :\n";//The original message will output
	for (int i = 0; i < size; i++) {
		Input >> message[i];
		cout << message[i] << " ";
	}
	cout << "\n" << endl;
	Input.close();

//The Meat and Potatoes. This for loop applies the rules using all the functions
	for (int u = 0; u < size; u++) {
		int SIZE = message[u].length();
		if (!isVowel(message[u].substr(0)) && isVowel(message[u].substr(1))) {//Consonant then vowel rule
			pigRule = 1;
			if (isPunct(message[u])) {
				punctuation = whatPunct(message[u].substr(SIZE-1));
				insrtPunct(message[u], punctuation, pigRule);
			}
			else {
				message[u] = message[u].substr(1, SIZE) + message[u].substr(0) + "ay";
			}
		}
		else if (!isVowel(message[u].substr(0)) && !isVowel(message[u].substr(1))) {//Consonants back to back
			pigRule = 2;
			if (isPunct(message[u])) {
				punctuation = whatPunct(message[u].substr(SIZE-1));
				insrtPunct(message[u], punctuation, pigRule);
			}
			else {
				tempString1 = message[u].substr(0, (message[u].length() / 2));
				tempString2 = message[u].substr((message[u].length() / 2), message[u].length()-1);
				message[u] = tempString2 + tempString1 + "ay";
			}
		}
		else if (isVowel(message[u].substr(0))) {//Vowel rule
			pigRule = 3;
			if (isPunct(message[u])) {
				punctuation = whatPunct(message[u].substr(SIZE-1));
				insrtPunct(message[u], punctuation, pigRule);
			}
			else {
				message[u] = message[u] + "way";
			}
		}
		else
			cout<<"\nI don't know what to do with the word"<<message[u]<<endl;
	}

	cout << '\n';
	for (int e = 0; e < size; e++) {//Output the Pig Latin
		cout << message[e] << " ";
	}
	cout << '\n';

	system("pause");
	return 0;
}

//FUNCTION DEFINITIONS
bool isVowel(string letter) {//To check if the value is a vowel
	if ((letter == "A") || (letter == "E") || (letter == "I") || (letter == "O") || (letter == "U") || (letter == "a") || (letter == "e") ||
		(letter == "i") || (letter == "o") || (letter == "u")) {
		return true;
	}
	else
		return false;
}

bool isPunct(string symbol){//To check if the value is a punctuation
	if (symbol.substr((symbol.length() - 1)) == "." || symbol.substr((symbol.length() - 1)) == ","
		|| symbol.substr((symbol.length() - 1)) == "?") {
		return true;
	}
	else
		return false;
}

int whatPunct(string dot) {//To see what punctuation it is. The int will be passed to insrtPunct
	if (dot == ".")
		return 1;
	else if (dot == ",")
		return 2;
	else if (dot == "?")
		return 3;
	else
		return 6;

}

void insrtPunct(string& word, int punct, int rule) {//This applies the rules in the cases that there is a punctuation at the end of a string
	string str1, str2;
	int length;
	switch (punct) {
		case 1://'.' PERIOD
			if (rule == 1) {
				word = word.substr(0, (word.length() - 1));
				word = word.substr(1, word.length()-2) + word.substr(0) + "ay.";
			}
			else if (rule == 2) {
				word = word.substr(2, word.length() - 3) + word.substr(0,1) + word.substr(1,1) + "ay.";
			}
			else {
				word = word.substr(0, (length-1)) + "way.";
			}
		break;

		case 2://',' COMMA
			if (rule == 1) {
				word = word.substr(0, (word.length() - 1));
				word = word.substr(1, word.length()-2) + word.substr(0) + "ay,";
			}
			else if (rule == 2) {
				word = word.substr(2, word.length() - 3) + word.substr(0, 1) + word.substr(1, 1) + "ay,";
			}
			else {
				word = word.substr(0, (length-1)) + "way,";
			}
		break;

		case 3://'?' QUESTION
			if (rule == 1) {
				word = word.substr(0, (word.length() - 1));
				word = word.substr(1, word.length()-2) + word.substr(0) + "ay?";
			}
			else if (rule == 2) {
				word = word.substr(2, word.length() - 3) + word.substr(0, 1) + word.substr(1, 1) + "ay?";
			}
			else {
				word = word.substr(0, (length - 1)) + "way?";
			}
		break;

		default:
			cout << "I'm not familiar with that character."<<endl;
	}
}