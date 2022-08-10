#include <bits/stdc++.h>
using namespace std; 

// Count Strongly Connected Components (Kosaraju’s Algorithm)
void topoSort(int node, vector<bool> &vis,unordered_map<int,list<int> > &adjList, stack<int> &st ){
    vis[node]=true;
    
    for(auto nbr: adjList[node]){
        if(!vis[nbr]){
            topoSort(nbr,vis,adjList,st);
        }
    }
    st.push(node);
}
void dfs(int node, vector<bool> &vis, unordered_map<int, list<int> > &transpose){
    vis[node]=true;
    
    for(auto i: transpose[node]){
        if(!vis[i]){
            dfs(i,vis,transpose);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int> > adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    stack<int> st;
    vector<bool> vis(v,false);
    for(int i=0;i<v;i++){
        if(!vis[i]){
              topoSort(i,vis,adjList,st);
        }
    }
    
    unordered_map<int, list<int> > transpose;
    for(int i=0;i<v;i++){
        vis[i]=false;
        for(auto nbr: adjList[i]){
            transpose[nbr].push_back(i);
        }
    }
    
    int cnt=0;
    
    while(!st.empty()){
        int front = st.top();
        st.pop();
        
       
            if(!vis[front]){
                
                dfs(front,vis,transpose);
                cnt++;
            }
        }
    
    return cnt;
  
}

int main(){
     

    return 0;
}