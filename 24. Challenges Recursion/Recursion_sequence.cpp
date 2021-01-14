#include<iostream>
#include<cstring>
using namespace std;

int ans=0;

void subStrings(char a[], char *out, int i, int j){
    //base case
    if(a[i]=='\0'){
        //printing the subString
        out[j] = '\0';
        cout<<out<<" ";
        ans++;
        return;
    }

    //rec case
    out[j] = a[i];
	//placing the same char in jth place
    subStrings(a, out, i+1, j);
    //backtracking
	out[j] = a[i];
    subStrings(a, out, i+1, j+1);
    return;
}

int main(){

    char a[10];
    cin>>a;

    char out[10] = {0};
    subStrings(a, out, 0, 0);
    cout<<endl<<ans<<endl;
}
