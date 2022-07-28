#include <bits/stdc++.h>
using namespace std; 

class Node{
    public:
    int data;
    Node* left;
    Node*right;

    Node(int d){
        this->data=d;
        this->left=this->right=NULL;
    }

};

//TC for insertion in BST is O( log n )
Node* insertIntoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(data > root->data){
        root->right= insertIntoBST(root->right,data);
    }else{
        root->left= insertIntoBST(root->left,data);
    }
    return root;

}

void takeInput(Node* &root){
    int d;

    cin>>d;
    while(d!=-1){
        root= insertIntoBST(root,d);
        cin>>d;
    }
}
void levelOrdertraversal(Node* root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp=q.front();
       
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

// Search in Binary search

    
    Node* searchBST(Node* root, int val) {
        Node* curr=root;
        
        while(curr!=NULL){
            if(curr->data==val){
                return curr;
            }else if(curr->data > val){
                curr=curr->left;
            }else{
                curr= curr->right;
            }
        }
        return NULL;
    }

// Delete from BST -> Very Important Question for Interview

int findMin(Node* root){
    Node* curr=root;
    if(curr->left!=NULL){
        curr=curr->left;
    }
    return curr->data;
}

Node* deleteNode(Node* root, int val){
    if(root==NULL){
        return NULL;
    }

    if(root->data==val){
        //0 Child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }



        //1 child

        if(root->left!=NULL && root->right==NULL){
            Node* temp = temp->left;
            delete root;
            return temp;
        }

        if(root->left==NULL && root->right!=NULL){
            Node* temp = temp->right;
            delete root;
            return temp;
        }

        //2 child

        if(root->left!=NULL && root->right!=NULL){
            int min=findMin(root->right);
            root->data= min;
            root->right= deleteNode(root->right,min);
            return root;
        }


    }else if(root->data > val){
        root->left=deleteNode(root->left,val);
    }else{
        root->right= deleteNode(root->right,val);
    }
    return root;
}

int main(){
     Node* root=NULL;
     takeInput(root);
     cout<<endl;
    levelOrdertraversal(root);

    root=deleteNode(root,90);

    return 0;
}