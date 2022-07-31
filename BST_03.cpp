#include <bits/stdc++.h>
using namespace std; 


// 2 Sum in a BST

void solve1(TreeNode* root, vector<int>& v){
        if(root==NULL){

        return;}
        
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        solve1(root,v);
        int i=0, j= v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k){
                return true;
            }else if(v[i]+v[j]> k){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }

//Flatten BST To A Sorted List

void solve(TreeNode<int>* root,vector<int >& v){
    if(root==NULL ){
        return;
    }
    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    
    vector<int > v;
    solve(root,v);
    TreeNode<int>* newROOT = new TreeNode<int>(v[0]);
    TreeNode<int>* curr= newROOT;
    for(int i=1;i<v.size();i++){
        TreeNode<int>* temp = new TreeNode<int>(v[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    return newROOT;
}

// Balance a Binary Search Tree

 void solve2(TreeNode* root, vector<int>& v){
        if(root==NULL){
            return;
        }
        
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
        
    }
    TreeNode* inorderToBST(int s, int e, vector<int> v){
        if(s>e){
            return NULL;
        }
        int mid= (s+e)/2;
        TreeNode* root= new TreeNode(v[mid]);
        root->left = inorderToBST(s,mid-1,v);
        root->right= inorderToBST(mid+1,e,v);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        solve2(root,v);
        TreeNode* newRoot= inorderToBST(0,v.size()-1,v);
        return newRoot;
    }

// Construct Binary Search Tree from Preorder Traversal
    TreeNode* solve(vector<int> preorder,int min,int max,int& i){
        if(i>= preorder.size()){
            return NULL;
        }
        
        if(preorder[i]<min || preorder[i]>max){
            return NULL;
        }
        
        TreeNode* root= new TreeNode(preorder[i++]);
        
        root->left= solve(preorder,min,root->val,i);
        root->right= solve(preorder,root->val,max,i);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min= INT_MIN;
        int max= INT_MAX;
        int i=0;
        return solve(preorder,min,max,i);
    }
    int main(){
     

    return 0;
    }