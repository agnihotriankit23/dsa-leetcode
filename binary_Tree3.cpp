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

// Vertical Order Traversal

vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> result;
        if(root==NULL) return result;
        
        map< int, map<int,vector<int> > > nodes;
        
        queue< pair<Node*, pair<int,int> > >q;
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*, pair<int,int> > temp= q.front();
            q.pop();
            
            Node* front= temp.first;
            int hd= temp.second.first;
            int lvl= temp.second.second;
            
            nodes[hd][lvl].push_back(front->data);
            
            if(front->left){
                q.push(make_pair(front->left,make_pair(hd-1,lvl+1)));
            }
            
            if(front->right){
                q.push(make_pair(front->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i: nodes){
            for(auto j:i.second){
                for(auto k:j.second)
                    result.push_back(k);
            }
        }
        
        return result;
    }

// Top view of Binary tree
  
   vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,int> m;
        
        queue<pair<Node*, int > > q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*, int > temp= q.front();
            q.pop();
            
            Node* front= temp.first;
            int hd= temp.second;
            
            //If one value is already present for hd then do nothing
            if(m.find(hd)==m.end())
            m[hd]=front->data;
            
            if(front->left) q.push(make_pair(front->left,hd-1));
            if(front->right) q.push(make_pair(front->right,hd+1));
        }
        
        for(auto i:m){
            
                ans.push_back(i.second);
            }
        
        return ans;
        
}

//Bottom view of Binary tree

vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL) return ans;
        
        map<int,int> m;
        
        queue<pair<Node*, int> > q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*, int> temp= q.front();
            q.pop();
            Node* front= temp.first;
            int hd= temp.second;
            
            m[hd]=front->data;
            
            if(front->left) q.push(make_pair(front->left,hd-1));
            if(front->right) q.push(make_pair(front->right,hd+1));
        }
        
        for(auto i: m){
            ans.push_back(i.second);
        }
        
        return ans;
    }


    // Left View of Binary tree
    void solveLeft(Node* root,vector<int>& ans, int lvl){
    if(root==NULL) return;
    
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    solveLeft(root->left,ans,lvl+1);
    solveLeft(root->right,ans,lvl+1);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
  solveLeft(root,ans,0);
   return ans;
   
}


//Right View of Binary tree

void solveRight(Node* root,vector<int>& ans, int lvl){
    if(root==NULL) return;
    
    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    solveRight(root->right,ans,lvl+1);
    solveRight(root->left,ans,lvl+1);
    
}

vector<int> rightView(Node *root)
{
   // Your code here
   vector<int> ans;
  solveRight(root,ans,0);
   return ans;
   
}

int main(){
     

    return 0;
}