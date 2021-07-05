#include <iostream>
#include <climits>

using namespace std;

int kadanesAlgo(int arr[],int size){
    int overallMax = arr[0];
    int currentMax = arr[0];
    for (int i{1};i<size;i++){
        currentMax = max(currentMax + arr[i],arr[i]);
        overallMax = max(overallMax,currentMax);
    };
    return overallMax;
};

