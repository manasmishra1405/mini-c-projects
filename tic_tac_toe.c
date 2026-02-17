#include <stdio.h>

/*
    Tic Tac Toe Game
    ----------------
    Player 1 -> X
    Player 2 -> O
*/

/* Function to initialize the board with numbers 1 to 9 */
void initializeBoard(char board[3][3]) {
    char value = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

/* Function to display the current board */
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

/* Function to place player's move on the board */
int makeMove(char board[3][3], int choice, char player) {
    int row, col;

    /* Convert position (1-9) into row and column */
    row = (choice - 1) / 3;
    col = (choice - 1) % 3;

    /* Check if the selected position is free */
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = player;
        return 1;   // Valid move
    }

    return 0;       // Invalid move
}

/* Function to check if any player has won */
int checkWin(char board[3][3]) {

    /* Check all rows and columns */
    for (int i = 0; i < 3; i++) {

        /* Row check */
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return 1;
        }

        /* Column check */
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i]) {
            return 1;
        }
    }

    /* Diagonal checks */
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;   // No winner
}

/* Function to check if the game is a draw */
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0;   // Empty cell found
            }
        }
    }
    return 1;   // No empty cells
}

/* Main function */
int main() {
    char board[3][3];
    int choice;
    char currentPlayer = 'X';

    /* Initialize the board */
    initializeBoard(board);

    /* Game loop */
    while (1) {
        displayBoard(board);

        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &choice);

        /* Validate input */
        if (choice < 1 || choice > 9 ||
            !makeMove(board, choice, currentPlayer)) {
            printf("❌ Invalid move. Try again.\n");
            continue;
        }

        /* Check for win */
        if (checkWin(board)) {
            displayBoard(board);
            printf("🎉 Player %c wins!\n", currentPlayer);
            break;
        }

        /* Check for draw */
        if (checkDraw(board)) {
            displayBoard(board);
            printf("🤝 It's a draw!\n");
            break;
        }

        /* Switch player */
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
