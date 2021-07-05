#include <stdio.h>
#define max(a,b) ((a > b) ? a : b)


int kadanesAlgo(int arr[],int size){
    if (size == 0)return arr[0];
    int maxSoFar= arr[0];
    int maxResult = arr[0];
    for (int i = 1;i<size;i++){
        maxSoFar = max(maxSoFar + arr[i],arr[i]);
        maxResult = max(maxResult,maxSoFar);

    };
    return maxResult;

}



int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%i",&size);
    int arr[size];
    printf("Enter the values : ");
    for (int i = 0;i<size;i++){
        scanf("%i",&arr[i]);
    };
    int result = kadanesAlgo(arr,size);
    printf("The result is : %i\n",result);

    return 0;
}