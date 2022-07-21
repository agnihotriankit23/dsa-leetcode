#include<bits/stdc++.h>
using namespace std;
// letter combination of a phone number

class Solution {
    private:
    void solve(string digits,string output,int index,vector<string>& ans, string mapping[]){
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }
        
        int number= digits[index] - '0';
        string text=mapping[number];
        for(int i=0;i<text.size();i++){
            output.push_back(text[i]);
            solve(digits,output,index+1,ans,mapping);
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
     vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        solve(digits,output,0,ans,mapping);
        return ans;
        
    }
};
int main(){
    //important question
    string digits="45";
    vector<string> ans;
   
    Solution obj;
     ans= obj.letterCombinations(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}