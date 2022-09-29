/*
	Name: d6 Ability Checks
	Copyright: 2022
	Author: Daniel R. Collins
	Date: 28-09-22 00:44
	Description: Test chance for success when rolling ability checks
		by 3d6, 4d6, or 5d6, roll-under.
*/
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Constants
const int NUM_TRIALS = 10000;

// Roll a d6
int rolld6 () {
	return rand() % 6 + 1;
}

// Roll a number of d6s
int rolld6s(int num) {
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += rolld6();
	}
	return sum;	
}

// Test one ability score vs. number of dice
// Return success ratio
float testAbilityVsDice(int ability, int dice) {
	int success = 0;
	for (int i = 0; i < NUM_TRIALS; i++) {
		int roll = rolld6s(dice);
		if (roll <= ability)
			success++;
	}
	return (float) success / NUM_TRIALS;
}

// Make a table of all tests
void makeResultsTable () {
	cout << "Score\t3d6\t4d6\t5d6\n";
	cout << fixed << showpoint << setprecision(3);
	for (int a = 3; a <= 18; a++) {
		cout << a;
		for (int d = 3; d <= 5; d++) {
			float rate = testAbilityVsDice(a, d);
			cout << "\t" << rate;
		}
		cout << endl;
	}
	cout << endl;
}

// Main test driver
int main(int argc, char** argv) {
	srand(time(0));
	makeResultsTable();
	return 0;
}