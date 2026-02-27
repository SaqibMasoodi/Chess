#include <stdio.h>

#define board_size 8

//--------------------------------------------------------------------//
// Function prototypes //
void print_board(int board[board_size][board_size]);
void initialize_board(int board[board_size][board_size]);
void move_piece(int board[board_size][board_size]);
void gameState(int board[board_size][board_size]);
void clear_screen();
//--------------------------------------------------------------------//

int main()
{
    int board[board_size][board_size] = {0};

    initialize_board(board);
    print_board(board);

    while(1)
    {
        move_piece(board);
        clear_screen();
        print_board(board);
    }
    return 0;
}

void clear_screen(){
    // Clear the console screen using ANSI escape codes
    system("cls");
}


void print_board(int board[board_size][board_size])
{
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (board[i][j] >= 0)
                printf("+%d ", board[i][j]);
            else
                printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void move_piece(int board[board_size][board_size])
{
    int piece;

    printf("Enter the piece you want to move:\n");
    printf(" 1. White Pawn\n");
    printf(" 2. White Rook\n");
    printf(" 3. White Knight\n");
    printf(" 4. White Bishop\n");
    printf(" 5. White Queen\n");
    printf(" 6. White King\n");
    printf("-1. Black Pawn\n");
    printf("-2. Black Rook\n");
    printf("-3. Black Knight\n");
    printf("-4. Black Bishop\n");
    printf("-5. Black Queen\n");
    printf("-6. Black King\n");

    scanf("%d", &piece);

    int to_x, to_y;
    printf("Enter the target position to move the piece (x y): ");
    scanf("%d %d", &to_x, &to_y);

    int old_x = -1, old_y = -1;

    // Find the original position
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (board[i][j] == piece)
            {
                old_x = i;
                old_y = j;
                break;
            }
        }
        if (old_x != -1)
            break;
    }

    if (old_x == -1)
    {
        printf("Piece not found on board!\n");
        return;
    }

    // Move piece
    board[to_x][to_y] = piece;

    // Clear old position
    board[old_x][old_y] = 0;
}

void initialize_board(int board[board_size][board_size])
{
    for (int i = 0; i < board_size; i++)
    {
        board[1][i] = 1;  // White pawns
        board[6][i] = -1; // Black pawns
    }

    board[0][0] = 2;
    board[0][1] = 3;
    board[0][2] = 4;
    board[0][3] = 5;
    board[0][4] = 6;

    board[7][0] = -2;
    board[7][1] = -3;
    board[7][2] = -4;
    board[7][3] = -5;
    board[7][4] = -6;
}

void gameState(int board[board_size][board_size])
{
}