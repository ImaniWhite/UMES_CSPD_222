//Imani White

//Algorithm
//1. Define Variables
//	a. the 150 limit
//	b. the array of primes
//	c. the prime boolean
//2. Make and Open the output file
//3. Tell the user what is going on
//4. Starting with a given number, check if it is diviable by the numbers less that that number
//	a. use two for loops
//	b. if the number divides evenly, then it is not prime
//	c. if the number does not divide evenly, then it should be added to the array of primes
//5. Output the primes

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	const int MAX = 150;//our limit
	int Prime[150] = {2};//We know that the first prime number is two.
	bool isPrime = true;
	int count = 1; //keeps track of how many numbers are in Prime[]

	//Making the outputfile. The file is in the same folder as my program.
	ofstream Outfile;
	Outfile.open("prime_IW.dat");
	if (!Outfile) {
		cout << "Could not open file. Program Terminated." << endl;
		return 1;
	}

	//This part will tell the user what is going on.
	cout << "This program will find the first 150 prime numbers. Check the file prime_IW.dat for the output"<<endl;
	Outfile << "This program will find the first 150 prime numbers." << endl;
		
	for (int x = 3; x > 0; x++) {//Starting at three, since one & zero are not a prime number and we already know two, this outer loop looks throuh every number
		for (int y = 2; y <= (x/2); y++) {
			if (x % y == 0) {//There is no remainder (and the prodect is whole and natural)...
				isPrime = false;//then is it no prime
				break;
			}
		}
		if (isPrime) {//if x has gone through the first FOR loop, then it was not marked as false, then this will double checked that it is true
			Prime[count] = x;//if this isPrime is true, then fill the array Prime[]
			count++;//increase the counter so the next prime number will fill the next empty spot
		}
			isPrime = true;//set isPrime back to true again so that every next iteration doesn't come up as false

			if (count == MAX)//if count has reached out limit of 150 numbers...
			break;//then stop
	}

	//Output to file	
	for (int z = 0; z < MAX; z++) {
		Outfile << Prime[z] << endl;
	}

	//The outpufile will be closed
	Outfile.close();

	system("pause");
	return 0;
}