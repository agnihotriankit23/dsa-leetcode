#include <bits/stdc++.h>
using namespace std; 

// Cycle Detection in Directed Graph

bool checkCycle(unordered_map<int,list<int> > adjList,unordered_map<int,bool> &visited,int node, unordered_map<int,bool> &dfs)
{
    visited[node]=1;
    dfs[node]=1;
    
    for(auto i: adjList[node]){
        if(!visited[i]){
            bool flag=checkCycle(adjList,visited,i,dfs);
            if(flag){
                return true;
            }
            dfs[i]=0;
        }else if( dfs[i]==1){
            return true;
        }
    }
    dfs[node]=0;
    return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e){

	// Write your code here
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<e;i++){
        int u= edges[i][0];
        int v= edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfs;
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            bool ans  = checkCycle(adjList,visited,i,dfs);
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