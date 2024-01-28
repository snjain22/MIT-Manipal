#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){

    int *M, n;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0 ; i<n ; i++){
        printf("Enter %dth Element: ", i);
        scanf("%d", &arr[i]);
    }

    M = (int*) malloc (sizeof(int)*(pow(2,n)));

    

}
