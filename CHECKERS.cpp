#include <iostream>
#include <algorithm>
#include <conio.h>
#include <windows.h>

using namespace std;

char turn = 'W';
bool leap;
bool playing = true;
int row1, row2, column1, column2,Wwin=12,Bwin=12;

char board[8][8] =
{
    {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
    {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
    {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
};


void display_board();
void input();
bool check_move();
void move();
void do_leap();
void king();
bool game_over();
void gameRules();

int main()
{
    int option;
    char answ;

menu:
    system("Color 0A");
    cout << "-----------------------------------\n";
    cout << "--         CHECKERS GAME         --\n";
    cout << "-----------------------------------\n";
    cout << "Please select option:\n";
    cout << "1. Game Rules\n";
    cout << "2. Play game\n";
    cout << "3. Exit\n";
    cout << "Your option is:";
    cin >> option;
    switch (option) {
    case 1:
        gameRules();
        cout << "Do you want to go to menu? y/n:";
            cin >> answ;
            if (answ == 'y') {  goto menu; }
            else { cout << "Goodbye"; system("exit"); }
        break;
    case 2:
        while (playing)
        {
            system("cls");
            display_board();

            if (turn == 'W')
            {
                cout << "--Player 1 [W]--\n";
            }
            else if (turn == 'B')
            {
                cout << "--Player 2 [B]--\n";
            }

            input();
            move();
            king();

            if (game_over()) {
                system("exit");
            }
            
        }

    case 3:
        cout << "Goodbye";
        system("exit");
        break;
    }
}

void gameRules() {
    cout << "Player 1 [w]\n";
    cout << "Player 2 [b]\n\n";
    cout << "A capital letter represents a king piece.\n";
    cout << "Player 1 'b' starts the game\n";
    cout << "When you reach the end of oponents board piece, you will be king\n";
    cout << "Both players only can move cross the board\n";
    cout << "Choose coordinates between 1-8\n";
    cout << "Write row and column coordinates separated, for example '1 2'\n ";
}

void display_board()
{
    cout << "     1     2     3     4     5     6     7     8     \n";
    cout << "  _________________________________________________\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "1 |  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << "  |  " << board[0][4] << "  |  " << board[0][5] << "  |  " << board[0][6] << "  |  " << board[0][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "2 |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  " << board[1][3] << "  |  " << board[1][4] << "  |  " << board[1][5] << "  |  " << board[1][6] << "  |  " << board[1][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "3 |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  " << board[2][3] << "  |  " << board[2][4] << "  |  " << board[2][5] << "  |  " << board[2][6] << "  |  " << board[2][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "4 |  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  " << board[3][3] << "  |  " << board[3][4] << "  |  " << board[3][5] << "  |  " << board[3][6] << "  |  " << board[3][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "5 |  " << board[4][0] << "  |  " << board[4][1] << "  |  " << board[4][2] << "  |  " << board[4][3] << "  |  " << board[4][4] << "  |  " << board[4][5] << "  |  " << board[4][6] << "  |  " << board[4][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "6 |  " << board[5][0] << "  |  " << board[5][1] << "  |  " << board[5][2] << "  |  " << board[5][3] << "  |  " << board[5][4] << "  |  " << board[5][5] << "  |  " << board[5][6] << "  |  " << board[5][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "7 |  " << board[6][0] << "  |  " << board[6][1] << "  |  " << board[6][2] << "  |  " << board[6][3] << "  |  " << board[6][4] << "  |  " << board[6][5] << "  |  " << board[6][6] << "  |  " << board[6][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
    cout << "  |     |     |     |     |     |     |     |     |\n";
    cout << "8 |  " << board[7][0] << "  |  " << board[7][1] << "  |  " << board[7][2] << "  |  " << board[7][3] << "  |  " << board[7][4] << "  |  " << board[7][5] << "  |  " << board[7][6] << "  |  " << board[7][7] << "  |\n";
    cout << "  |_____|_____|_____|_____|_____|_____|_____|_____|\n";
}

void input()
{
    cout << "Player B:" << Wwin << " " << "Player W:" << Bwin << endl;
    cout << "Piece you want to move:\n";
    cout << "Row and Column: ";
    cin >> row1>>column1;
    row1 = row1 - 1;
    column1 = column1 - 1;
    while (row1 < 0 || row1 > 7 || column1 < 0 || column1 > 7)
    {
        cout << "Incorrect input. Enter numbers between 1 and 8.\n";
        cout << "Try again. Piece you want to move:\n";
        cin >> row1 >> column1;
        row1 = row1 - 1;
        column1 = column1 - 1;
    }

    cout << "Where you want to move?\n";
    cout << "Row and Column: ";
    cin >> row2 >> column2;
    row2 = row2 - 1;
    column2 = column2 - 1;

    while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
    {
        cout << "Incorrect input. Enter numbers between 1 and 8.\n";
        cout << "Try again. Where you want to move?\n";
        cout << "Row: ";
        cin >> row2 >> column2;
        row2 = row2 - 1;
        column2 = column2 - 1;
    }


    while (check_move() == false)
    {
        cout << "WRONG MOVE!\n";
        input();
    }
}


bool check_move()
{
    
    //checks player turn
    if (toupper(board[row1][column1]) != turn) {
        cout << "IT IS NOT YOUR TURN!!!\n\n";
        leap = false;
        return false;
    }
    
    // Checks if  piece is moving backwards
        if ((turn == 'W' && row2 < row1&&row2+2!=row1) || (turn == 'B' && row2 > row1&&row2-2!=row1))
        {
            leap = false;
            return false;
        }
        
        
    // Checks if the location the piece is moving to is already taken and if we have something to move
    if (board[row2][column2] != ' '|| board[row1][column1] == ' ')
    {
        leap = false;
        return false;
    }
    
    // Checks if the piece is moving to the directory
    if (column1 == column2 || row1 == row2)
    {
        leap = false;
        return false;
    }
   
     //Checks if the piece is moving by more than 1 column and only 1 row
    if ((board[row1][column1] != 'W') || (board[row1][column1] != 'B') ) {
        if ((column2 > column1 + 1 || column2 < column1 - 1) && (row2 == row1 + 1 || row2 == row1 - 1))
        {
            leap = false;
            return false;
        }
    }
        
       
    if (row2 > row1 + 1 || row2 < row1 - 1)
    {
        
        // Checks if the piece is leaping too far
        if (row2 > row1 + 2 || row2 < row1 - 2)
        {
            leap = false;
            return false;
        }

        //check if not leaping your own pieces
        if ((toupper(board[row2 - 1][column2 - 1]) == turn)|| (toupper(board[row2 + 1][column2 + 1]) == turn)) {
            leap = false;
            return false;
        }
        
        // Checks if the piece isn't moving by exactly 2 columns
        if (column2 != column1 + 2 && column2 != column1 - 2)
        {
            leap = false;
            return false;
        }
        

        // Checks if the piece is leaping over another piece from the other player
        
        char otherPlayer;
        if (toupper(board[row1][column1]) == 'B') {
            otherPlayer = 'W';
        }
        else {
            otherPlayer = 'B';
        }

        if (row2 > row1 && column2 > column1)
        {
            if (toupper(board[row2 - 1][column2 - 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 > row1 && column2 < column1)
        {
            if (toupper(board[row2 - 1][column2 + 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 > column1)
        {
            if (toupper(board[row2 + 1][column2 - 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 < column1)
        {
            if (toupper(board[row2 + 1][column2 + 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        
        leap = true;
        return true;
        
    } 
    
    
    
    leap = false;
    return true;
    
}

// Performs a move
void move()
{
    bool king_piece = false;

    if (board[row1][column1] == 'W' || board[row1][column1] == 'B')
    {
        king_piece = true;
    }

    board[row1][column1] = ' ';

    if (turn == 'W')
    {
        if (king_piece == false)
        {
            board[row2][column2] = 'w';
        }
        else if (king_piece == true)
        {
            board[row2][column2] = 'W';
        }

        turn = 'B';
    }
    else if (turn == 'B')
    {
        if (king_piece == false)
        {
            board[row2][column2] = 'b';
        }
        else if (king_piece == true)
        {
            board[row2][column2] = 'B';
        }

        turn = 'W';
    }

    if (leap == true)
    {
        do_leap();
    }
}

// Performs a leap over a checkers piece
void do_leap()
{
    char answer;

    // Removes the checker piece after leap
    if (row2 > row1 && column2 > column1)
    {
        board[row2 - 1][column2 - 1] = ' ';
        if (turn == 'W') { Bwin--; }
        else { Wwin--; }
    }
    else if (row2 > row1 && column2 < column1)
    {
        board[row2 - 1][column2 + 1] = ' ';
        if (turn == 'W') { Bwin--; }
        else { Wwin--; }
    }
    else if (row2 < row1 && column2 > column1)
    {
        board[row2 + 1][column2 - 1] = ' ';
        if (turn == 'W') { Bwin--; }
        else { Wwin--; }
    }
    else if (row2 < row1 && column2 < column1)
    {
        board[row2 + 1][column2 + 1] = ' ';
        if (turn == 'W') { Bwin--; }
        else { Wwin--; }
    }

    system("cls");
    display_board(); // Displays the board after the changes

    // Asks if the user wants to leap again
    do
    {
        cout << "You just leaped once. Do you want to try a second (y/n): ";
        cin >> answer;
    } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

    if (answer == 'y' || answer == 'Y')
    {
        row1 = row2;
        column1 = column2;
        cout << "Leap piece: row: " << row1 << ", column: " << column1 << endl;
        cout << "Move to:\n";
        cout << "row and column: ";
        cin >> row2 >> column2;
        row2 = row2 - 1;
        column2=column2-1;

        while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
        {
            cout << "Incorrect input. Enter numbers between 1 and 8.\n";
            cout << "Move to:\n";
            cout << "row and column: ";
            cin >> row2 >> column2;
        }

        if (turn == 'W')
        {
            turn = 'B';
        }
        else if (turn == 'B')
        {
            turn = 'W';
        }

        check_move();

        if (leap == false)
        {
            cout << "INVALID LEAP!\n";

            if (turn == 'W')
            {
                turn = 'B';
            }
            else if (turn == 'B')
            {
                turn = 'W';
            }
        }
        else if (leap == true)
        {
            move();
        }
    }
}

// Converts regular checkers pieces that have reached the other side of the board to king pieces
void king()
{
    for (int i = 0; i < 8; i++)
    {
        if (board[0][i] == 'b')
        {
            board[0][i] = 'B';
        }

        if (board[7][i] == 'w')
        {
            board[7][i] = 'W';
        }
    }
}

// Checks if game is over
bool game_over()
{
    if (Wwin > 0 && Bwin == 0) {
        cout << "Game is over!!!\n\n";
        cout << "Player 2[B] wins!!";
        playing = false;
        return true;
    }
    if (Wwin ==0 && Bwin > 0) {
        cout << "Game is over!!!\n\n";
        cout << "Player 1[W] wins!!";
        playing = false;
        return true;
    }
    return false;
}