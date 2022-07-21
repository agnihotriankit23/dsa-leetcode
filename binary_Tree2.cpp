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

//

int main(){



    return 0;
}