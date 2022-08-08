#include <bits/stdc++.h>
using namespace std; 


// Topological Sort on  DAG(Directed Acyclic Graph)
void dfs(unordered_map<int, set<int> > &adjList, unordered_map<int,bool> &visited, int node, stack<int> &s){
    visited[node]=1;
    
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList,visited,i,s);
            
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
   unordered_map<int, set<int> > adjList;
    for(int i=0;i<edges;i++){
        int u= graph[i][0];
        int v = graph[i][1];
        
        adjList[u].insert(v);
    }
    stack<int> s;
    unordered_map<int,bool> visited;
    
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            dfs(adjList,visited,i,s);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main(){
     

    return 0;
}