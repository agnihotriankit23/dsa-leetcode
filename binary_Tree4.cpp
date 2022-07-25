#include <bits/stdc++.h>
using namespace std; 

// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)

void solve1(Node* root, int sum, int& maxSum, int len, int& maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen=len;
            maxSum=sum;
        }else if(len==maxLen){
            maxSum=max(sum, maxSum);
        }
        return;
    }

    sum+=root->data;

    solve1(root->left,sum,maxSum,len+1,maxLen);
    solve1(root->right,sum,maxSum,len+1,maxLen);
}

int sumRootToLeaf(Node* root){
    int sum=0;
    int maxSum=INT_MIN;

    int len=0;
    int maxLen=0;
    solve1(root,sum,maxSum,len,maxLen);
    return maxSum;
}

//Lowest common ancestor of a Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        
        if(root->val==p->val || root->val== q->val){
            return root;
        }
        
        TreeNode* leftAns= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns= lowestCommonAncestor(root->right,p,q);
        
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }else{
            return NULL;
        }
        
    }

 // K Sum Path in a Binary Tree

 void solve2(Node* root, int k, int& count, vector<int> path){
    if(root==NULL){
        return;
    }

    path.push_back(root->data);

    solve2(root->left,k,count,path);
    solve2(root->right,k,count,path);

    int size= path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
            sum+=path[i];
            if(sum==k) count++;
    }
 }

 int sumK(Node* root, int k){
    vector<int> path;
    int count=0;

    solve2(root,k,count,path);
    return count;
 }



 // Kth Ancestor in a Tree

Node* solve3(Node* root, int&k ,int node){
    if(root==NULL) return NULL;

    if(root->data==node){
        return root;
    }


    Node* left= solve3(root->left,k,node);
    Node* right= solve3(root->right,K,node);

    if(left!=NULL && right==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }else{
            return left;
        }
    }
    else if(left==NULL && right!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }else{
            return right;
        }
    }
    return NULL;
}

int kthAncestor(Node* root, int k,int node){

    Node* ans= solve3(root,k,node);
    if(ans==NULL) return -1;
    else return ans->data;
}

//Maximum Sum of Non- adjacent Nodes
pair<int,int> solve4(Node* root){
    if(root==NULL){
        pair<int,int> p= make_pair(0,0);
        return p;
    }

    pair<int,int> left= solve4(root->left);
    pair<int,int> right= solve4(root->right);


    pair<int,int> ans;
    ans.first= root->data + left.second + right.second;
    ans.second= max(left.first,left.second)+max(right.first, right.second);

    return ans;
}
int getMaxSum(Node* root){
    pair<int,int > ans;
    ans=solve(root);
    return max(ans.first,ans.second);
}


int main(){
     

    return 0;
}