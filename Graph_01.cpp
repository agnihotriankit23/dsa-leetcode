#include <bits/stdc++.h>
using namespace std; 
template <typename T>
class graph{
    public:
        unordered_map<T, list<T> > adj;

        void insertAdj(T u , T v , bool direction){
            adj[u].push_back(v);

            if(!direction){
                adj[v].push_back(u);
            }
        }

        void printAdj(){
            for(auto i:adj){
                cout<< i.first << " -> ";
                for(auto j:i.second){
                    cout<<j<<" , ";
                }cout<<endl;
            }
        }
};


int main(){
    /* int n;
    // cout<<"Enter Number of nodes \n";
     //cin>>n;

     int m;
    // cout<<" Enter Number of Edges \n";
    // cin>>m;

     graph<int> g;
    cout<<"-------Enter Edges Now-------\n";
     for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.insertAdj(u,v,0);

     }

     g.printAdj();
*/
    return 0;
}