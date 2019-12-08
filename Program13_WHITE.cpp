/*Imani White

Similar to the pythagorean triple program, this one will also use multiple for loops to check to see if the end result is what we are looking for.
In this program, we are simlulating a Box and Ball game. We are looking for all the combinations of balls in boxes that give a total score of 17.
I got combinatorics help.

1. Make variables
	a. interation counter
	b. array that keeps track of how many balls are in each box.
2. For Loop Galore
	a. The first for loop will keep track of the first box; it has a max of six balls because if you use more, the remaining balls in the other boxes would exceed 17
	b. The seconf for loop will handle the seconf box; it has a max of eight balls because if you use more, the remaining balls in the other boxes would not equal 17
	c. The third loop will take care of the third AND fourth boxes. It would be more effecient to calculate the fourth box rather than make a new loop for it.
		It has a max of four balls because if you use more, the remaining balls in the other boxes would not give a score of 17
*/

#include <iostream>
using namespace std;

int main(){
	int intr = 0;//for counting interations
	int ballcnt[3];//for counting number of balls

	cout << "All the combinations for 17 are: " << endl;

	for (int x = 0; x <= 6; x++){// 6 is the max amount for the first box
		intr++;
		ballcnt[0] = x;//number of balls in box 1
		for (int y = 0; y <= 8; y++){// 8 is the max amount for the second box
			ballcnt[1] = y;//number of balls in box 2
			intr++;
			if (ballcnt[0] + ballcnt[1] * 2 <= 17){//sum of balls in box 1 & 2 should be less than or equal to 17
				for (int z = 0; z <= 4; z++){// 4 is the max amount for the third box
					intr++;
					ballcnt[2] = z;//number of balls in box 3

					int score = ballcnt[0] * 1 + ballcnt[1] * 2 + ballcnt[2] * 3;//sum of balls in box 1, 2 & 3 (box 1 is given one point, box 2 is given 2 and box 3, 3
					int curcnt = ballcnt[0] + ballcnt[1] + ballcnt[2];//number of balls in box 1, 2 & 3

					if (score <= 17){//sum of balls in box 1 & 2 should be less than or equal to 17
						if ((17 - score) % 4 == 0 && ((17 - score) / 4) == (9 - curcnt)){//There should be nine balls, four boxes, and equal 17. And there shouldn't be a remainder
							cout << "\nBox One has " << ballcnt[0] << " balls \nBox Two has " << ballcnt[1] << " balls \nBox Three has " << ballcnt[2] << " balls /nBox Four has " << ((17 - score) / 4) << " balls " << endl;
						}
					}
				}
			}
		}
	}
	cout <<"\n"<< intr << " interations were used."<<endl;
	system("pause");
	return 0;
}