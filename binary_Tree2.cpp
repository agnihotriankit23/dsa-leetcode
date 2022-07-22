#include<bits/stdc++.h>
using namespace std;
//Hieght of a binary tree
class Solution {
    private:
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftDepth = solve(root->left);
        int rightDepth = solve(root->right);
        if(leftDepth>rightDepth){
            return(leftDepth+1);
        }else{
            return(rightDepth+1);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        //if(root==NULL) return -1;
        int ans=solve( root);
        return ans;
    }
};

// Diameter of Binary Tree
 pair<int,int> diameterFast(TreeNode* root){
        if(root==NULL) {
            pair<int,int> p= make_pair(0,0);
            return p;
        }
        
        pair<int,int> left= diameterFast(root->left);
        pair<int,int> right= diameterFast(root->right);
        
        int op1= left.first;
        int op2= right.first;
        int op3= left.second + right.second +1;
        
        pair<int,int> ans;
        ans.first= max(op1,max(op2,op3));
        ans.second= max(left.second,right.second)+1;
        return ans;
    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first -1;
    }

// Check for Balanced  Tree
 pair<bool,int> solve(TreeNode* root){
        if(root==NULL){
            pair<bool,int> p= make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left= solve(root->left);
        pair<bool,int> right = solve(root->right);
        
        bool op1= left.first;
        bool op2 = right.first;
        bool op3= abs(left.second-right.second)<=1;
        int h= max(left.second,right.second)+1;
        pair<bool,int> ans;
        ans.first= (op1 && op2 && op3);
        ans.second= h;
        return ans;
        
    }
    bool isBalanced(TreeNode* root) {
       return solve(root).first;
    }



// Determine Two Trees are identical or not
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        bool left= isSameTree(p->left,q->left);
        bool right= isSameTree(p->right,q->right);
        bool val = ( p->val== q->val);
        return (left && right && val);
    }


// Sum tree 
pair<bool,int> sumTree(Node* root){
        if(root==NULL){
            pair<bool,int> p= make_pair(true,0);
            return p;
        }
        if(root->left==NULL && root->right==NULL){
             pair<bool,int> p= make_pair(true,root->data);
            return p;
        }
         pair<bool,int> left= sumTree(root->left);
         pair<bool,int> right= sumTree(root->right);
         
         pair<bool,int> ans;
         
         ans.first= ((left.second+right.second)==root->data) && (left.first ) && (right.first);
         ans.second= (left.second+right.second)+root->data;
         return ans;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return sumTree(root).first;
    }

int main(){



    return 0;
}