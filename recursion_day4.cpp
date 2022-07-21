#include<bits/stdc++.h>
using namespace std;
// reverse a string using recursion
void reverseString(string& s, int i, int j){
    if(i>j) return ;
    swap(s[i],s[j]);
    i++;
    j--;
    reverseString(s,i,j);
}

//Check pallindrome
bool checkPal(string s,int i,int j){
    if(i>j) return true;
    if(s[i]!=s[j]) return false;
    i++;
    j--;
    bool ans=checkPal(s,i,j);
    return ans;
}

//  Calculate Power using Recusion
 int power(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    int ans= power(a,b/2);
    if(b%2==0){
        return ans*ans;
    }else{
        return a*ans*ans;
    }
 }

 // Bubble sort using recursion
 void bubbleSort(int *arr, int n){
    if(n==1 || n==0){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
 }

int main(){
    string s="abbccbba";
    reverseString(s,0,s.size()-1);
    cout<<s<<endl;
    cout<<checkPal(s,0,s.size()-1)<<endl;
    cout<<power(2,10)<<endl;
    int arr[]={4,7,23,5,1,9,0,45,33};
    bubbleSort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}