#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    int arr[n], temp, OC=0;

    printf("Enter Elements: ");
    
    for(int i = 0 ; i<n ; i++){
        printf("Enter %dth Element: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n-i-1 ; j++){
            
            OC++;

            if (arr[j] > arr[j+1]){           
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("ARRAY AFTER SORTING: \n");
    for(int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
    printf("OpCount: %d", OC);
}
