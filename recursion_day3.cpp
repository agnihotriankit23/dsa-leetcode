#include<bits/stdc++.h>
using namespace std;
//Find recursivly that given array is sorted or not
bool isSorted(int  *arr, int size){
    if(size==0 || size==1) return true;
    if(arr[0]>arr[1]) return false;
    bool ans= isSorted(arr+1,size-1);
    return ans;
}
// sum of all elements in array recursiely
int arraySum(int *arr,int size){
    if(size==0) return 0;
    int ans= arr[size-1] + arraySum(arr,size-1);
    return ans;
}

// Search  a element in a array
void searchArray(int * arr, int size , int key){
    if(size==0){
        cout<<"Element Not Found!!!!\n";
        return ;
    }
    if(arr[0]==key) {
        cout<<"Element Found!!! "<< endl;
        return;
    }
    searchArray(arr+1,size-1,key);
}

// Impliment Binary Search using Recursion
// *Array should be sorted
int binarySearch(int *arr , int s, int e , int key){
    if(e<s) {
        
        //cout<<"Element is not found!!\n";
        return -1;}
    int mid = s+ (e-s)/2;
    if(arr[mid]==key){
        cout<<"Element is Found!!\n";
        return mid;
    }else if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }else{
        return binarySearch(arr,s,mid-1,key);
    }
}


int main(){
 int arr[]={1,2,3,4,5};
 cout<< isSorted(arr,5)<<endl;
 cout<< arraySum(arr,5)<<endl;
 //searchArray(arr,5,5);
 cout<< "Element is found at Position "<<binarySearch(arr,0,4,4)<<endl;;
    return 0;
}