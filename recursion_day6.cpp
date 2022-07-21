#include<bits/stdc++.h>
using namespace std;
//Quick Sort

int partition(int* arr, int s,int e){
    int pos=0;
    int pivot=arr[s];
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot) pos++;
    }
    int pivotIndex= s+ pos; //Important Point
    swap(arr[pivotIndex],arr[s]);
     pivot=arr[pivotIndex];
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(arr[i]>pivot && arr[j]<pivot){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int* arr , int s, int e){
    if(s>=e){
        return;
    }
    int p= partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[8]={6, 6, -6, -2, -4, -6, 2, -6 };
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    quickSort(arr,0,7);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0;
}