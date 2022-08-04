#include <bits/stdc++.h>
using namespace std; 


// K-th Largest Sum Subarray

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
     priority_queue<int, vector<int> , greater<int> > minHeap;
        int n= arr.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                
                if(minHeap.size()<k){
                    minHeap.push(sum);
                }else{
                    if(sum>minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                    }
                }
            }
        }
        return minHeap.top();
    }


// Merge K sorted Arrays

lass compare{
    public:
    bool operator()(node* a, node* b){
        return ( a->data > b->data);
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*> , compare > minHeap;
    for(int i=0; i<k ; i++){
        node* temp = new node(kArrays[i][0], i,0);
        minHeap.push(temp);
    }
    vector<int> ans;
    while(minHeap.size()>0){
        node* temp= minHeap.top();
        int i= temp->i_row;
        int j= temp->j_col;
        
        ans.push_back(temp->data);
        
        minHeap.pop();
        
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

// Merge K sorted Linked Lists

class Solution {
public:
    class compare{
      public:
        bool operator()(ListNode* a , ListNode* b){
            return ( a->val > b->val);
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , compare > minHeap;
        int k = lists.size();
        if(k==0) return NULL;
        for(int i=0;i<k;i++){
           if(lists[i] != NULL){
                minHeap.push(lists[i]);
           } 
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(minHeap.size()>0){
            ListNode* top = minHeap.top();
            minHeap.pop();
            
            if(top->next != NULL){
                minHeap.push(top->next);
            }
            if(head==NULL){
                head= tail = top;
            }else{
                tail->next= top;
                tail=top;
            }
            
        }
        return head;
    }
};

int main(){
     

    return 0;
}