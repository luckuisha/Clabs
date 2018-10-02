#include <stdio.h>
#include <stdbool.h>
void initBoard(char board[][26], int num);
void printBoard(char board[][26], int num);
void configBoard(char board[][26]);
void availMoves(char board[][26], int num);		
void printInBoard(char board[][26], int num);
bool positionInBounds(int num, char row, char col);
bool checkLegalInDirection(char board[][26], int num, char row, char col, char colour, int deltarow, int deltacol);

int main(int argc, char **argv)
{
    int n;
    char board[26][26];
    
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    initBoard(board, n);
    printBoard(board, n);
    
    printf("Enter board configuration: \n");
    configBoard(board);
    printBoard(board, n);

    availMoves(board, n);
    
    printf("Enter a move: \n");
    printInBoard(board, n);
    printBoard(board, n);

    return 0;
}

void initBoard(char board[][26], int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if((i == j && i == num / 2) || (i == j && i == num/2-1))		//places W in corresponding locations
                board[i][j] = 'W';
            else if ((j == i + 1 && j == num / 2) || (j + 1 == i && j == num / 2 - 1))		//places B in corresponding locations
                board[i][j] = 'B';
            else
                board[i][j] = 'U';		//puts U everywhere else
        }
    }
}

void printBoard(char board[][26], int num)
{
    int i, j, k;
    char x = 'a', y = 'a';
    printf("  ");		//puts the space in the top left corner
    for(k = 0; k < num; k++)
        {
            printf("%c", x);		//prints the letters on the left
            x++;
        }
    for (i = 0; i < num; i++)
    {
        printf("\n%c ", y);		//prints letter on the top row before the array is printed
        y++;
        for (j = 0;j < num; j++)
            {
                printf("%c", board[i][j]);		//prints board
            }
    }
    printf("\n");
}

void configBoard(char board[][26])
{
    char a, b, c;		//a=colour, b=row, c=column
    int x = 1, y = 1;	//x=corresponding row for the letter b, y=corresponding col for the letter c
    do
    {
        scanf(" %c%c%c", &a, &b, &c);
        x = b - 97;
        y = c - 97;
        board[x][y]= a;
    }
    while(a != '!' && b != '!' && c != '!');
    if (a == '!' && b == '!' && c == '!')		//stops when a,b,c are !!!
        return;
}

bool positionInBounds(int num, char row, char col)
{
    int a = row - 97, b = col - 97;    //a and b are numbers corresponding to row in int and col in int
    if(a >= num || b >= num)		//this makes sure that a and b are within than the bounds or it returns false
        return false;
    else if((a < num && a >= 0) && (b < num && b >= 0))		//returns true if it is in bounds
        return true;
}

bool checkLegalInDirection(char board[][26], int num, char row, char col, char colour, int deltarow, int deltacol)
{
    char opcolour, i = 'a', j = 'a';	//opcolour=opposite, i=char correpsonding to row, j=char correpsonding to col
    int a, b, cnt = 0;		//a=initial row int, b=initial col int
    if(colour == 'B')
        opcolour = 'W';
    else if (colour == 'W')
        opcolour = 'B';
    a = row - 97; 
    b = col - 97; 
        do
        {
            a += deltarow;		//adds increment first
            b += deltacol;
            i = a + 97;		//increments i and j to check if position is in bounds, needs to be in char
            j = b + 97;
            cnt++;		//counter makes sure that the available moves prints only once
        }
        while (board[a][b] == opcolour && positionInBounds(num, i, j));
        if(positionInBounds(num, i, j))
        {
            if(board[a][b] == colour && cnt>1)
                return true;			//checks until the next slot is the same colour, and returns true. counter makes it print only once
            else if(board [a][b] == 'U')
                return false;		//returns false if the next slot is empty
        }
        return false;		//returns false for any other combination
}

void availMoves(char board[][26], int num)
{
    char row, col, colour;
    int deltarow, deltacol, i, j, k = 0;
    colour = 'W';		//initially beings with W, later switches to B
    do
    {
    printf("Available moves for %c:\n", colour);
    for (i = 0; i < num; i++)
        for(j = 0; j < num; j++)
        {
            row = i + 97;
            col = j + 97;
            if(board[i][j] == 'U')
            {
                for (deltarow = -1; deltarow < 2; deltarow++)
                    for (deltacol = -1;deltacol < 2; deltacol++)
                        {
                            if(!(deltarow == 0 && deltacol == 0) && checkLegalInDirection(board, num, row, col, colour, deltarow, deltacol) && positionInBounds(num, row + deltarow, col + deltacol))
                                printf("%c%c\n", row, col);
                        }
            }
                        
        }
    colour = 'B';
    k++;		//this makes it so it checks for B only once
    }
    while(k <= 1);
}

void printInBoard(char board[][26], int num)
{
    char colour, rowletter, colletter, a = 'a', b = 'a', opcolour;
    int i, j, deltarow, deltacol, x, y;
    scanf(" %c%c%c", &colour, &rowletter, &colletter);
    if (colour == 'B')
        opcolour = 'W';
    if (colour == 'W')
        opcolour = 'B';
    i = rowletter - 97;
    j = colletter - 97;
    x = i;
    y = j;
    if(board[i][j] == 'U')
    {
        for (deltarow = -1; deltarow < 2; deltarow++)
            for (deltacol = -1; deltacol < 2; deltacol++)
            {
                if(!(deltarow == 0 && deltacol == 0) && checkLegalInDirection(board, num, rowletter, colletter, colour, deltarow, deltacol) && positionInBounds(num, rowletter + deltarow, colletter + deltacol))
                {
                    board[i][j] = colour;		//if avail move, it changes the slot to colour
                    do
                    {
                        i += deltarow;		//increments in order to change colour
                        j += deltacol;
                        a = i + 97;
                        b = j + 97;
                        if(board[i][j] == opcolour && positionInBounds(num, a, b)) //keeps going until next slot is not opcolour
                            board[i][j] = colour; //then changes the colour at that spot
                    }
                    while (board[i][j] == colour && positionInBounds(num, a, b) && board[i + deltarow][j + deltacol] == colour);		//stops until the next slot is the original colour
                }
            }
        if (board[x][y] == colour)
            printf("Valid move.\n");
        else if(board[x][y] == 'U')
            printf("Invalid move.\n");
    }
}
