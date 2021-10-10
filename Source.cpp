/*James Ford
10/9/2021
csc215
Skynet HK-Aerial Phase 1
Create a Grid Search program that will use loops to locate the enemy.
*/

//Necessary Liabraies
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//declare the namespace as standard
using namespace std;

//declare the string as standard
using std::string;


int main()
{

	//declare varible for the string
	string answer;

	//declare varibles for the different algorithms and generators being used

	//establish the lowest number possible
	int searchGridLowNumber = 1;
	//establish the highest number possible
	int searchGridHighNumber = 64;
	//seed random number generator
	srand(static_cast<unsigned int>(time(0)));
	//set a range
	int secretNumber = rand() % 64 + 1;
	//search algorithm evaluates the possibe guesses that are between the set range of numbers
	int targetLocationPrediction =
		((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

	//set varibles to keep track of the number of guesses
	int tries = 0;

	//commence the testing
	cout << "Wake up solider! The enemy is upon us!\n";
	cout << "We have narrowed the search area to an 8x8 kill boxthat is split into a grid, numbered 1 - 64.\n\n";
	cout << "To avoid unwanted.... collateral damage. You must pinpoint the enemies location down to to one of those squares.\n\n";
	cout << "Keep your head up soldier and pay ATTENTION!!!";
	cout << "Are you still with me?\n";
	cin >> answer;
	cout << "Okay be on the look out \n";
	cout << "Enemies location is being triangulated \n";
	cout << "The enemy has been located in Sector " << secretNumber << "on the grid!!\n";
	cout << "Now is the time to shine for the software, let see how many tries it takes\n";
	cout << "until we find the enemy.\n";

	//Do-while loop runnign the algorithm and game text
	do
	{
		//increment tries here to get the first ping
		++tries;
		cout << "....\n";
		cout << "Solider support software attempt #" << tries << " \n";

		//start the search algorithm for this cycle
		targetLocationPrediction =
			((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;

		//start conditional to see if the guess is less or greatest than the random number

		//if the guess is greater than the number...
		if (targetLocationPrediction > secretNumber)
		{
			cout << " Solider supprot software guessed the enemy was located in sector " << targetLocationPrediction << " \n";
			cout << "which is higher than the Sector number that the enemy is located at. \n";
			cout << " The software will now use that as the new maximum. \n";
			cout << "Do you understand? \n";
			cin >> answer;
			cout << "Tremendous!";

			//assign this guess as the highest number
			searchGridHighNumber = targetLocationPrediction;
			//this will inform the user
			cout << "The new maximum number possible is " << searchGridHighNumber << " \n";
		}
		//If the guess is lower the target number
		else if (targetLocationPrediction < secretNumber)
		{
			cout << " Solider support software guessed the enemy was located in sector " << targetLocationPrediction << " \n";
			cout << "Which is lower than the sector number that the enemy is located at \n";
			cout << " The software will now use that as the new minimum. \n";

			//assign this guess as the new lowest number
			searchGridLowNumber = targetLocationPrediction;
			 //this will inform the user
			cout << "The new minimum number possible is " << searchGridLowNumber << "\n";
		}
		//Correct Guess conditions
		else if (targetLocationPrediction == secretNumber)
		{
			cout << "The Software has spotted the enemy in Sector " << secretNumber << "\n";
			cout << " The  enemy was located in Sector " << targetLocationPrediction << "\n";
			cout << "The solider suppor software took " << tries << "attempts to locate the enemy \n";
		}
	}
	//set the loop condition so that while the predicition isnt the number it continues 
	while (targetLocationPrediction != secretNumber);

	//main() return statement
	return 0;
}
