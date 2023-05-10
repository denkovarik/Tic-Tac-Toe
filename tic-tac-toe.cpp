#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

enum tic_tac_toe_marker // enum for the markers 'x' 'o' and blank positions on the board
    {
    ttt_blank_position_1 = '1',
    ttt_blank_position_2 = '2',
    ttt_blank_position_3 = '3',
    ttt_blank_position_4 = '4',
    ttt_blank_position_5 = '5',
    ttt_blank_position_6 = '6',
    ttt_blank_position_7 = '7',
    ttt_blank_position_8 = '8',
    ttt_blank_position_9 = '9',
    ttt_x = 10,
    ttt_o = 11,
    ttt_e = 12 //indicates that an error has occurred
    };
tic_tac_toe_marker ttt_value; // initializes variable for enum tic_tac_toe_marker

char position_1; // variables for each position on the board
char position_2;
char position_3;
char position_4;
char position_5;
char position_6;
char position_7;
char position_8;
char position_9;

int position_1_taken;
int position_2_taken;
int position_3_taken;
int position_4_taken;
int position_5_taken;
int position_6_taken;
int position_7_taken;
int position_8_taken;
int position_9_taken;

int chosen_position = 30;
char play_again = 'Y';

void one_player_instructions (); //Prints the instructions for the game
void two_player_instructions ();
void board ();
int rand_num (int high, int low); //function that chooses random numbers for the computer
void place_X_marker (int chosen_position);
void place_O_marker (int chosen_position);
int computer ();
int end_game ();
int winner ();

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
            position_1_taken = 0;
            position_2_taken = 0;
            position_3_taken = 0;
            position_4_taken = 0;
            position_5_taken = 0;
            position_6_taken = 0;
            position_7_taken = 0;
            position_8_taken = 0;
            position_9_taken = 0;

            position_1 = ttt_blank_position_1; // initializes each position to its respective value found in the tic-tac-toe marker enum to indicate it is blank.
            position_2 = ttt_blank_position_2;
            position_3 = ttt_blank_position_3;
            position_4 = ttt_blank_position_4;
            position_5 = ttt_blank_position_5;
            position_6 = ttt_blank_position_6;
            position_7 = ttt_blank_position_7;
            position_8 = ttt_blank_position_8;
            position_9 = ttt_blank_position_9;

            play_again = 'e';

            one_player_instructions (); //function that prints out the instructions for the game

            double turn_double = 0;

            for (int turn = 0; chosen_position != 0 && end_game () == 0; turn ++) // each iteration of the loop represents a turn
            {
                double half_of_turn_double = turn_double / 2; // a double (number) used to help determine is turn is even
                                                                            // turn == turn_double
                bool turn_is_even = half_of_turn_double == turn / 2; // bool used to help determine if the turn is even

                if (turn_is_even && chosen_position != 0) //decides who's turn it is
                {
                    ttt_value = ttt_x;
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
                    ttt_value = ttt_o;
                }

                while (chosen_position < 0 || chosen_position > 9) //detects invalid entries for chosen position
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nInvalid position. Please chosen an open box from 1 to 9 as shown below. \n" << endl;
                    board();
                    cout << "Position: ";
                    cin >> chosen_position;
                    cout << endl;
                }

                if (ttt_value == ttt_x)
                {
                    while ((chosen_position == position_1_taken || chosen_position == position_2_taken || chosen_position == position_3_taken || chosen_position == position_4_taken || chosen_position == position_5_taken || chosen_position == position_6_taken || chosen_position == position_7_taken || chosen_position == position_8_taken || chosen_position == position_9_taken) && chosen_position != 0)
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

                    place_X_marker (chosen_position);
                }
                else if (ttt_value == ttt_o) //computer
                {
                    computer ();

                    place_O_marker(chosen_position);
                }
                else
                {
                    cout <<"error" << endl;
                }

                switch (chosen_position) //marks positions as taken when a marker is placed in it
                {
                case 1:
                    position_1_taken = 1;
                    break;
                case 2:
                    position_2_taken = 2;
                    break;
                case 3:
                    position_3_taken = 3;
                    break;
                case 4:
                    position_4_taken = 4;
                    break;
                case 5:
                    position_5_taken = 5;
                    break;
                case 6:
                    position_6_taken = 6;
                    break;
                case 7:
                    position_7_taken = 7;
                    break;
                case 8:
                    position_8_taken = 8;
                    break;
                case 9:
                    position_9_taken = 9;
                    break;
                default:
                    break;
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
            position_1_taken = 0;
            position_2_taken = 0;
            position_3_taken = 0;
            position_4_taken = 0;
            position_5_taken = 0;
            position_6_taken = 0;
            position_7_taken = 0;
            position_8_taken = 0;
            position_9_taken = 0;

            position_1 = ttt_blank_position_1; //
            position_2 = ttt_blank_position_2;
            position_3 = ttt_blank_position_3;
            position_4 = ttt_blank_position_4;
            position_5 = ttt_blank_position_5;
            position_6 = ttt_blank_position_6;
            position_7 = ttt_blank_position_7;
            position_8 = ttt_blank_position_8;
            position_9 = ttt_blank_position_9;

            play_again = 'e';

            two_player_instructions(); //function that prints out the instructions for the game

            double turn_double = 0;

            for (int turn = 0; chosen_position != 0 && end_game () == 0; turn ++)
            {
                chosen_position = 30; // variable that represents the player's chosen position on the board
                double half_of_turn_double = turn_double / 2; // a double (number) used to help determine is turn is even
                                                                            // turn == turn_double
                bool turn_is_even = half_of_turn_double == turn / 2; // bool used to help determine is the turn is even

                if (turn_is_even && chosen_position != 0)
                {
                    ttt_value = ttt_x;
                    cout << "Player 1's turn \n" << endl;
                    cout << "Please choose a position to place the 'X' marker or enter '0' to exit the game." << endl;
                    cout << endl;
                    board ();
                }
                else if (chosen_position != 0)
                {
                    ttt_value = ttt_o;
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

                if (ttt_value == ttt_x)
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

                    place_X_marker (chosen_position);
                }
                else if (ttt_value == ttt_o)
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

                    place_O_marker(chosen_position);
                }
                else
                {
                    cout <<"error" << endl;
                }

                switch (chosen_position)
                {
                case 1:
                    position_1_taken = 1;
                    break;
                case 2:
                    position_2_taken = 2;
                    break;
                case 3:
                    position_3_taken = 3;
                    break;
                case 4:
                    position_4_taken = 4;
                    break;
                case 5:
                    position_5_taken = 5;
                    break;
                case 6:
                    position_6_taken = 6;
                    break;
                case 7:
                    position_7_taken = 7;
                    break;
                case 8:
                    position_8_taken = 8;
                    break;
                case 9:
                    position_9_taken = 9;
                    break;
                default:
                    break;
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

void place_X_marker (int chosen_position)
{
    switch (chosen_position)
    {
    case 0:
        break;
    case 1:
        position_1 = 'X';
        break;
    case 2:
        position_2 = 'X';
        break;
    case 3:
        position_3 = 'X';
        break;
    case 4:
        position_4 = 'X';
        break;
    case 5:
        position_5 = 'X';
        break;
    case 6:
        position_6 = 'X';
        break;
    case 7:
        position_7 = 'X';
        break;
    case 8:
        position_8 = 'X';
        break;
    case 9:
        position_9 = 'X';
        break;
    default:
        break;
    }
}

void place_O_marker (int chosen_position)
{
    switch (chosen_position)
    {
    case 0:
        break;
    case 1:
        position_1 = 'O';
        break;
    case 2:
        position_2 = 'O';
        break;
    case 3:
        position_3 = 'O';
        break;
    case 4:
        position_4 = 'O';
        break;
    case 5:
        position_5 = 'O';
        break;
    case 6:
        position_6 = 'O';
        break;
    case 7:
        position_7 = 'O';
        break;
    case 8:
        position_8 = 'O';
        break;
    case 9:
        position_9 = 'O';
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

        if (position_5 == '5' && rand_num(9,1) > 2)
        {
            chosen_position = 5;
        }
        else if (position_1 == 'O' && position_2 == 'O' && rand_num (9,1) > 2)
        {
            chosen_position = 3;
        }
        else if (position_2 == 'O' && position_3 == 'O' && rand_num (9,1) > 2)
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
    bool all_positions_are_taken = (position_1 == 'X' || position_1 == 'O') && (position_2 == 'X' || position_2 == 'O') && (position_3 == 'X' || position_3 == 'O') && (position_4 == 'X' || position_4 == 'O') && (position_5 == 'X' || position_5 == 'O') && (position_6 == 'X' || position_6 == 'O') && (position_7 == 'X' || position_7 == 'O') && (position_8 == 'X' || position_8 == 'O') && (position_9 == 'X' || position_9 == 'O');
    bool player_1_wins = (position_1 == 'X' && position_2 == 'X' && position_3 == 'X') || (position_4 == 'X' && position_5 == 'X' && position_6 == 'X') || (position_7 == 'X' && position_8 == 'X' && position_9 == 'X') || (position_1 == 'X' && position_4 == 'X' && position_7 == 'X') || (position_2 == 'X' && position_5 == 'X' && position_8 == 'X') || (position_3 == 'X' && position_6 == 'X' && position_9 == 'X') || (position_1 == 'X' && position_5 == 'X' && position_9 == 'X') || (position_3 == 'X' && position_5 == 'X' && position_7 == 'X');
    bool player_2_wins = (position_1 == 'O' && position_2 == 'O' && position_3 == 'O') || (position_4 == 'O' && position_5 == 'O' && position_6 == 'O') || (position_7 == 'O' && position_8 == 'O' && position_9 == 'O') || (position_1 == 'O' && position_4 == 'O' && position_7 == 'O') || (position_2 == 'O' && position_5 == 'O' && position_8 == 'O') || (position_3 == 'O' && position_6 == 'O' && position_9 == 'O') || (position_1 == 'O' && position_5 == 'O' && position_9 == 'O') || (position_3 == 'O' && position_5 == 'O' && position_7 == 'O');

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











