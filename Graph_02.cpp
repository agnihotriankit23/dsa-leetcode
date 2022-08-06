#include <bits/stdc++.h>
using namespace std; 

// BFS in Graph
void prepareAdjList(unordered_map<int, set<int> > &adjList, vector<pair<int, int>> edges){
    for(int i=0;i< edges.size();i++){
        int u = edges[i].first;
        int v= edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int, set<int> > &adjList,unordered_map<int,bool> &visited, int node, vector<int>& ans){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int frontNode= q.front();
        q.pop();
        
        ans.push_back(frontNode);
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int> > adjList;
    unordered_map<int,bool> visited;
    vector<int> ans;
    
    prepareAdjList(adjList,edges);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,i,ans);
        }
    }
    return ans;
    
    
}



int main(){
     

    return 0;
}