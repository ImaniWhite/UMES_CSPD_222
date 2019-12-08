/*Imani White
1. Make the Die Class: It will make use of random number generation
	a. Constructor
	b. Roller to change the side
	c. operator+ to add the sides together
2. The Game: A Do-While Loop
	a. Prompt the user
	b. Give feedback to the user after fishing
		i. Keep a running total of the score
		ii. Each number has a fish and a number of points
			A switch statement can be used to keep track of that
3. End of Game
	a. Give different ending messages depending on how many points the user got
	b. Use If Else statements
*/
#include <iostream>
#include <cmath>
#include <cstdlib>//For rand and srand
#include <ctime>//For the time function
#include <string>
using namespace std;

//Making the class
class Die {
private:
	int side;//The side the die is on
public:
	Die();//Constructor
	void Roll();//This will roll the die
	int getRoll() { return side; }//This will tell us what side it is on
	int operator+(Die block) {//The plus operator wil add the sides of the die together to get their total
		int num;
		num = side + block.side;
		return num;
	}
};

Die::Die() {//This will make a die object. The die will made with a starting side.
	int toss;
	toss = rand() % (6 - 1 + 1); //this will make the random either 1 or 2
	switch (toss) {
	case 1:
		side = 1;
		break;
	case 2:
		side = 2;
		break;
	case 3:
		side = 3;
		break;
	case 4:
		side = 4;
		break;
	case 5:
		side = 5;
		break;
	default:
		side = 6;
		break;
	}
}

void Die::Roll() {//This will "roll" the die, changing teh side. It is the same as the constructor
	int toss;
	toss = rand() % (6 - 1 + 1); //this will make the random either 1 to 6
	switch (toss) {
	case 1:
		side = 1;
		break;
	case 2:
		side = 2;
		break;
	case 3:
		side = 3;
		break;
	case 4:
		side = 4;
		break;
	case 5:
		side = 5;
		break;
	default:
		side = 6;
		break;
	}
}

string Fish(int fish, int &score) {//This fuction will add points to the score and it will return what kind of fish the user caught
	switch (fish) {//I used fish found in the Chesapeake Bay
	case 2:
		score = score + 10;
		return "Gobie";
		break;
	case 3:
		score = score + 20;
		return "Yellow Perch";
		break;
	case 4:
		score = score + 30;
		return "Brook Trout";
		break;
	case 5:
		score = score + 40;
		return "Rainbow Trout";
		break;
	case 6:
		score = score + 50;
		return "Black Sea Bass";
		break;
	case 7:
		score = score + 60;
		return "Common Carp";
		break;
	case 8:
		score = score + 70;
		return "Rockfish";
		break;
	case 9:
		score = score + 80;
		return "Cownose Ray";
		break;
	case 10:
		score = score + 90;
		return "Blue Catfish";
		break;
	case 11:
		score = score + 100;
		return "Atlantic Sturgeon";
		break;
	case 12:
		score = score + 200;
		return "Bull Shark";
		break;
	default:
		return "Your line snapped!";//in case something went wrong
		break;
	}
}

int main() {
	srand((int)time(0));//This makes the seed
	int points = 0;
	char ans;//This will keep track of if the user the user wants to keep playing
	//Making objects
	Die object1;
	Die object2;
	//A fun little display!
	cout << "=====================================" << endl;
	cout << "Welcome to Imani's Fishing Hole"<<endl;
	cout << "=====================================" << endl;
	cout << "        ,%&& %&& %" << endl;
		cout << "   ,%&%& %&%& %&" << endl;
		cout << "  %& %&% &%&% % &%" << endl;
		cout << " % &%% %&% &% %&%&," << endl;
		cout << " &%&% %&%& %& &%& %" << endl;
		cout << "%%& %&%& %&%&% %&%%&" << endl;
		cout << "&%&% %&% % %& &% %%&" << endl;
		cout << "&& %&% %&%& %&% %&%'" << endl;
		cout << " '%&% %&% %&&%&%%'%" << endl;
		cout << "  % %& %& %&% &%%" << endl;
		cout << "   %%`\.'   /`%&'" << endl;
		cout << "      |    |            /`-._           _\\/" << endl;
		cout << "      |,   |_          /     `-._ ..--~`_" << endl;
		cout << "      |,   |_          /     `-._ ..--~`_" << endl;
		cout << "      |;   |_`\_      /  ,\\.~`  `-._ -  ^" << endl;
		cout << "      |;:  |/^}__..-,@   .~`    ~    `o ~" << endl;
		cout << "      |;:  |(____.-'     '.   ~   -    `    ~" << endl;
		cout << "      |;:  |  \ / `\       //.  -    ^   ~" << endl;
		cout << "      |;:  |\ /' /\_\_        ~. _ ~   -   //-" << endl;
		cout << "    \\/;:   \'--' `---`           `\\//-\\///\n" << endl;
		system("pause");//This lets the user look at the display before the screen gets too full
	cout << "Cast your line and see what you get! The bigger the fish, the more points you'll have!"<<endl;

	//A do-while loop handles the bulk of the game
	do {
		object1.Roll();//The dice are rolled
		object2.Roll();
		int number = object1 + object2;//Adds the rolls together using the plus operator
		string game = Fish(number, points);
		cout << "\nYour fish is a "<< game <<endl;
		cout << "\nWould you like to cast again?\nY/N to answer. " << endl;
		cin >> ans;
	} while (ans == 'Y' ||ans == 'y');//Lets the player continue of they'd like
	cout << endl;

	//The total number of fishing points is displayed, along with a message that varies depending on the number of points earned.
	if (points <= 100)
		cout << "You ended with " << points << " points. \nNot too great, but at least you aren't empty handed..." << endl;
	else if (points >= 200 && points > 100)
		cout << "You ended with " << points << " points. \nThanks for playing!" << endl;
	else if (points >= 300 && points > 200)
		cout << "You ended with " << points << " points! \nPretty Good!" << endl;
	else if (points >= 400 && points > 300)
		cout << "You ended with " << points << " points! \nGreat Haul!" << endl;
	else if (points >= 500 && points > 400)
		cout << "You ended with " << points << " points! \nWhat a wonderful assortment of fish!" << endl;
	else if (points >= 1000 && points > 500)
		cout << "You ended with " << points << " points! \nAMAZING! YOU HAD AN EXELLENT HAUL!" << endl;
	else
		cout << "A huge shark came and swallowed up your bucket!"<<endl;//in case something went wrong

	//End Program
	system("pause");
	return 0;
}