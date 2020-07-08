
#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;
int main()
{

	cout << endl;
	cout << "Welcome to the Game of Nim!" << endl << endl;
	cout << "This is a well-known game with a number of variants." << endl;
	cout << "The following variant has an interesting winning strategy." << endl;
	cout << "Two players alternately take marbles from a pile." << endl;
	cout << "In each move, a player chooses how many marbles to take." << endl;
	cout << "The player must take at least one but at most half of the marbles." << endl;
	cout << "Then the other player takes a turn." << endl;
	cout << "The player who takes the last marble loses." << endl << endl;

	cout << "You can choose to play PvP or PvC." << endl << endl;

	cout << "PvP:" << endl << endl;
	cout << "Pile size ranging from 10 to 100 will be randomly determined in each game." << endl;
	cout << "Two users--player 1 and player 2--will take turns." << endl;
	cout << "Player 1 always goes first." << endl;
	cout << "Users will decide amongst themselves who will be player 1 in each game/round." << endl << endl;


	cout << "PvC:" << endl << endl;
	cout << "Pile size ranging from 10 to 100 will be randomly determined in each game." << endl;
	cout << "User will play against a computer." << endl;
	cout << "In each game, there is a 50-50 chance of the computer either being \"stupid\" or \"smart\"." << endl;
	cout << "In each game, there is a 50-50 chance that determines whether the user or the computer goes first." << endl << endl << endl;


	cout << "Would you like to play? (Enter P to play and enter E to exit): ";
	string start;
	cin >> start;
	while (start != "P" && start != "p" && start != "E" && start != "e")
	{
		cin.clear();
		cout << "Error. Continue? (Please enter P to play and enter E to exit): ";
		cin >> start;
	}

	cout << endl;
	if (start == "P" || start == "p")
	{

		string again = "E";
		string mode = "E";

		do
		{

			again = "E";

			cout << "Enter \"P\" for PvP and \"C\" for PvC (Enter E to exit): ";
			cin >> mode;   // Possible exit point

			while (mode != "P" && mode != "p" && mode != "C" && mode != "c" && mode != "E" && mode != "e")
			{
				cin.clear();
				cout << "Error. Please enter \"P\" for PvP and \"C\" for PvC: ";
				cin >> mode;	// Possible exit point
			}


			srand(time(0));


			if (mode == "C" || mode == "c")
			{
				cout << endl << endl << "NEW GAME (PvC)" << endl << endl;

				cout << "(ENTER Q AT ANY POINT IN THE GAME TO QUIT GAME AND ENTER E AT ANY POINT TO EXIT PROGRAM)" << endl << endl;

				int pile = rand() % (100 - 9) + 10;
				cout << "Pile size is " << pile << endl;

				int intelligence = rand() % 2;

				if (intelligence == 0)
				{
					cout << "The computer is stupid" << endl;
				}
				else
				{
					cout << "The computer is smart" << endl;
				}

				int first_turn = rand() % 2;

				int comp_value;
				string user_value;
				// Initially defined as a string so that a user has the option to quit game or exit program when asked to enter an amount

				string play;

				if (first_turn == 0)
				{
					cout << "The computer goes first" << endl << endl;
					cout << "Continue? (Y/N): ";
					cin >> play;	// Possible exit point or quitting point
					while (play != "Y" && play != "y" && play != "N" && play != "n" && play != "Q" && play != "q" && play != "E" && play != "e")
					{
						cin.clear();
						cout << "Error. Continue? (Please enter Y for yes and N for no): ";
						cin >> play;	// Possible exit point or quitting point
					}
					cout << endl;

					if (play == "Y" || play == "y")
					{
						if (intelligence == 0)
						{
							comp_value = rand() % (pile / 2) + 1;
						}
						else
						{
							if (pile == 3 || pile == 7 || pile == 15 || pile == 31 || pile == 63)
							{
								comp_value = rand() % (pile / 2) + 1;
							}
							else
							{
								if (pile > 63)
								{
									comp_value = pile - 63;
								}
								else if (pile > 31)
								{
									comp_value = pile - 31;
								}
								else if (pile > 15)
								{
									comp_value = pile - 15;
								}
								else if (pile > 7)
								{
									comp_value = pile - 7;
								}
								else if (pile > 3)
								{
									comp_value = pile - 3;
								}
								else
								{
									comp_value = 1;
								}
							}
						}

						cout << "Computer has taken " << comp_value << endl;
						pile -= comp_value;
						cout << "Pile size: " << pile << endl << endl;
					}
				}
				else
				{
					cout << "You are going first" << endl << endl;
					cout << "Continue? (Y/N): ";
					cin >> play;	// Possible exit point or quitting point
					while (play != "Y" && play != "y" && play != "N" && play != "n" && play != "Q" && play != "q" && play != "E" && play != "e")
					{
						cin.clear();
						cout << "Error. Continue? (Please enter Y for yes and N for no): ";
						cin >> play;	// Possible exit point or quitting point
					}
					cout << endl;
				}


				if (play == "Y" || play == "y")
				{

					while (pile > 1)
					{
						cout << "Choose an amount to take out: ";
						cin >> user_value;	// Possible exit point or quitting point

						string min = "1";

						if (user_value == "E" || user_value == "e")
						{
							play = "E";
							break;
						}
						else if (user_value == "Q" || user_value == "q")
						{
							break;
						}
						else if (user_value < min || user_value >= "A" || stod(user_value) > pile / 2 || round(stod(user_value)) != stod(user_value))
						{
							while (user_value < min || user_value >= "A" || stod(user_value) > pile / 2 || round(stod(user_value)) != stod(user_value))
							{
								cin.clear();
								cout << "Error. Please enter an integer value ranging from 1 to half of the current pile value: ";
								cin >> user_value;	// Possible exit point or quitting point
								if (user_value == "E" || user_value == "e")
								{
									play = "E";
									break;
								}
								else if (user_value == "Q" || user_value == "q")
								{
									play = "Q";
									break;
								}
							}
						}

						if (play == "E" || play == "e")
						{
							break;
						}
						else if (play == "Q" || play == "q")
						{
							break;
						}


						// converting to int before performing arithmetic on user value with an int variable
						int player_value = stoi(user_value);

						pile -= player_value;

						cout << "Pile size: " << pile << endl << endl;

						if (pile == 1)
						{
							cout << "You won!" << endl << endl;
							break;
						}

						cout << "Computer's turn" << endl;

						if (intelligence == 0)
						{
							comp_value = rand() % (pile / 2) + 1;
						}
						else
						{
							if (pile == 3 || pile == 7 || pile == 15 || pile == 31 || pile == 63)
							{
								comp_value = rand() % (pile / 2) + 1;
							}
							else
							{
								if (pile > 63)
								{
									comp_value = pile - 63;
								}
								else if (pile > 31)
								{
									comp_value = pile - 31;
								}
								else if (pile > 15)
								{
									comp_value = pile - 15;
								}
								else if (pile > 7)
								{
									comp_value = pile - 7;
								}
								else if (pile > 3)
								{
									comp_value = pile - 3;
								}
								else
								{
									comp_value = 1;
								}
							}
						}

						cout << "Computer has taken " << comp_value << endl;
						pile -= comp_value;

						cout << "Pile size: " << pile << endl << endl;

						if (pile == 1)
						{
							cout << "You lost." << endl << endl;
						}

					}
				}


				if (play != "E" && play != "e")
				{
					cout << endl;
					cout << "Play again?(Y/N): ";
					cin >> again;	// Possible exit point
					while (again != "Y" && again != "y" && again != "N" && again != "n" && again != "E" && again != "e")
					{
						cin.clear();
						cout << "Error. Play again? (Please enter Y for yes and N for no): ";
						cin >> again;	// Possible exit point
					}
					cout << endl;
				}
			}
			else if (mode == "P" || mode == "p")
			{
				cout << endl << endl << "NEW GAME (PvP)" << endl << endl;

				cout << "(ENTER Q AT ANY POINT IN THE GAME TO QUIT GAME AND ENTER E AT ANY POINT TO EXIT PROGRAM)" << endl << endl;

				int pile = rand() % (100 - 9) + 10;
				cout << "Pile size is " << pile << endl;


				string user_value;
				// Initially defined as a string so that a user has the option to quit game or exit program when asked to enter an amount


				string play = "Y";

				while (pile > 1)
				{
					cout << "Player 1's turn." << endl;
					cout << "Choose an amount to take out: ";
					cin >> user_value;	// Possible exit point or quitting point

					string min = "1";

					if (user_value == "E" || user_value == "e")
					{
						play = "E";
						break;
					}
					else if (user_value == "Q" || user_value == "q")
					{
						break;
					}
					else if (user_value < min || user_value >= "A" || stod(user_value) > pile / 2 || round(stod(user_value)) != stod(user_value))
					{
						while (user_value < min || user_value >= "A" || stod(user_value) > pile / 2 || round(stod(user_value)) != stod(user_value))
						{
							cin.clear();
							cout << "Error. Please enter an integer value ranging from 1 to half of the current pile value: ";
							cin >> user_value;	// Possible exit point or quitting point
							if (user_value == "E" || user_value == "e")
							{
								play = "E";
								break;
							}
							else if (user_value == "Q" || user_value == "q")
							{
								play = "Q";
								break;
							}
						}
					}

					if (play == "E" || play == "e")
					{
						break;
					}
					else if (play == "Q" || play == "q")
					{
						break;
					}


					// converting to int before performing arithmetic on user value with an int variable
					int player_value = stoi(user_value);

					pile -= player_value;

					cout << "Pile size: " << pile << endl << endl;

					if (pile == 1)
					{
						cout << "Player 1 won!" << endl;
						break;
					}

					cout << "Player 2's turn." << endl;
					cout << "Choose an amount to take out: ";
					cin >> user_value;	// Possible exit point or quitting point

					if (user_value == "E" || user_value == "e")
					{
						play = "E";
						break;
					}
					else if (user_value == "Q" || user_value == "q")
					{
						break;
					}
					else if (user_value < min || user_value >= "A" || stod(user_value) > pile / 2 || round(stod(user_value)) != stod(user_value))
					{
						while (user_value < min || user_value >= "A" || stod(user_value) > pile / 2 || round(stod(user_value)) != stod(user_value))
						{
							cin.clear();
							cout << "Error. Please enter an integer value ranging from 1 to half of the current pile value: ";
							cin >> user_value;	// Possible exit point or quitting point
							if (user_value == "E" || user_value == "e")
							{
								play = "E";
								break;
							}
							else if (user_value == "Q" || user_value == "q")
							{
								play = "Q";
								break;
							}
						}
					}

					if (play == "E" || play == "e")
					{
						break;
					}
					else if (play == "Q" || play == "q")
					{
						break;
					}


					// converting to int before performing arithmetic on user value with an int variable
					player_value = stoi(user_value);

					pile -= player_value;

					cout << "Pile size: " << pile << endl << endl;

					if (pile == 1)
					{
						cout << "Player 2 won!" << endl;
						break;
					}

				}


				if (play != "E" && play != "e")
				{
					cout << endl << endl;
					cout << "Play again?(Y/N): ";
					cin >> again;	// Possible exit point
					while (again != "Y" && again != "y" && again != "N" && again != "n" && again != "E" && again != "e")
					{
						cin.clear();
						cout << "Error. Play again? (Please enter Y for yes and N for no): ";
						cin >> again;	// Possible exit point
					}
					cout << endl;
				}

			}


		} while (again == "Y" || again == "y");

	}


	return 0;

}
