/*!
 * Author: bsandeepan95.work@gmail.com
 * Date: 08-Dec-2018

 * Notes:
    1.  IMPORTANT!! Can you make this playable in PVP and PVC?
        (Note: Read on Minimax algorithm for PvC. Read these -
            https://medium.freecodecamp.org/how-to-make-your-tic-tac-toe-game-unbeatable-by-using-the-minimax-algorithm-9d690bad4b37
            https://en.wikipedia.org/wiki/Minimax)
    2.  Can we implement a better draw checking code that does
         not need a counter for filled boxes?
    3.  ERROR: user giving char/str input for box number can cause segmentation error.
        Maybe try to not implement scanf at all? use fgets with strtol??

 * New Modifications:
    1.  Initial code is complete to deploy. (15-Dec-2018)
    2.  Successfully(?) implemented logic to run the game multiple
        times based on user's choice. (17-Dec-2018)

 * To add:
    1.  Implement ttt_list as a 2d array. Try to think how to
        make it work for 5x5 and 7x7 boards. (Note: Making
        the board names relevant as 00, 01, 02,... RowColumn
        may prove beneficial. Use string.h for ease maybe?)
    2.  New code for 5x5 and 7x7 print_board function.
    3.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

typedef enum {false, true}bool;     // defining own bool datatype


// functions start here
int my_cls()
{
    /** For reloading the screen every time a move is given.
        Should work on both Windows and Unix Systems.
    */
    system("cls||clear");   // Windows||Unix
    return 0;
}

int my_clean_stdin()
{
    //cleaning input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}


int print_board(char ttt_list[])        // prints the board
{
    /** Draws the 3x3 game board. */

    printf("       |     |     \n");    // 1,2,3
    printf("    %c  |  %c  |  %c  \n",
           ttt_list[0], ttt_list[1], ttt_list[2]);
    printf("  _____|_____|_____\n");

    printf("       |     |     \n");    // 4,5,6
    printf("    %c  |  %c  |  %c  \n",
           ttt_list[3], ttt_list[4], ttt_list[5]);
    printf("  _____|_____|_____\n");

    printf("       |     |     \n");    // 7,8,9
    printf("    %c  |  %c  |  %c  \n",
           ttt_list[6], ttt_list[7], ttt_list[8]);
    printf("       |     |     \n");

    printf("\n");
    return 0;
}


int user_input(bool select)
{
    /** Asks the user to choose a box number from the table. */
    int ch_i = 0;

    printf("Player %d: Enter box number to mark: ", (select + 1));
    scanf("%d", &ch_i);

    if ((0 < ch_i) && (ch_i < 10))
        return ch_i;
    else
    {
        my_clean_stdin();
        printf("Kindly choose a cell number available "
               "in the Tic Tac Toe table.\n");
        ch_i = user_input(select);
        return ch_i;
    }
}


bool user_mark(bool select, char player_mark[], char ttt_list[])
{
    /** Reads box no. given by user and marks the cell.
        How it works:
            The function is defined based on user providing an
            already marked cell number. If true, then it will
            recursively call itself until user gives the right input.
            Else, the box will mark the chosen cell with player's
            mark and returns a value to switch the player.
    */
    int choice;
    choice = user_input(select);    // getting the user choice

    if (ttt_list[choice - 1] == player_mark[0])
        printf("Invalid move! This cell is already marked by Player 1.\n");
    else if (ttt_list[choice - 1] == player_mark[1])
        printf("Invalid move! This cell is already marked by Player 2.\n");
    else
    {
        ttt_list[choice - 1] = player_mark[select];
        return !select;
    }
    // recursive call to rectify false selection
    return select = user_mark(select, player_mark, ttt_list);
}


bool check_for_win(char ttt_list[], char player_mark[], int mark_count, bool win)
{
    /** Checks for win and draw. */

    for (int i = 0; i < 2; i++)
    {
        if (((ttt_list[0] == ttt_list[1]) &&
             (ttt_list[1] == ttt_list[2]) &&
             (ttt_list[2] == player_mark[i]))  //012
                                        ||
            ((ttt_list[0] == ttt_list[3]) &&
             (ttt_list[3] == ttt_list[6]) &&
             (ttt_list[6] == player_mark[i]))  //036
                                        ||
            ((ttt_list[1] == ttt_list[4]) &&
             (ttt_list[4] == ttt_list[7]) &&
             (ttt_list[7] == player_mark[i]))  //147
                                        ||
            ((ttt_list[3] == ttt_list[4]) &&
             (ttt_list[4] == ttt_list[5]) &&
             (ttt_list[5] == player_mark[i]))  //345
                                        ||
            ((ttt_list[2] == ttt_list[5]) &&
             (ttt_list[5] == ttt_list[8]) &&
             (ttt_list[8] == player_mark[i]))  //258
                                        ||
            ((ttt_list[6] == ttt_list[7]) &&
             (ttt_list[7] == ttt_list[8]) &&
             (ttt_list[8] == player_mark[i]))  //678
                                        ||
            ((ttt_list[0] == ttt_list[4]) &&
             (ttt_list[4] == ttt_list[8]) &&
             (ttt_list[8] == player_mark[i]))  //048
                                        ||
            ((ttt_list[2] == ttt_list[4]) &&
             (ttt_list[4] == ttt_list[6]) &&
             (ttt_list[6] == player_mark[i]))  //246
           )
        {
            my_cls();
            printf("\nPlayer %d Wins!! Congratulations!!!\n\n", i + 1);
            print_board(ttt_list);
            return true;
        }
    }

    if ((mark_count == 9) && !win)  // TODO: Write a better draw checking code
    {
        printf("\nIt is a Draw!\n");
        return true;
    }

    return false;       // no win yet
}


int start_tictactoe()
{
    /** Starts the game. */
    char ttt_list[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player_mark[] = {'X', 'O'};
    bool win = false, select = false;   // select:(p1->0, p2->1)
    int mark_count = 0;

    while(!win)
    {
        my_cls();      // clears the screen to reload the board again
        printf("Tic Tac Toe (3x3) Game in C\n\n");
        printf("Player 1 (%c) : Player 2 (%c)\n\n", player_mark[0], player_mark[1]);

        print_board(ttt_list);

        select = user_mark(select, player_mark, ttt_list);
        mark_count++;

        win = check_for_win(ttt_list, player_mark, mark_count, win);
    }
    return 0;
}


int main(int argc, char **argv)
{
    bool again = true;
    int usr_ch = 0;

    while (again)
    {
        start_tictactoe();

        printf("Do you want to play again?\n"
               "Press 1 to Continue.\nPress 2 to Quit.\n"
               "Enter your choice: ");
        scanf("%d", &usr_ch);

        if (usr_ch == 1)
            continue;
        else if (usr_ch == 2)
        {
            again = false;
            printf("\nQuitting game. Thank you for playing.\n"
                   "Regards,\n- Sandeepan B.\n");
        }
        else
        {
            again = false;
            printf("\nInvalid input. Quitting game.\n");
        }
    }
    
    //pausing system for display
    printf("Press Enter to exit.\n");
    my_clean_stdin();
    getchar();
    return 0;
}
