#include<bits/stdc++.h>
using namespace std;
//Merge Sort
void mergeArray(int* arr, int s, int e){
	int mid= s+ (e-s)/2;
	int len1= mid-s+1;
	int len2= e-mid;
	int n=len1+len2;
	int A1[len1];
	int A2[len2];

	int k=0;
	for(k;k<len1;k++){
		A1[k]=arr[k];
	}
	
	for(int i=0;i<len2;i++){
		A2[i]=arr[k++];
	}
	k=0;

	int ind1=0;
	int ind2=0;
	while(ind1<len1 && ind2<len2){
		if(A1[ind1]<A2[ind2]){
			arr[k]=A1[ind1];
			ind1++;
			k++;
		}else{
			arr[k]=A2[ind2];
			ind2++;
			k++;
		}
	}
	while(ind1<len1){
		arr[k]=A1[ind1];
		k++;
		ind1++;
	}
	while(ind2<len2){
		arr[k]=A2[ind2];
		k++;
		ind2++;
	}


}


void mergeSort(int* arr, int s,int e){
	if(s>=e){
		return;
	}
	int mid= s+ (e-s)/2;

	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	mergeArray(arr,s,e);
}



int main(){
	   int arr[10]={23,4,1,78,90,0,5,6,6,8};
	   int n=10;
	   for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	   }
	   cout<<endl;
	   mergeSort(arr,0,9);
	   for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	   }
	   cout<<endl;
	}