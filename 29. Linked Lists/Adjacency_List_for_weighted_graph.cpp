#include<iostream>
#include<list>
using namespace std;


int main(){

    //list of create a graph data structure
    //pointer to an array of Linked list
    list<pair<int, int>> *l;
    int n;
    cin>>n;

    l = new list<pair<int,int>>[n];

    int e;
    cin>>e;
    for(int i=0; i<e; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }

    //print the Linked List
    for(int i=0; i<n; i++){
        //print every Linked List
        cout<<"Linked List "<<i<<" ->";
        for(auto xp:l[i]){
            cout<<"("<<xp.first<<","<<xp.second<<"),";
        }
        cout<<endl;
    }


}
