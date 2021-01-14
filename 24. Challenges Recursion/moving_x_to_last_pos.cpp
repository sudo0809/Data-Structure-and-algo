#include<iostream>
using namespace std;

void moveX(char in[], char *out, int i, int j, int x_count){
    //base case
    if(in[i]=='\0'){
        //print string
        while(x_count--){
            out[j]='x';
            j++;
        }
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    if(in[i]=='x'){
        x_count++;
        moveX(in,out,i+1,j,x_count);
    }
    else{
        out[j]=in[i];
        moveX(in,out,i+1,j+1,x_count);
    }
    return;
}

int main(){
    char in[10];
    cin>>in;

    char out[10];
    moveX(in, out, 0, 0, 0);
}
