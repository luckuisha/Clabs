#include <stdio.h>
#include <stdbool.h>
//#include "lab7part2lib.h"

void initboard(char board[][26], int num);
void printboard(char board[][26], int num);
void configboard(char board[][26]);
bool availmoves(char board[][26], int num);
bool colouravailmoves(char board[][26], int num, char colour);
void printinboard(char board[][26], int num);
void AIslayer(char board[][26], int num, char colour);
void winner(char board[][26], int num, char colour);
int human(char board[][26], int num, char colour);
bool positioninbounds(int num, char row, char col);
bool checklegalindirection(char board[][26], int num, char row, char col, char colour, int deltarow, int deltacol);
bool checkmove(char board[][26], int num, int i, int j, char colour);

int main(int argc, char **argv)
{
    int n;
    char board[26][26], humancolour, compcolour;
    
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    initboard(board, n);
    
    printf("Computer plays (B/W) : ");
    scanf(" %c", &compcolour);
    if (compcolour=='B')
        humancolour='W';
    else if (compcolour=='W')
        humancolour='B';
    printboard(board, n);
    
    if(compcolour=='B')
        while(availmoves(board, n))
        {
            if(colouravailmoves(board, n, compcolour))
            {
                AIslayer(board, n, compcolour);
                printboard(board, n);
            }
            else if(!colouravailmoves(board, n, compcolour) && availmoves(board, n))
                    printf("%c has no valid move.\n", compcolour);
            
            if(colouravailmoves(board, n, humancolour))
            {
                if(human(board, n, humancolour)==0)
                    return 0;
                printboard(board, n);
            }
            else if(!colouravailmoves(board, n, humancolour) && availmoves(board, n))
                    printf("%c has no valid move.\n", humancolour);
                    
        }
    
    else if(compcolour=='W')
    {
        while(availmoves(board, n))
        {
            if(colouravailmoves(board, n, humancolour))
            {
                if(human(board, n, humancolour)==0)
                    return 0;
                printboard(board, n);
            }
            else if(!colouravailmoves(board, n, humancolour) && availmoves(board, n))
                    printf("%c has no valid move.\n", humancolour);
            if(colouravailmoves(board, n, compcolour))
            {
                AIslayer(board, n, compcolour);
                printboard(board, n);
            }
            else if(!colouravailmoves(board, n, compcolour) && availmoves(board, n))
                    printf("%c has no valid move.\n", compcolour);
        }
            
    }
    
    if(!availmoves(board, n))
        winner(board, n, compcolour);

    return 0;
}

void initboard(char board[][26], int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if((i == j && i == num / 2) || (i == j && i == num/2-1))
                board[i][j] = 'W';
            else if ((j == i + 1 && j == num / 2) || (j + 1 == i && j == num / 2 - 1))
                board[i][j] = 'B';
            else
                board[i][j] = 'U';
        }
    }
}

void printboard(char board[][26], int num)
{
    int i, j, k;
    char x = 'a', y = 'a';
    printf("  ");
    for(k = 0; k < num; k++)
        {
            printf("%c", x);
            x++;
        }
    for (i = 0; i < num; i++)
    {
        printf("\n%c ", y);
        y++;
        for (j = 0;j < num; j++)
            {
                printf("%c", board[i][j]);
            }
    }
    printf("\n");
}

void configboard(char board[][26])
{
    char a, b, c;
    int x = 1, y = 1;
    do
    {
        scanf(" %c%c%c", &a, &b, &c);
        x = b - 97;
        y = c - 97;
        board[x][y]= a;
    }
    while(a != '!' && b != '!' && c != '!');
    if (a == '!' && b == '!' && c == '!')
        return;
}

bool positioninbounds(int num, char row, char col)
{
    int a = row - 97, b = col - 97;    
    if(a >= num || b >= num)
        return false;
    else if((a < num && a >= 0) && (b < num && b >= 0))
        return true;
    return false;
}

bool checklegalindirection(char board[][26], int num, char row, char col, char colour, int deltarow, int deltacol)
{
    char opcolour, i = 'a', j = 'a';
    int a, b, cnt = 0;
    if(colour == 'B')
        opcolour = 'W';
    else if (colour == 'W')
        opcolour = 'B';
    a = row - 97; // initial row int
    b = col - 97; // initial col int
        do
        {
            a += deltarow;
            b += deltacol;
            i = a + 97;
            j = b + 97;
            cnt++;
        }
        while (board[a][b] == opcolour && positioninbounds(num, i, j));
        if(positioninbounds(num, i, j))
        {
            if(board[a][b] == colour && cnt>1)
                return true;
            else if(board [a][b] == 'U')
                return false;
        }
        return false;
}

bool availmoves(char board[][26], int num)
{
    char row, col, colour;
    int deltarow, deltacol, i, j, k = 0;
    colour = 'B';
    do
    {
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
                            if(!(deltarow == 0 && deltacol == 0) && checklegalindirection(board, num, row, col, colour, deltarow, deltacol) && positioninbounds(num, row + deltarow, col + deltacol))
                                return true;
                        }
            }
                        
        }
    colour = 'W';
    k++;
    }
    while(k <= 1);
    return false;
}

void printinboard(char board[][26], int num)
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
                if(!(deltarow == 0 && deltacol == 0) && checklegalindirection(board, num, rowletter, colletter, colour, deltarow, deltacol) && positioninbounds(num, rowletter + deltarow, colletter + deltacol))
                {
                    board[i][j] = colour;
                    do
                    {
                        i += deltarow;
                        j += deltacol;
                        a = i + 97;
                        b = j + 97;
                        if(board[i][j] == opcolour && positioninbounds(num, a, b))
                            board[i][j] = colour;
                    }
                    while (board[i][j] == colour && positioninbounds(num, a, b) && board[i + deltarow][j + deltacol] == colour);
                }
            }
        if (board[x][y] == colour)
            printf("Valid move.\n");
        else if(board[x][y] == 'U')
            printf("Invalid move.\n");
    }
}

void AIslayer(char board[][26], int num, char colour)
{
    char a = 'a', b = 'a', opcolour, s='a', t='a';
    int i, j, deltarow, deltacol, score=0, cnt=0, x, y, p, q, inew, jnew;
    if (colour == 'B')
        opcolour = 'W';
    else if (colour == 'W')
        opcolour = 'B';
    for (i = 0; i < num; i++)
    {
        for(j = 0; j < num; j++)
        {
            cnt=0;
            if (checkmove(board, num, i, j, colour))
            {
                for (deltarow = -1; deltarow < 2; deltarow++)
                {
                    for (deltacol = -1; deltacol < 2; deltacol++)
                    {
                        p=i;
                        q=j;
                        do
                        {
                            p += deltarow;
                            q += deltacol;
                            a = i + 97;
                            b = j + 97;
                            if(board[p][q] == opcolour && positioninbounds(num, a, b))
                            {
                                cnt++;
                            }
                        }
                        while (positioninbounds(num, a, b) && board[p + deltarow][q + deltacol] == opcolour);
                    }
                }
                if((i==0 && j==0) || (i==num-1 && j==num-1) || (i==0 && j==num-1) || (i==num-1 && j==0)) //corners
                    cnt+=100;
                else if(!((i==0 && j==1) || (i==1 && j==0) || (i==num-2 && j==num-1) || (i==num-1 && j==num-2) || (i==0 && j==num-2) || (i==1 && j==num-1) || (i==num-1 && j==1) || (i==num-2 && j==0)) && (i==0 || j==0 || i==num-1 || j==num-1)) //sides
                    cnt+=50;
                else if((i==1 && j==1) || (i==num-2 && j==num-2) || (i==1 && j==num-2) || (i==num-2 && j==1) || (i==0 && j==1) || (i==1 && j==0) || (i==num-2 && j==num-1) || (i==num-1 && j==num-2) || (i==0 && j==num-2) || (i==1 && j==num-1) || (i==num-1 && j==1) || (i==num-2 && j==0)) //besides corner
					cnt+=-100;
				else if(!((i==1 && j==1) || (i==num-2 && j==num-2) || (i==1 && j==num-2) || (i==num-2 && j==1) || (i==0 && j==1) || (i==1 && j==0) || (i==num-2 && j==num-1) || (i==num-1 && j==num-2) || (i==0 && j==num-2) || (i==1 && j==num-1) || (i==num-1 && j==1) || (i==num-2 && j==0)) && (i==1 || i==num-2 || j==num-2 || j==1))
                    cnt+=-75;
                else if ( i==2 || j==2 || i==num-3 || j==num-3)
                    cnt+=10;            
                if (cnt+175>score)
                {
                    score=cnt+175;
                    x=i;
                    inew=x;
                    y=j;
                    jnew=y;
                    s='a'+x;
                    t='a'+y;
//                    printf("%d %d %c %c %d \n", x,y,s,t, score );
                }
            }
        }
    }
    for (deltarow = -1; deltarow < 2; deltarow++)
    {
        for (deltacol = -1; deltacol < 2; deltacol++)
        {
            x=inew;
            y=jnew;
            s='a'+x;
            t='a'+y;
            board[x][y] = colour;
            if(checklegalindirection(board, num, s ,t , colour, deltarow, deltacol))
            do
            {
                x += deltarow;
                y += deltacol;
                a = x + 97;
                b = y + 97;
                if(board[x][y] == opcolour && positioninbounds(num, a, b))
                    board[x][y] = colour;
            }
            while (board[x][y]== colour && positioninbounds(num, a, b) && board[x + deltarow][y + deltacol] == opcolour);
        }
    }
    printf("Computer places %c at %c%c \n", colour, s, t);
}

int human(char board[][26], int num, char colour)
{
    char rowletter, colletter, a = 'a', b = 'a', opcolour;
    int i, j, deltarow, deltacol, x, y, z=1;
    if (colour == 'B')
        opcolour = 'W';
    if (colour == 'W')
        opcolour = 'B';
        printf("Enter a move for %c (RowCol): ", colour);
		//findSmartestMove(board, num, colour, &i, &j);
		//printf("Testing AI move (row, col): %c%c\n", i+'a', j+'a');
		
        scanf(" %c%c", &rowletter, &colletter);
		i=rowletter-'a';
		j=colletter-'a';
        //rowletter=i+'a';
        //colletter=j+'a';
        x = i;
        y = j;
        if(board[i][j] == 'U')
        {
            for (deltarow = -1; deltarow < 2; deltarow++)
                for (deltacol = -1; deltacol < 2; deltacol++)
                {
                    if(!(deltarow == 0 && deltacol == 0) && checklegalindirection(board, num, rowletter, colletter, colour, deltarow, deltacol) && positioninbounds(num, rowletter + deltarow, colletter + deltacol))
                    {
                        i=x;
                        j=y;
                        board[i][j] = colour;
                        do
                        {
                            i += deltarow;
                            j += deltacol;
                            a = i + 97;
                            b = j + 97;
                            if(board[i][j] == opcolour && positioninbounds(num, a, b))
                                board[i][j] = colour;
                        }
                        while (board[i][j] == colour && positioninbounds(num, a, b) && board[i + deltarow][j + deltacol] == opcolour);
                    }
                }
            if(board[x][y] == 'U')
            {
                z=0;
                printf("Invalid move.\n%c player wins.", opcolour);
            }
        }
    return z;
}

void winner(char board[][26], int num, char colour)
{
    int i, j, colscore, opcolscore;
    char opcolour;
    if(colour == 'B')
        opcolour = 'W';
    else if (colour == 'W')
        opcolour = 'B';
    for(i=0; i<num; i++)
        for(j=0; j<num ;j++)
        {
            if (board[i][j]==colour)
                colscore++;
            else if (board[i][j]==opcolour)
                opcolscore++;                
        }
    if (colscore>opcolscore)
        printf("%c player wins.", colour);
    else if (colscore<opcolscore)
        printf("%c player wins.", opcolour);
    else if (colscore==opcolscore)
        printf("Draw!");
}

bool colouravailmoves(char board[][26], int num, char colour)
{
    char row, col;
    int deltarow, deltacol, i, j;
    {
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
                                if(!(deltarow == 0 && deltacol == 0) && checklegalindirection(board, num, row, col, colour, deltarow, deltacol) && positioninbounds(num, row + deltarow, col + deltacol))
                                    return true;
                            }
                }
                            
            }
    }
    return false;
}

bool checkmove(char board[][26], int num, int i, int j, char colour)
{
    char a, b;
    int deltarow, deltacol;
    a=i+'a';
    b=j+'a';
    if(board[i][j]=='U')
    {
        for (deltarow = -1; deltarow < 2; deltarow++)
        {
            for (deltacol = -1;deltacol < 2; deltacol++)
                    {
                        if(!(deltarow == 0 && deltacol == 0) && checklegalindirection(board, num, a, b, colour, deltarow, deltacol) && positioninbounds(num, a + deltarow, b + deltacol))
                                return true;
                                
                    }
        }
    }
    return false;
}

