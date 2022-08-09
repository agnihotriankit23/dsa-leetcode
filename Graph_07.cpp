#include <bits/stdc++.h>
using namespace std; 

//Dijkstra Algorithm to find shortest distance in graph
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, set<pair<int,int> > > adjList;
    for(int i=0;i<edges;i++){
        int u= vec[i][0];
        int v= vec[i][1];
        int d= vec[i][2];
        adjList[u].insert(make_pair(v,d));
        adjList[v].insert(make_pair(u,d));
    }
    
    set< pair<int,int> > s;
    vector<int> dist(vertices,INT_MAX);
    
    dist[0]=0;
    s.insert(make_pair(0,0));
   
    while(!s.empty()){
        auto node = *(s.begin());
       // s.pop();
        
        for(auto i:adjList[node.second]){
            if((node.first+i.second)<dist[i.first]){
                dist[i.first]=node.first+i.second;
                s.insert(make_pair(dist[i.first],i.first));
            }
        }
        s.erase(node);
    }
    return dist;
}

int main(){
     

    return 0;
}