#include <bits/stdc++.h>
using namespace std; 


// Topological Sort on  DAG(Directed Acyclic Graph)
//Using DFS

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

//Using BFS (Kahns Algorithm)
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> in_degree(V,0);
	  for(int i=0;i<V;i++){
	      for(int j=0;j<adj[i].size();j++){
	          in_degree[adj[i][j]]++;
	      }
	  }
	  queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
     
    vector<int> ans;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto i: adj[front]){
            if(--in_degree[i]==0){
                q.push(i);
            }
        }
    }
    return ans;
	}

int main(){
     

    return 0;
}