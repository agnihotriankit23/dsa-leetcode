#include <bits/stdc++.h>
using namespace std; 

// Create Binary tree form Inorder and preorder traversal
/* 

void createMap(vector<int>& inorder, map<int,int>& nodeToIndex,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& index,int inorderStarting,int inorderEnding,int n,map<int,int>& nodeToIndex){
        if(index>=n || inorderStarting>inorderEnding){
            return NULL;
        }
        
        int e= preorder[index++];
        int pos= nodeToIndex[e];
        TreeNode* root= new TreeNode(e);
        root->left= solve(preorder,inorder,index,inorderStarting,pos-1,n,nodeToIndex);
        root->right= solve(preorder,inorder,index,pos+1,inorderEnding,n,nodeToIndex);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n= preorder.size();
        int inorderStarting=0;
        int inorderEnding =n-1;
        map<int,int> nodeToIndex;
        createMap(inorder,nodeToIndex,n);
        TreeNode* ans= solve(preorder,inorder,index,inorderStarting,inorderEnding, n,nodeToIndex);
        return ans;
    }



*/

// Create Binary tree from Inorder and postorder traversal

/*
 void createMap(vector<int>& inorder,int n, map<int,int>& nodeToIndex){
        for(int i=0;i<n;i++){
            nodeToIndex[inorder[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int& index,int inorderStarting, int inorderEnding, int n, map<int,int>& nodeToIndex){
        
        if(index<0 || inorderStarting>inorderEnding){
            return NULL;
        }
        
        int e= postorder[index--];
        TreeNode* root= new TreeNode(e);
        int pos= nodeToIndex[e];
        
         root->right= solve(inorder,postorder,index,pos+1,inorderEnding,n,nodeToIndex);
        root->left= solve(inorder,postorder,index,inorderStarting,pos-1,n,nodeToIndex);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n= postorder.size();
        int index= n-1;
        int inorderStarting=0;
        int inorderEnding= n-1;
        map<int,int> nodeToIndex;
        createMap(inorder,n,nodeToIndex);
        TreeNode* ans= solve(inorder,postorder,index,inorderStarting,inorderEnding,n,nodeToIndex);
        return ans;
    }

*/

int main(){

    return 0;
}