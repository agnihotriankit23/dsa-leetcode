#include <bits/stdc++.h>
using namespace std; 


// Prims Algorithm 
// This algorithm is used to find minimum cost of Spanning tree
//Spanning Tree :- We convert Graph to Binary tree with n  nodes and n-1 edges

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    //Create AdjList
    unordered_map<int, list<pair<int,int> > > adjList;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v= g[i].first.second;
        int w= g[i].second;
        
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }
    
    vector<bool> mst(n+1);
    vector<int> key(n+1);
    vector<int> parent(n+1);
    
    for(int i=1;i<=n;i++){
        parent[i]=-1;
        mst[i]=false;
        key[i]=INT_MAX;
    }
    parent[1]=-1;
    key[1]=0;
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        
        mst[u]=true;
        
        for(auto j: adjList[u]){
            int v= j.first;
            int w= j.second;
            if(mst[v]==false && key[v]> w){
                key[v]=w;
                parent[v]=u;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>>  ans;
    for(int i=2;i<=n;i++){
        int x= parent[i];
        int y= i;
        int z= key[i];
        ans.push_back({{x,y},z});
    }
    return ans;
    
}


int main(){
     

    return 0;
}