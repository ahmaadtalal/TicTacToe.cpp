#include <iostream>
using namespace std;

const int SIZE = 3;

void displayBoard(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << " " << board[i][j] << " ";
            if (j < SIZE - 1)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i < SIZE - 1)
        {
            cout << "-----------" << endl;
        }
    }
}

bool checkWin(char board[SIZE][SIZE], char player)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        {
        return true;
        }

    return false;
}

bool checkTie(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void makeMove(char board[SIZE][SIZE], int row, int col, char player)
{
    if (board[row][col] == ' ')
    {
        board[row][col] = player;
    }
    else
    {
        cout << "Invalid move. Cell already occupied. Try again." << endl;
        cout << "Player " << player << ", enter your move (row and column, 0-2): ";
        cin >> row >> col;
        makeMove(board, row, col, player);
    }
}

int main()
{
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do
    {
        cout << "Current board:" << endl;
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column, 0-2): ";
        cin >> row >> col;

        makeMove(board, row, col, currentPlayer);

        if (checkWin(board, currentPlayer))
        {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (checkTie(board))
        {
            cout << "It's a tie!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    }
    while (true);

    cout << "Final board:" << endl;
    displayBoard(board);

    return 0;
}