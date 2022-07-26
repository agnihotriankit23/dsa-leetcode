#include <bits/stdc++.h>
using namespace std; 


//Burning Tree Problem


/*

    Node* createMap(Node* root,int target, map<Node*,Node*>& nodeToParent){
        Node* res=NULL;
        
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root]=NULL;
        
        while(!q.empty()){
            
            Node* front= q.front();
            q.pop();
            
            if(front->data== target){
                res=front;
            }
            
            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
            
            
        }
        return res;
    }
    
    int burnTime(Node* root, map<Node*, Node*>& nodeToParent){
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root]=1;
        int ans=0;
        
        while(!q.empty()){
            bool flag=0;
            int size= q.size();
            for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            
            if(temp->left && !visited[temp->left]){
                flag=1;
                visited[temp->left]=1;
                q.push(temp->left);
                
            }
            
            if(temp->right && !visited[temp->right]){
                flag=1;
                visited[temp->right]=1;
                q.push(temp->right);
            }
            
            if(nodeToParent[temp] && !visited[nodeToParent[temp]]){
                flag=1;
                visited[nodeToParent[temp]]=1;
                q.push(nodeToParent[temp]);
            }
            
            }
            if(flag){
                ans++;
            }
        }
        
        return ans;
    }
  
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> nodeToParent;
        Node* targetNode= createMap(root,target,nodeToParent);
        int ans= burnTime(targetNode,nodeToParent);
        return ans;
    }

*/

int main(){
     

    return 0;
}