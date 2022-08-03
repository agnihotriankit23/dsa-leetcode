#include <bits/stdc++.h>
using namespace std; 


// Kth smallest element 
int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> heap;
        
        for(int i=0;i<k;i++){
            heap.push(arr[i]);
        }
        
        for(int i=k;i<=r;i++){
            if(arr[i]<heap.top()){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        return heap.top();
    }


// kth Largest Element

int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> heap;
        
        for(int i=0;i<k;i++){
            heap.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>heap.top()){
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }


// IS BINARY TREE HEAP
// IS CBT
// IS MAX HEAP

 int nodeCount(struct Node* tree){
      if(tree==NULL) return 0;
      
      int ans = 1 + nodeCount(tree->left) + nodeCount(tree->right);
      return ans;
  }
  bool isCBT(struct Node* tree,int i,int ct){
      if(tree==NULL) return true;
      
      if(i>=ct) return false;
      else{
          
            bool left = isCBT(tree->left,2*i + 1,ct);
            bool right= isCBT(tree->right,2*i + 2,ct);
      
            return (left && right);
      }
  }
  bool isMAXHeap(struct Node* tree){
      //if(tree==NULL) return true;
      if(tree->left==NULL && tree->right==NULL) return true;
     
      if(tree->right==NULL){
          return (tree->data > tree->left->data);
         
      }
      else
      {
      bool left= isMAXHeap(tree->left);
      bool right= isMAXHeap(tree->right);
     return (left && right && (tree->data > tree->left->data  && tree->data > tree->right->data));
     
      }
  }
    bool isHeap(struct Node* tree) {
        // code here
        int ct= nodeCount(tree);
        return ( isCBT(tree,0,ct) && (isMAXHeap(tree)));
    }


// Merge two Max heaps

void heapify(vector<int>& ans,int size, int i){
        int largest=i;
        
        int left = 2*i +1;
        int right = 2*i + 2;
        
        if(left<size && ans[largest]<ans[left]){
            largest=left;
        }
        
        if(right<size && ans[right]>ans[largest]){
            largest=right;
        }
        
        if(largest!=i){
            swap(ans[largest],ans[i]);
            heapify(ans,size,largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto i:b){
            ans.push_back(i);
        }
        int size= n+m;
        for(int i=size/2 -1 ; i>=0;i--){
            heapify(ans,size,i);
        }
        
        return ans;
        
    }


// Min cost of ropes

 long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long , vector<long long> , greater<long long> > pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        long long ans=0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq. top();
            pq.pop();
            
            long long cost = a+b ;
            ans+=cost;
             pq.push(cost);
        }
        return ans;
    }

// Convert BST to min Heap

void getInorder(BinaryTreeNode* root, vector<int>& v){
        if(root==NULL) return;
        getInorder(root->left,v);
        v.push_back(root->data);
        getInorder(root->right,v);
}
void makePreOrder(BinaryTreeNode* root,vector<int> v,int* i){
    //if(i>=v.size()) return;
    if(root==NULL) return ;
    
    root->data= v[++*i];
    makePreOrder(root->left,v,i);
    makePreOrder(root->right,v,i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
    vector<int> v;
    getInorder(root,v);
    //BinaryTreeNode* newRoot;
    int i=-1;
    makePreOrder(root,v,&i);
    return root;
}


int main(){
     

    return 0;
}