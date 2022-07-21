#include<bits/stdc++.h>
using namespace std;
// Subsets and subsequences
 void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
        if(index>= nums.size()){
            ans.push_back(output);
            return;
        }
        
        // exclude
        solve(nums,output,index+1,ans);
        
        //Include
        
        int e= nums[index];
        output.push_back(e);
        solve(nums,output,index+1,ans);
    }
     vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        solve(nums,output,index,ans);
        return ans;
     }
     //Subsequences
     void solve(string str,string output,int index,vector<string>& ans){
    if(index>= str.size()){
        if(output!="")
        ans.push_back(output);
        return;
    }
    solve(str,output,index+1,ans);
    
    char e= str[index];
    output.push_back(e);
     solve(str,output,index+1,ans);
}

vector<string> subsequences(string str){
	
	// Write your code here
    vector<string> ans;
    string output="";
    int index=0;
     solve(str,output,index,ans);
//     vector<string> ans1;
//     for(int i=1;)
    return ans;
	
}
int main(){
    
    //make a vector and then pass it function subsets;
    /*vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<vector<int>> ans;
    ans= subsets(v);
    int n=ans.size();
    for(int i=0;i<n;i++){
        int m= ans[i].size();
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    */

    
    return 0;
}