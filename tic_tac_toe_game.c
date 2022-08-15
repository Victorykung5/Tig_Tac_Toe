#include <stdio.h>
char board(int x[3][3])
{
    printf(" |1|2|3|\n=========\n1|%c|%c|%c|\n=========\n2|%c|%c|%c|\n=========\n3|%c|%c|%c|\n", x[0][0], x[0][1], x[0][2], x[1][0], x[1][1], x[1][2], x[2][0], x[2][1], x[2][2]);
    return 0;
}
char mark(int a)
{
    if (a == 1)
        return 'X';
    else
        return 'O';
}
int main()
{   //XO game!!!
    int c = 1, k = 0, f = 9, d, e, m;
    int x[3][3];
    int z, y = 1;
    int count = 0;
    while (y == 1)
    {   m=0;
        count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                x[i][j] = ' ';
            }
        }
        printf("%c", board(x));
        while (k != -1)
        {
            while (f != 0)
            {
                printf("Player %c turn (column,row):", mark(c));
                scanf("%d %d", &d, &e);
                if (d > 3 || e > 3 || d < 1 || e < 1 || x[d - 1][e - 1] != 32)
                {
                    printf("Invalid move!!!\n");
                    f = 1;
                }
                else
                {
                    f = 0;
                }
            }
            x[d - 1][e - 1] = mark(c);
            printf("%c", board(x));
            for (int i = 0; i < 3; i++)
            {
                int j = 0;
                if (((x[0][i] == x[1][i]) && (x[0][i] == x[2][i]) && x[0][i] != 32) || ((x[i][0] == x[i][1]) && (x[i][0] == x[i][2]) && x[i][0] != 32) || ((x[0][0] == x[1][1]) && (x[0][0] == x[2][2]) && x[0][0] != 32) || ((x[0][2] == x[1][1]) && (x[0][2] == x[2][0]) && x[0][2] != 32))
                {
                    printf("Player %c is the winner!!!\n", mark(c));
                    k = -1;
                    m++;
                    break;
                }
            }
            if (c == 2)
                c--;
            else
                c++;
            f++;
            count++;
            if (count == 9 && m == 0)
            {
                printf("Draw!!! No one win\n");
                break;
            }
        }
        printf("Do you want to try again?(Y/N)   :");
        scanf("%s", &z);
        k = 0;
        f = 9;
        y = 0;
     
        if (z == 89 || z == 121)
        {
            y = 1;
        }
        
    }
    printf("-----END-----");
    return 0;
}
