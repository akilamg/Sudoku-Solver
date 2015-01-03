#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define ROWS 9
#define COLS 9

void readboard(char board[ROWS][COLS])
{
    int i,j;
    FILE* infile;
    infile=fopen("sudoku_write.txt","r");
    for(i=0;i<ROWS;i++)
    {
         for(j=0;j<COLS;j++)
            fscanf(infile,"%c", &board[i][j]);

         fscanf(infile,"\n");
    }
    fclose(infile);
}

void printboard(char board[ROWS][COLS])
{
          int i,j;
          FILE* infile;
          infile=fopen("sudoku_result.txt","w");
          fprintf(infile, "Solution:");
          printf("\n");
          fprintf(infile, "\n");
          for (i=0;i<ROWS;i++)
          {
              printf("\t");
              for(j=0;j<COLS;j++)
              {
                  printf("%c ",board[i][j]);
                  fprintf(infile, "%c ", board[i][j]);

              }

              printf("\n");
              fprintf(infile, "\n");
          }
      printf("\n");

}

int checkval(char board[ROWS][COLS],int i,int j,char v)
{
    int x,y;
        for (x=0;x<9;x++)
        { if (x!=i)
             if (board[x][j]==v)return 0;
        }
        for (y=0;y<9;y++)
        { if (y!=j)
             if (board[i][y]==v)return 0;
        }
        for(x=(i/3)*3;x<(i/3)*3+3;x++)
        {    for(y=(j/3)*3;y<(j/3)*3+3;y++)
             {if ((x!=i)|| (y!=j))
                 if (board[x][y]==v) return 0;
              }
        }
return 1;
}

int solution(char board[ROWS][COLS],int i,int j)

{
    char v;
         if(j==9)
         {j=0;
          i++;
         }
    if (i==9)
       {printboard(board);
       return 1;
       }
    if (board[i][j]!='.')
       {if (solution(board,i,j+1))
           return 0;
       }
    else
    {for(v='1';v<='9';v++)
         if(checkval(board,i,j,v))
         {board[i][j]=v;
                        if (solution(board,i,j+1))
                           return 1;
         }
         board[i][j]='.';
    }
return 0;
}




int main(int argc,char *argv[])
{
char board[ROWS][COLS];
    readboard(board);
    printboard(board);
    solution(board,0,0);

system ("pause");
return 0;
}

