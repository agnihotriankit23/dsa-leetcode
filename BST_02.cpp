#include <bits/stdc++.h>
using namespace std; 



// Validate the BST
bool checkBST(Node* root, long long min, long long max){
    if(root==NULL){
        return true;
    }
    if(min< root->data && root->data<max){
        bool left= checkBST(root->left,min,root->data);
        bool right= checkBST(root->right,root->data,max);
        return (left && right);

    }else{
        return false;
    }
}
bool isValidBST(Node* root){
    return checkBST(root,LONG_MIN,LONG_MAX);
}

//Kth smallest number in an BST

int solve(Node* root,int& i,int k){
    if(root==NULL){
        return -1;
    }
    int left= solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }
    return solve(root->right,i,k);
}
int kthSmallest(Node* root, int k){
    int i=0;
    return solve(root,i,k);
}

//Kth largest element in a BST

void solve(Node* root,vector<int>& v){
        if(root==NULL){
            return ;
        }
        solve(root->left,v);
        v.push_back(root->data);
        solve(root->right,v);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> v;
        solve(root,v);
        int n= v.size();
        return v[n-K];
    }

    // Lowest Common Ancestor in BST

    TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* curr= root;
        while(curr!=NULL){
            if((p->val <= curr->val && q->val >= curr->val) || (p->val >= curr->val && q->val <= curr->val)){
                return curr;
            }else if(p->val > curr->val && q->val > curr->val){
                curr=curr->right;
            }else if(p->val< curr->val && q->val < curr->val){
                curr=curr->left;
            }
        }
        return NULL;
    }
    
int main(){
     

    return 0;
}