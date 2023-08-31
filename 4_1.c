/*1)	Implement a menu driven program to define a stack of characters.
Include push, pop and display functions.

Also include functions for checking error conditions such as underflow and overflow
(ref. figure 1) by defining isEmpty and isFull functions.

Use these function in push, pop and display functions appropriately.

Use type defined structure to define a STACK containing a
character array and an integer top. Do not use global variables.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int TOP;
    char Arr[MAX];
} STACK;

void isEmpty()
{
    printf("STACK IS EMPTY!\n");
}

void isFull()
{
    printf("STACK IS FULL!\n");
}

void Push(STACK *p, char X)
{
    if (p->TOP == MAX - 1)
    {
        isFull();
        printf("OverFlow! ");
    }
    else
    {
        p->TOP += 1;
        (p->Arr[p->TOP]) = X;
    }
}



int POP(STACK *p)
{
    if ((p->TOP) == -1)
    {
        isEmpty();
        printf("UNDERFLOW!");
    }
    else
    {
        printf("Popped Element: %c\n", p->Arr[p->TOP]);
        p->TOP--;
        
    }
}

int Display(STACK *p)
{
    if (p->TOP == -1)
    {
        isEmpty();
    }

    else
    {        
        for (int i = p->TOP; i >= 0; i--)
        {
            printf("| %c |\n", p->Arr[i]);
        }
    }
}

void main()
{
    STACK S;
    int n, ch;
    char X;
    S.TOP = -1;

    while (1)
    {
        printf("--MENU--\nEnter\n1 - Pushing Elements\n2-Popping Elements\n3-Displaying\n4-Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("--Pushing Elements!--\n");
            printf("Enter Num of Elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter Element %d: ", i + 1);
                scanf(" %c", &X);
                Push(&S, X);
            }
        }

        else if (ch == 2)
        {
            printf("--Popping Elements--\n");
            printf("Enter Number of Elements: ");
            scanf("%d", &n);
            if (S.TOP+1 - n >= 0)
            {
                for (int i = 0; i < n; i++)
                {
                    POP(&S);
                }
            }

            else if( S.TOP==-1)
            {
                POP(&S);
            }
            else
            {
                printf("You cannot delete %d elements from a stack of length %d!", n, S.TOP+1);
            }
        }

        else if (ch == 3)
        {
            printf("--Displaying Elements--\n");
            Display(&S);
        }

        else if (ch == 4)
        {
            printf("--Exiting--");
            break;
        }
    }

}
