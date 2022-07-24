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

int main(){
     

    return 0;
}