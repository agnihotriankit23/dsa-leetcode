#include <bits/stdc++.h>
using namespace std; 

// Merge 2 BST

void inorderV(TreeNode<int> * root,vector<int>& v){
    if(root==NULL){
        return;
    }
    inorderV(root->left,v);
    v.push_back(root->data);
    inorderV(root->right,v);
}

TreeNode<int>* inorderToBst(int s, int e, vector<int> v){
    if(s>e){
        return NULL;
    }
    
    int mid=(s+e)/2;
    
    TreeNode<int> * root= new TreeNode<int>(v[mid]);
    root->left = inorderToBst(s,mid-1,v);
    root->right = inorderToBst(mid+1,e,v);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> v1;
    inorderV(root1,v1);
    vector<int> v2;
    inorderV(root2,v2);
    
    int n1= v1.size();
    int n2 = v2.size();
    
    int i=0,j=0;
    
    vector<int> v3;
    
    while(i<n1 && j<n2){
        if(v1[i]<v2[j]){
            v3.push_back(v1[i++]);
        }else{
            v3.push_back(v2[j++]);
        }
    }
    while(i<n1){
        v3.push_back(v1[i++]);
    }
    while(j<n2){
        v3.push_back(v2[j++]);
    }
    //int i=0;
    TreeNode<int> * newRoot= inorderToBst(0,v3.size()-1,v3);
    
    return newRoot;
    
    
}

int main(){
     

    return 0;
}