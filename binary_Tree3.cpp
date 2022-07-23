#include <bits/stdc++.h>
using namespace std; 


// ZigZag Level Order Traversal

vector<vector<int>>  zigZagTraversal(TreeNode* root){
    vector<vector<int>> result;
    if(root==NULL)
    return result;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight=true;

    while(!q.empty()){
        int size= q.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++){
            TreeNode* temp= q.front();
            q.pop();

            int index= leftToRight ? i : size-i-1;
            ans[index]= temp->val;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        leftToRight=!leftToRight;
        result.push_back(ans);
    }
}

// Boundary Traversal 

void addLeftNode(Node* root, vector<int>& ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)) return ;

    ans.push_back(root->data);
    if(root->left) addLeftNode(root->left,ans);
    else addLeftNode(root->right,ans);
}

void addLeafNode(Node* root,vector<int>& ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    addLeafNode(root->left);
    addLeafNode(root->right);
}

void addRightNode(Node* root, vector<int>& ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)) return ;

     
    if(root->right) addRightNode(root->right,ans);
    else addRightNode(root->left,ans);
    ans.push_back(root->data);
}

vector<int> boundary(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;

    ans.push_back(root->data);

    addLeftNode(root->left,ans);

    addLeafNode(root->left,ans);
    addLeafNode(root->right,ans);

    addRightNode(root->right,ans);

    return ans;
}

int main(){
     

    return 0;
}