#include <bits/stdc++.h>
using namespace std; 

class heap{
    public:
     int arr[100];
     int size;

     heap(){
        size=0;
        arr[0]=-1;
     }
     // Insertion in heap
     void insert(int val){
        size=size+1;
        int index = size;
        arr[index]=val;

        while(index>1){
            int parentIndex = index/2;
            if(arr[parentIndex]<arr[index]){
                swap(arr[index],arr[parentIndex]);
                index=parentIndex;
            }else{
                return;
            }
        }


     }

     void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
     }
     

     // Deletion in heap ( we delete always root node)
     void deletion(){
        arr[1]=arr[size];
        size--;

        int i=1;
        while(i<size){
            if(2*i < size && arr[i]<arr[2*i]){
                swap(arr[i],arr[2*i]);
                i=2*i;
            }else if(2*i + 1 && arr[i]<arr[2*i +1]){
                swap(arr[i],arr[2*i +1]);
                i=2*i+1;
            }else{
                return;
            }
        }
     }
};

void heapify(int arr[], int n, int i){
    int largest=i;

    int left= 2*i;
    int right= 2*i +1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }

    if(right<=fn && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    int t=n;
    while(t>1){
        swap(arr[t],arr[1]);
        t--;

        heapify(arr,t,1);
    }
}

int main(){
     /*
     heap h;
     h.insert(50);
     h.insert(55);
     h.insert(53);
     h.insert(52);
     h.insert(54);

     h.print();

     h.deletion();
     h.print();
     */

     int arr[6]={-1,54,53,55,52,50};
     int n = 5;

     for(int i= n/2 ; i>0; i--){
        heapify(arr,n,i);
     }

     cout<<"Printing the heap now \n";

     for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
     }cout<<endl;

     heapSort(arr,n);

     cout<<"Printing Sorted Heap \n";
     for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
     }cout<<endl;

     
    return 0;
}