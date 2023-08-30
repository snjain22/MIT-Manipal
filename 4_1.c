/*1)	Implement a menu driven program to define a stack of characters. 
Include push, pop and display functions. 
Also include functions for checking error conditions such as underflow and overflow 
(ref. figure 1) by defining isEmpty and isFull functions. 
Use these function in push, pop and display functions appropriately. 
Use type defined structure to define a STACK containing a 
character array and an integer top. Do not use global variables.*/
#include<stdio.h>

#define MAX 10


typedef struct 
{
    int TOP;
    char Arr[MAX];
} STACK;



void Push(STACK *p, char X)
{
    if (p->TOP == MAX-1)
        printf("OverFlow! ");
    else
        (p->Arr[p->TOP]) = X;
    
}

int POP(STACK *p)
{
    if ((p->TOP)==0)
    {
        printf("UNDERFLOW!");
    }
    else
    {
        p->TOP = (p->TOP)--;
        return p->TOP;
    }
}

int Display(STACK *p)
{
    for(int i=p->TOP ; i>=0 ; i-- )
    {
        printf("| %d |\n------", p->Arr[i]);
    }
}

void main()
{
    STACK S, *p;
    int n;
    char X;
    printf("Enter No.: ");
    scanf("%d", &n);
    S.TOP=-1;

    // for (int i = 0 ; i<n ; i++)
    // {
        scanf("%d", &X);
        // Push(&S,X);
    // }
    if (p->TOP == MAX-1)
        printf("OverFlow! ");
    else
    {
        printf("TOP: %d\n", S.TOP);
        printf("%d", p->Arr[p->TOP++]);
        
    }

    Display(&S);
}
