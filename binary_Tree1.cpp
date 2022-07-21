#include<bits/stdc++.h>
using namespace std;

// Creation / Build Binary tree

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildtree(node *root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root= new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in Left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data for inserting in right of "<< data<<endl;
    root->right=buildtree(root->right);
    return root;
}

// 4 Types of Traversal
void levelOrdertraversal(node* root){
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp=q.front();
       
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
            }

            if(temp->right){
            q.push(temp->right);
            }
        }
    }
}


void inordertraversal(node* root){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

void preorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root){
    if(root==NULL){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";

}

//Build Tree using LevelOrder traversal

void buildFromLevelOrder(node* &root){
    queue<node*>  q;
    cout<<"Enter data for root Node: ";
    int data;
    cin>>data;
    root= new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter Left data for: "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left= new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right data for: "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right= new node(rightdata);
            q.push(temp->right);
        }

    }
}

//Function to count number of leaf Nodes in a tree

void solve(node *root,int &ans){
    if(root==NULL){
        return;
    }
     
    solve(root->left,ans);
    if(root->left==NULL && root->right==NULL){
        ans++;
       
    }
   
   
        solve(root->right,ans);
}
int noOfLeafNodes(node *root){
   
    int ans=0;
    solve(root,ans);
    return ans;
}


int main(){
    node* root=NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
   /* root=buildtree(root);

    cout<<"levelOrder Traversal is: ";
    levelOrdertraversal(root);
    cout<<"Inorder Traversal is :";
    inordertraversal(root);
    cout<<endl;

    cout<<"Preorder Traversal is :";
    preorderTraversal(root);
    cout<<endl;

    cout<<"Postorder Traversal is :";
    postorderTraversal(root);
    cout<<endl;
*/
    buildFromLevelOrder(root);
    levelOrdertraversal(root);
    return 0;
}