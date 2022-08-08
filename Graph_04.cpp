#include <bits/stdc++.h>
using namespace std; 
// Cycle Detection in Undirected Graph using BFS

#include <bits/stdc++.h>
bool bfs(unordered_map<int,list<int> > &adjList,unordered_map<int,bool> &visited , int node){
    unordered_map<int,int> parent;
   // parent[node]=-1;
    queue<int> q;
    q.push(node);
    visited[node]=1;
    parent[node]=-1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        
        for(auto i: adjList[frontNode]){
            if(visited[i]==true && parent[frontNode]!=i){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i]=1;
                parent[i]=frontNode;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<m;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    //unordered_map<int,int> parent;
    //bool flag=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
    bool flag=   bfs(adjList,visited,i);
         if(flag){
        return "Yes";
    }
    }}
        return "No";
    
}


// Cycle Detection in Undirected Graph using DFS
 bool dfs( vector<int> adj[], unordered_map<int,bool> &visited,int node,unordered_map<int,int> &parent){
        
        visited[node]=1;
        //parent[node]=-1;
        
        for(auto i: adj[node]){
            if(visited[i]==true && parent[node]!=i){
                return true;
            }else if(!visited[i]){
                parent[i]=node;
                if(dfs(adj,visited,i,parent)==true)return true;
            }
        }
       return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                parent[i]=-1;
                 bool ans= dfs(adj,visited,i,parent);
                 if(ans){
                     return 1;
                 }
            }
        }
        return 0;
       
    }
int main(){
     

    return 0;
}