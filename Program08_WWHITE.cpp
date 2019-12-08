//Pig Latin Translator

#include <iostream>
#include <string>
#include <fstream>
bool isVowel(char*, int);		//function that returns true if a character is a vowel (uppercase or lowercase)
bool isPunct(char*, int);		//function that returns true if a character is a punctuation mark
bool isSpace(char*, int);		//function that returns true if the character is a space
bool newsentFlag = false;		//global flags to detect beginning of a new sentence
using namespace std;
int main()
{
	int size = 0;				//number of characters in string/size of dynamic array
	string temp;				//temporary string so we can count characters in file
	char temp1, temp2;			//temporary char used when printing in pig latin
	ifstream myInfile;			//file variable
	myInfile.open("prog08_PigLatin.txt");	//open the file
	char *arrptr = nullptr;					//initialize pointer to point to nothing. later it will point to a dynamic array
	if (myInfile)				//if the file opens:
	{
		getline(myInfile, temp);			//get all the text from the file and store in a string
		size = temp.length();				//find how many characters are in the string
		arrptr = new char[size];			//create a dynamic array that holds that many characters
		myInfile.clear();					//clear the flags
		myInfile.seekg(0, ios::beg);		//move to the beginning to read file again
		for (int i = 0; i < size; i++)		//for each character in the file:
			myInfile.get(*(arrptr + i));	//add it into the dynamic character array
		myInfile.close();					//close the file
	}
	for (int i = 0; i < size; i++)			//print the initial statement from the file
	{
		cout << arrptr[i];					//prints character by character without making changes
	}
	cout << endl << endl << "Becomes: " << endl << endl;		//formatting output
	for (int index = 0; index < size; index++)					//looks at each character in cstring
	{
		if ((!isVowel(arrptr, index)) && (isVowel(arrptr, (index + 1))))		//if first 2 letters of a word are consonant & vowel
		{
			temp1 = tolower(arrptr[index]);			//store the first letter so you can print it later
			index++;						//look at the next letter (2nd letter of word now)
			if (newsentFlag)				//if it is the beginning of a sentence, make the first letter printed capital
			{
				cout << static_cast<char>(toupper(*(arrptr + index)));	//print the letter as uppercase
				newsentFlag = false;		//reset flag because it did its job
			}
			else
				cout << arrptr[index];		//else (not the beginning of sentence), print lowercase
			index++;						//look at next letter
			while ((!isPunct(arrptr, index)) && (!isSpace(arrptr, index)))	//if the letter being looked at is not a space or punctuation
			{
				cout << arrptr[index];		//print the letter
				index++;					//look at the next character
			}								//stops when it reaches a punctuation or space (aka at the end of a word)
			cout << temp1 << "ay";			//print the first letter of the word and "ay" at the end of the word
			if (isPunct(arrptr, index))		//if there is a punctuation mark after this word:
			{
				cout << arrptr[index];		//print the punctuation
				index++;					//look at the next character
			}
			if (isSpace(arrptr, index))		//if there is a space after this word:
			{
				cout << arrptr[index];		//print the space
			}
			continue;		//need continue because the word might need this section of code in order to transform into pig latin
								//ie start from the beginning of for loop, check for different situations for transformations
		}
		else if ((!isVowel(arrptr, index)) && (!isVowel(arrptr, (index + 1))))	//if first 2 letters of a word are both consonants
		{
			temp1 = tolower(arrptr[index]);		//store first letter so it can be printed later
			temp2 = arrptr[index + 1];			//store second letter so it can be printed later
			index += 2;					//increment 2x because we have looked at the first two letters already. now on the third
			if (newsentFlag)		//if it is the beginning of a sentence, make the first letter printed capital
			{
				cout << static_cast<char>(toupper(*(arrptr + index)));	//print the letter as uppercase
				newsentFlag = false;		//reset flag because it did its job
			}
			while ((!isPunct(arrptr, index)) && (!isSpace(arrptr, index)))	//if the letter being looked at is not a space or punctuation
			{
				cout << arrptr[index];			//print the letter
				index++;						//look at the next letter
			}									//stops when it reaches a punctuation mark (aka the end of a word)
			cout << temp1 << temp2 << "ay";		//prints the first 2 letters of the word and "ay" at the end of the word
			if (isPunct(arrptr, index))			//if there is a punctuation mark at the end of the word
			{
				cout << arrptr[index];			//print the punctuation mark
				index++;						//look at the next character
			}
			if (isSpace(arrptr, index))			//if there is a space after the word
			{
				cout << arrptr[index];			//print a space
			}
			continue;
		}
		else if (isVowel(arrptr, index))		//if the word starts with a vowel:
		{
			if (newsentFlag)		//if it is the beginning of a sentence, make the first letter printed capital
			{
				cout << static_cast<char>(toupper(*(arrptr + index)));	//print the letter as uppercase
				newsentFlag = false;		//reset flag because it did its job
			}
			else
				cout << arrptr[index];				//print the first letter of the word
			index++;							//look at the next letter
			while ((!isPunct(arrptr, index)) && (!isSpace(arrptr, index)))	//if the letter being looked at is not a space or punctuation
			{
				cout << arrptr[index];			//print the letter
				index++;						//look at the next character
			}
			cout << "way";					//prints "way" at the end of the word
			if (isPunct(arrptr, index))		//if there is a punctuation mark at the end of the word:
			{
				cout << arrptr[index];		//print the punctuation mark
				index++;					//look at the next character
			}
			if (isSpace(arrptr, index))		//if there is a space
			{
				cout << arrptr[index];		//print the space
			}
			continue;
		}
	}
	cout << endl << endl;		//format output
	delete[] arrptr;		//release dynamic array
	system("pause");
	return 0;
}
bool isVowel(char *input, int i)	//if the character is a lowercase or uppercase vowel, return true
{
	if ((input[i] == 'a') || (input[i] == 'e') || (input[i] == 'i') || (input[i] == 'o') || (input[i] == 'u') || (input[i] == 'A') || (input[i] == 'E') || (input[i] == 'I') || (input[i] == 'O') || (input[i] == 'U'))
		return true;
	else
		return false;
}
bool isPunct(char *input, int i)	//if the character is a punctuation mark, return true
{
	if ((input[i] == '.') || (input[i] == '?') || (input[i] == '!'))
	{
		newsentFlag = true;		//if the punctuation marks the end of a sentence, change the new sentence flag to true
		return true;
	}
	else if (input[i] == ',')	//if it is just a comma (not the end of a sentence), return true
		return true;
	else
		return false;
}
bool isSpace(char *input, int i)	//if the character is a space, return true
{
	if (input[i] == ' ')
		return true;
	else
		return false;
}