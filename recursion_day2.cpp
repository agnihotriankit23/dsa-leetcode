#include<bits/stdc++.h>
using namespace std;
 map<int,string> mp={{0,"Zero"},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
 void sayDigit(int n){
    if(n==0) return ;
    int r= n%10;
    
    n=n/10;
    sayDigit(n);
    cout<<mp[r]<<" ";
 }
 
 
int main(){
    int n;
    cin>> n;

    sayDigit(n);
    return 0;


 }