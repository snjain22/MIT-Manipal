// #include<stdio.h>

// void main(){
//     int opCount = 0;
//     char s[100], sub[100];
//     printf("Enter String: ");
//     gets(s);

//     printf("Enter Substring: ");
//     gets(sub);

//     printf("String: %s\nSubstring: %s\n", s, sub);

//     int i= 0, flag = 0, match=0;
//     while(s[i] != '\0'){

//         if (s[i] == sub[0]){
//             printf("At %dth position, potential match found.\n", i);
//             match= i;
//             for (int j = 0 ; sub[j]!='\0' ; j++){
        
//                 opCount++;
        
//                 flag = 0;
//                 if(s[i] == sub[j]){
//                     flag = 1;
//                     i++;
//                 }
//             }
//         }

//         if (flag==1){
//             printf("String Match Found at %d", match);
//             break;
//         }
//         i++;    
//     }
//     if (flag==0){
//            printf("! %s not present in given %s. !",sub, s);
//     }
//     printf("\nOpCount: %d", opCount);
// }

#include<stdio.h>
#include<stdlib.h>
int Sum(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}
void PowerSet(int arr[], int n, int subset[], int subsetSize, int index, int *found, int *opcount) {
    (*opcount)++;
    if (index == n) {
        if (Sum(subset, subsetSize) == Sum(arr, n) / 2) {
            *found = 1;
        }
        return;
    }
    subset[subsetSize] = arr[index];
    PowerSet(arr, n, subset, subsetSize + 1, index + 1, found, opcount);
    PowerSet(arr, n, subset, subsetSize, index + 1, found, opcount);
}
int Partition(int arr[], int n, int *opcount) {
    int subset[n];
    int found = 0;
    PowerSet(arr, n, subset, 0, 0, &found, opcount);
    return found;
}
int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int opcount = 0;
    int result = Partition(arr, n, &opcount);
    printf("Set: {");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    if (result) {
        printf("Partition is possible.\n");
    } else {
        printf("Partition is not possible.\n");
    }
    printf("Number of operations: %d\n", opcount);
    return 0;
}
