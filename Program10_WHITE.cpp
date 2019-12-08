//Imani White
/*
0. I need a randon number generator to make the program work
1. Make the class
	a. constructor - the creator
	b. sideUp - the flipper
	c. getSideUp - gets the result
2. Toss the coin 100 times
	a. call the coin flipping function 100 times
3. Output
	a. the coin toss results
	b. the percent difference
*/
#include <iostream>
#include <cmath>
#include <cstdlib>//For rand and srand
#include <string>
#include <ctime>//For the time function

using namespace std;

class Coin {
private:
	string sideup;//Heads or Tails
public:
	Coin();//The coin object will be created on a side
	void sideUp();//This will filp the coin after the pobject is created
	string getSideUp() { return sideup; }//This will tell us what side a coin is on
};

Coin::Coin(){//Constructor
		int toss;
			toss = rand() % (2-1+1); //this will make the random either 1 or 2
		if (toss)
			sideup = "Heads";
		else
			sideup = "Tails";
}

void Coin::sideUp(){//This is essentally the same as the constructor, but it will allow the object to be changed/flipped
	int toss;
	toss = rand() % (2 - 1 + 1);
	if (toss)
		sideup = "Heads";
	else
		sideup = "Tails";
}

void TossTheCoin(Coin &change, double &counter1, double &counter2) {//This function will toss the coin 100 times
	for (int y = 0; y< 10; y++) {//I made the output a tablt to make it a little easier to look at
		for (int x = 0; x < 10; x++) {
			change.sideUp();
			cout << "Toss " << (y+1)*(x+1) << ": " << change.getSideUp()<<"\t";
			if (change.getSideUp()== "Heads")
				counter1++;//Heads
			else
				counter2++;//Tails
		}
		cout << endl;
	}
}

int main() {
	srand((int)time(0));//This makes the seed

	Coin Yen;//Making the coin
	if (Yen.getSideUp()=="Heads")
		cout << "The coin's initail side is HEADS" << endl;
	else
		cout << "The coin's initail side is TAILS" << endl;
	double Hcount = 0.0, Tcount = 0.0;//These will count the number of heads and tails
	double Pdiff;//This will store the percent difference

	TossTheCoin(Yen, Hcount, Tcount);
	cout << "There were "<< Hcount <<" Heads."<<endl;
	cout << "There were "<< Tcount <<" Tails."<<endl;
	cout << endl;

	Pdiff = (abs(50.0 - Hcount) / 50.0) * 100; //gets the percent differnce of heads and tails since it would be the same for both
	cout << "Ideally, the flip should be 50/50\n";//Output the persent differnces
	cout << "The difference is "<< Pdiff <<"%"<< endl;

	system("pause");
	return 0;
}