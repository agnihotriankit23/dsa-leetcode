#include <bits/stdc++.h>
using namespace std; 

// Depth First Search
void prepareAdjList(unordered_map<int, set<int> > &adjList,vector<vector<int>> &edges){
    for(int i=0;i< edges.size();i++){
        int u= edges[i][0];
        int v = edges[i][1];
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void dfs(int node , unordered_map<int, set<int> > &adjList,unordered_map<int , bool> &visited,vector<int> &component){
    component.push_back(node);
    visited[node]=1;
    
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(i,adjList,visited,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, set<int> > adjList;
    prepareAdjList(adjList,edges);
    
    unordered_map<int , bool> visited;
    vector<vector<int> > ans;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adjList,visited,component);
            ans.push_back(component);
        }
    }
    return ans;
    
    
}

int main(){
     

    return 0;
}