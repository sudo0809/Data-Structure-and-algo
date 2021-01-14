#include<iostream>
#include<set>
#include<string>
using namespace std;

void permute(char *in, int i, set<string> &s){
    //base case
    if(in[i] == '\0'){
        // cout<<in<<endl;
        string t(in); //initialize t with a
        s.insert(t); // adding t in set s
        return;
    }

    //rec case
    for(int j=i; in[j]!='\0'; j++){
        swap(in[i], in[j]);
        permute(in, i+1, s);
        //Backtracking
        swap(in[i], in[j]); // restoring the original array
    }
    return;
}

int main() {

    char in[100];
    cin>>in;
    set<string> s;

    permute(in, 0, s);

    //looping over the set
    for(auto str:s){
        cout<<str<<",";
    }

    return 0;

}
