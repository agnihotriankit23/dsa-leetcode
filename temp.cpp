#include <bits/stdc++.h>
using namespace std; 

class Hero{
    private:
    int health;
    char level;

    public:
    Hero(int health, char level){
        this->health = health;
        this->level = level;
    }

    void print(){
        cout<<"Health : "<<this->health<<endl;
        cout<<"Level : "<<this->level<<endl;
    }
   
};


int main(){
    Hero h1();
    cout<<sizeof(h1)<<endl;   

    return 0;
}