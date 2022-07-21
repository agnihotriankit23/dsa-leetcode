#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    // cin>>n;
    n=10;
    int arr[n]={45,7,3,45,90,2,33,12,78,4};


    

    int count=1;
    while(count<n){
        for(int i=0;i<n-count;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        count++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}