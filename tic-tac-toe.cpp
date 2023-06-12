#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> board = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
};

char ttt_value = '';

int chosen_position = 30;
char play_again = 'Y';

void one_player_instructions (); //Prints the instructions for the game
void two_player_instructions ();
void board ();
int rand_num (int high, int low); //function that chooses random numbers for the computer
void place_marker (int chosen_position, char marker);
int computer ();
int end_game ();
int winner ();
bool position_taken(int pos);
bool all_positions_taken();
bool player_wins(char marker);
char board_at_position(int pos);

int main ()
{
    int selection;

    do
    {
        cout << "Welcome to Tic-Tac-Toe. \n\nEnter 1 for one-player Tic-Tac-Toe \nEnter 2 for two-player Tic-Tac-Toe \nEnter 0 to exit Tic-Tac-Toe\n" << endl;
        cout << "Selection: ";
        cin >> selection;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    }while (selection != 1 && selection != 2 && selection != 0);

    if (selection == 1)
    {
        char play_again;
        srand(time(NULL));

        do
        {
            play_again = 'e';

            one_player_instructions (); //function that prints out the instructions for the game

            double turn_double = 0;

            for (int turn = 0; chosen_position != 0 && end_game () == 0; turn++) // each iteration of the loop represents a turn
            {
                bool turn_is_even = (turn % 2 == 0);

                if (turn_is_even && chosen_position != 0) //decides who's turn it is
                {
                    ttt_value = 'X';
                    cout << "Player 1's turn \n" << endl;
                    cout << "Please choose a position to place the 'X' marker or enter '0' to exit the game." << endl;
                    cout << endl;
                    board ();
                    cout << "Position: ";
                    cin >> chosen_position;
                    cout << endl;
                }
                else if (chosen_position != 0)
                {
                    ttt_value = 'O';
                }

                while (chosen_position < 0 || chosen_position > 9) //detects invalid entries for chosen position
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nInvalid position. Please chosen an open box from 1 to 9 as shown below. \n" << endl;
                    board();
                    cout << "Position: ";
                    cin >> chosen_position;
                    cout << endl;
                }

                if (ttt_value == 'X')
                {
                    while (position_taken(chosen_position) && chosen_position != 0)
                    {
                        if (chosen_position == position_1_taken) // if statement used to determine if a position is already taken
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 1 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_2_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 2 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();                }
                        else if (chosen_position == position_3_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 3 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_4_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 4 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_5_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 5 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_6_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 6 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_7_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 7 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_8_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 8 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_9_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 9 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else
                        {

                        }

                        cout << "Position: ";
                        cin >> chosen_position;
                        cout << endl;
                    }

                    place_marker (chosen_position, 'X');
                }
                else if (ttt_value == 'O') //computer
                {
                    computer ();

                    place_marker(chosen_position, 'O');
                }
                else
                {
                    cout <<"error" << endl;
                }

                turn_double++;

                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

                if (end_game() == 1)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 1 Wins!!! :)\n\n\n" << endl;
                    board();
                }
                else if (end_game() == 2)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 Wins!!! :)\n\n\n" << endl;
                    board();
                }
                else if (end_game() ==3)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCat's Game  ^_^\n\n\n" << endl;
                    board();
                }
                else
                {
                    cout << endl;
                }
            }

            if (chosen_position != 0)
            {
                while (play_again != 'Y' && play_again != 'y' && play_again != 'N' && play_again != 'n')
                {
                    cout << "Play Again?" << endl;
                    cout << "(Y/N): ";
                    cin >> play_again;
                    cout << "\n\n" << endl;

                    if (play_again != 'Y' && play_again != 'y' && play_again != 'N' && play_again != 'n')
                    {
                        cout << "error" << endl;
                        cout << "Please enter 'Y' to replay the game or enter 'N' to exit. \n" << endl;
                    }
                }
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
            }
            else
            {
                play_again = 'N';
            }

        }while (play_again == 'Y' || play_again == 'y');
    }
    else if (selection == 2)
    {
        char play_again;

        do
        {
            play_again = 'e';

            two_player_instructions(); //function that prints out the instructions for the game

            double turn_double = 0;

            for (int turn = 0; chosen_position != 0 && end_game () == 0; turn ++)
            {
                chosen_position = 30; // variable that represents the player's chosen position on the board
                bool turn_is_even = (turn % 2 == 0);

                if (turn_is_even && chosen_position != 0)
                {
                    ttt_value = 'X';
                    cout << "Player 1's turn \n" << endl;
                    cout << "Please choose a position to place the 'X' marker or enter '0' to exit the game." << endl;
                    cout << endl;
                    board ();
                }
                else if (chosen_position != 0)
                {
                    ttt_value = 'O';
                    cout << "Player 2's turn \n" << endl;
                    cout << "Please choose a position to place the 'O' marker or enter '0' to exit the game." << endl;
                    cout << endl;
                    board();
                }

                cout << "Position: ";
                cin >> chosen_position;
                cout << endl;

                while (chosen_position < 0 || chosen_position > 9)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nInvalid position. Please chosen an open box from 1 to 9 as shown below. \n" << endl;
                    board();
                    cout << "Position: ";
                    cin >> chosen_position;
                    cout << endl;
                }

                if (ttt_value == 'X')
                {
                    while ((chosen_position == position_1_taken || chosen_position == position_2_taken || chosen_position == position_3_taken || chosen_position == position_4_taken || chosen_position == position_5_taken || chosen_position == position_6_taken || chosen_position == position_7_taken || chosen_position == position_8_taken || chosen_position == position_9_taken) && chosen_position != 0)
                    {
                        if (chosen_position == position_1_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 1 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_2_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 2 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();                }
                        else if (chosen_position == position_3_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 3 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_4_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 4 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_5_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 5 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_6_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 6 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_7_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 7 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_8_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 8 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_9_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 9 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'X' marker. \n" << endl;
                            board();
                        }

                        cout << "Position: ";
                        cin >> chosen_position;
                        cout << endl;
                    }

                    place_marker (chosen_position, 'X');
                }
                else if (ttt_value == 'O')
                {
                    while ((chosen_position == position_1_taken || chosen_position == position_2_taken || chosen_position == position_3_taken || chosen_position == position_4_taken || chosen_position == position_5_taken || chosen_position == position_6_taken || chosen_position == position_7_taken || chosen_position == position_8_taken || chosen_position == position_9_taken) && chosen_position != 0)
                    {
                        if (chosen_position == position_1_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 1 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_2_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 2 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_3_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 3 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_4_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 4 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_5_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 5 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_6_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 6 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_7_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 7 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_8_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 8 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }
                        else if (chosen_position == position_9_taken)
                        {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPosition 9 is already taken. \n\n\n\n\n\n\n\n\nPlease choose another position to place the 'O' marker. \n" << endl;
                            board();
                        }

                        cout << "Position: ";
                        cin >> chosen_position;
                        cout << endl;
                    }

                    place_marker(chosen_position, 'O');
                }
                else
                {
                    cout <<"error" << endl;
                }

                turn_double++;

                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

                if (end_game() == 1)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 1 Wins!!! :)\n\n\n" << endl;
                    board();
                }
                else if (end_game() == 2)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 Wins!!! :)\n\n\n" << endl;
                    board();
                }
                else if (end_game() ==3)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCat's Game  :(\n\n\n" << endl;
                    board();
                }
                else
                {
                    cout << endl;
                }


            }

            if (chosen_position != 0)
            {
                while (play_again != 'Y' && play_again != 'y' && play_again != 'N' && play_again != 'n')
                {
                    cout << "Play Again?" << endl;
                    cout << "(Y/N): ";
                    cin >> play_again;
                    cout << "\n\n" << endl;

                    if (play_again != 'Y' && play_again != 'y' && play_again != 'N' && play_again != 'n')
                    {
                        cout << "error" << endl;
                        cout << "Please enter 'Y' to replay the game or enter 'N' to exit. \n" << endl;
                    }
                }
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
            }
            else
            {
                play_again = 'N';
            }

        }while (play_again == 'Y' || play_again == 'y');
    }
    else if (selection == 0)
    {
        return 0;
    }
}




void one_player_instructions ()
{
    cout << "Welcome to One Player Tic-Tac-Toe." << endl;
    cout << endl;
    cout << "Each of the boxes are numbered as shown below. To place your marker in" << endl;
    cout << "a particular box, simply enter the number for that box into the 'Position'" << endl;
    cout << "command. You go first, and you use the 'X' marker." << endl;
    cout << "\nEnjoy!" << endl;
    cout << "\n" << endl;
}

void two_player_instructions()
{
    cout << "Welcome to two-player Tic-Tac-Toe." << endl;
    cout << endl;
    cout << "Each of the boxes are numbered as shown below. To place your marker in" << endl;
    cout << "a particular box, simply enter the number for that box into the 'Position'" << endl;
    cout << "command. Player 1 goes first and uses the 'X' marker." << endl;
    cout << "\nEnjoy!" << endl;
    cout << "\n" << endl;
}

void board ()
{
    cout << " " << position_1 << " | " << position_2 << " | " << position_3 << endl;
    cout << "---|---|---" << endl;
    cout << " " << position_4 << " | " << position_5 << " | " << position_6 << endl;
    cout << "---|---|---" << endl;
    cout << " " << position_7 << " | " << position_8 << " | " << position_9 << endl;
    cout <<  "\n" << endl;
}

int rand_num (int high, int low)
{
    return rand() % (high - low + 1) + low;
}

void place_marker (int chosen_position, char marker)
{
    switch (chosen_position)
    {
    case 0:
        break;
    case 1:
		board[0][0] = marker;
        break;
    case 2:
        board[0][1] = marker;
        break;
    case 3:
        board[0][2] = marker;
        break;
    case 4:
        board[1][0] = marker;
        break;
    case 5:
        board[1][1] = marker;
        break;
    case 6:
        board[1][2] = marker;
        break;
    case 7:
        board[2][0] = marker;
        break;
    case 8:
        board[2][1] = marker;
        break;
    case 9:
        board[2][2] = marker;
        break;
    default:
        break;
    }
}


int computer()
{
    while ((chosen_position == position_1_taken || chosen_position == position_2_taken || chosen_position == position_3_taken || chosen_position == position_4_taken || chosen_position == position_5_taken || chosen_position == position_6_taken || chosen_position == position_7_taken || chosen_position == position_8_taken || chosen_position == position_9_taken) && chosen_position != 0)
    {
        rand_num (9,1);

        // to win

        if (board_at_position(5) == '5' && rand_num(9,1) > 2)
        {
            chosen_position = 5;
        }
        else if (board_at_position(1) == 'O' && board_at_position(2) == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 3;
        }
        else if (board_at_position(2) == 'O' && board_at_position(3) == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 1;
        }
        else if (position_1 == 'O' && position_3 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 2;
        }
        else if (position_4 == 'O' && position_5 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 6;
        }
        else if (position_5 == 'O' && position_6 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 4;
        }
        else if (position_4 == 'O' && position_6 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 5;
        }
        else if (position_7 == 'O' && position_8 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 9;
        }
        else if (position_8 == 'O' && position_9 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 7;
        }
        else if (position_7 == 'O' && position_9 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 8;
        }
        else if (position_1 == 'O' && position_4 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 7;
        }
        else if (position_4 == 'O' && position_7 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 1;
        }
        else if (position_1 == 'O' && position_7 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 4;
        }
        else if (position_2 == 'O' && position_5 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 8;
        }
        else if (position_5 == 'O' && position_8 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 2;
        }
        else if (position_2 == 'O' && position_8 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 5;
        }
        else if (position_3 == 'O' && position_6 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 9;
        }
        else if (position_6 == 'O' && position_9 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 3;
        }
        else if (position_3 == 'O' && position_9 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 6;
        }
        else if (position_1 == 'O' && position_5 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 9;
        }
        else if (position_5 == 'O' && position_9 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 1;
        }
        else if (position_1 == 'O' && position_9 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 5;
        }
        else if (position_3 == 'O' && position_5 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 7;
        }
        else if (position_5 == 'O' && position_7 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 3;
        }
        else if (position_3 == 'O' && position_7 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 5;
        }

        //to not lose
        else if (position_1 == 'X' && position_2 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 3;
        }
        else if (position_1 == 'X' && position_3 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 2;
        }
        else if (position_2 == 'X' && position_3 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 1;
        }
        else if (position_4 == 'X' && position_5 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 6;
        }
        else if (position_4 == 'X' && position_6 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 5;
        }
        else if (position_5 == 'X' && position_6 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 4;
        }
        else if (position_7 == 'X' && position_8 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 9;
        }
        else if (position_7 == 'X' && position_9 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 8;
        }
        else if (position_8 == 'X' && position_9 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 7;
        }
        else if (position_1 == 'X' && position_4 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 7;
        }
        else if (position_1 == 'X' && position_7 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 4;
        }
        else if (position_4 == 'X' && position_7 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 1;
        }
        else if (position_2 == 'X' && position_5 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 8;
        }
        else if (position_2 == 'X' && position_8 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 5;
        }
        else if (position_5 == 'X' && position_8 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 2;
        }
        else if (position_3 == 'X' && position_6 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 9;
        }
        else if (position_3 == 'X' && position_9 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 6;
        }
        else if (position_6 == 'X' && position_9 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 3;
        }
        else if (position_1 == 'X' && position_5 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 9;
        }
        else if (position_1 == 'X' && position_9 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 5;
        }
        else if (position_5 == 'X' && position_9 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 1;
        }
        else if (position_3 == 'X' && position_5 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 7;
        }
        else if (position_3 == 'X' && position_7 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 5;
        }
        else if (position_5 == 'X' && position_7 == 'X' && rand_num (9,1) > 3)
        {
            chosen_position = 3;
        }
        else
        {
            chosen_position = rand_num (9,1);
        }
    }
    return chosen_position;
}

int end_game()
{
    int end_game;
    bool all_positions_are_taken = all_positions_taken();
    bool player_1_wins = player_wins('X');
    bool player_2_wins = player_wins('O');

    if (player_1_wins)
    {
        end_game = 1;
    }
    else if (player_2_wins)
    {
        end_game = 2;
    }
    else if (all_positions_are_taken)
    {
        end_game = 3;
    }
    else
    {
        end_game = 0;
    }
    return end_game;
}

bool position_taken(int pos)
{
	int row, col;
	
	if(pos < 1 || pos > 9)
	{
		return false;
	}
	
	pair<int, int> pos_rol_col = position_2_row_col_cnvrt(pos);
	
	if(board[pos_rol_col.first][pos_rol_col.second] != 'X' && board[pos_rol_col.first][pos_rol_col.second] != 'O')
	{
		return false;
	}
	
	return true;
}

pair<int, int> position_2_row_col_cnvrt(int pos)
{
	pair<int, int> grid_row_col;
	switch (chosen_position) 
	{
		case 1:
			grid_row_col.first = 0;
			grid_row_col.second = 0;
			break;
		case 2:
			grid_row_col.first = 0;
			grid_row_col.second = 1;
			break;
		case 3:
			grid_row_col.first = 0;
			grid_row_col.second = 2;
			break;
		case 4:
			grid_row_col.first = 1;
			grid_row_col.second = 0;
			break;
		case 5:
			grid_row_col.first = 1;
			grid_row_col.second = 1;
			break;
		case 6:
			grid_row_col.first = 1;
			grid_row_col.second = 2;
			break;
		case 7:
			grid_row_col.first = 2;
			grid_row_col.second = 0;
			break;
		case 8:
			grid_row_col.first = 2;
			grid_row_col.second = 1;
			break;
		case 9:
			grid_row_col.first = 2;
			grid_row_col.second = 2;
			break;
		default:
			grid_row_col.first = -1;
			grid_row_col.second = -1;
			break;
	}
}

bool all_positions_taken()
{
	for(int i = 0; i < 3; i++) 
	{
		for(int j = 0; j < 3; j++)
		{
			if(board[i][j] != 'X' && board[i][j] != 'O')
			{
				return false;
			}
		}
	}
	return true;
}

bool player_wins(char marker)
{
	bool wins; 
	
	for(int i = 0; i < 3; i++)
	{
		wins = true;
		for(int j = 0; j < 3; j++)
		{
			if(board[i][j] != marker)
			{
				wins = false;
			}
			
			if(wins)
			{
				return true;
			}
		}
	}
	
	for(int j = 0; j < 3; j++)
	{
		wins = true;
		for(int i = 0; i < 3; i++)
		{
			if(board[i][j] != marker)
			{
				wins = false;
			}
			
			if(wins)
			{
				return true;
			}
		}
	}
	
	wins = true;
	for(int i = 0; i < 3; i++)
	{
		if(board[i][i] != marker)
		{
			wins = false;
		}
			
		if(wins)
		{
			return true;
		}
	}
	
	wins = true;
	for(int i = 0; i < 3; i++)
	{
		if(board[i][2-i] != marker)
		{
			wins = false;
		}
			
		if(wins)
		{
			return true;
		}
	}
	
	return false;
}

char board_at_position(int pos)
{
	if(pos < 1 || pos > 9)
	{
		return 'e';
	}
	
	pair<int, int> row_col = position_2_row_col_cnvrt(pos);
	
	return board[row_col.first][row_col.second];
}







