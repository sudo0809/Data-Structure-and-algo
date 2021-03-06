#include<iostream>
#include<cstring>
using namespace std;

void generate_subsequence(char *in, char *out, int i, int j){

    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //rec case
    //include the current char
    out[j]=in[i];
    generate_subsequence(in, out, i+1, j+1);
    //exclude the current char
    generate_subsequence(in, out, i+1, j);
    return ;
}

int main(){
    // char a[1000];
    // cin>>a;
    char input[] = "abc";
    char output[10];
    // int n = strlen(a);
    // cout<<n;
    generate_subsequence(input, output, 0, 0);
    cout<<"--------------";

    return 0;
}
