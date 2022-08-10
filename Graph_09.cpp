#include <bits/stdc++.h>
using namespace std; 


// Bridge in a Graph
 void dfs(int node, int parent,int &timer, vector<int> &low, vector<int> &desc, vector<int> adj[], vector<int> &vis, vector<vector<int>> &result ){
        vis[node]=1;
        low[node]=desc[node]=timer++;
        
        for(auto nbr : adj[node]){
            if(nbr == parent){
                continue;
            }else if(!vis[nbr]){
                dfs(nbr,node, timer, low, desc, adj,vis,result);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>desc[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }else{
                low[node]=min(low[node], desc[nbr]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> low(V,-1);
        vector<int> desc(V,-1);
        int parent= -1;
        int timer=0;
        
        vector<int> vis(V,0);
        
        vector<vector<int> > result;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,parent,  timer, low,desc,adj,vis,result);
            }
        }
        vector<int> ans;
        ans.push_back(c);
        ans.push_back(d);
        vector<int> ans1;
        ans1.push_back(d);
        ans1.push_back(c);
        
        if(find(result.begin(),result.end(),ans)!=result.end() || find(result.begin(),result.end(),ans1)!=result.end()){
            return 1;
        }else{
            return 0;
        }
    }




int main(){
     

    return 0;
}