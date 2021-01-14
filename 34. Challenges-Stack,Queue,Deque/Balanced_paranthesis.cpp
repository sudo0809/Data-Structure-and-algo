#include<iostream>
#include<list>
using namespace std;

bool checkBalance(char s[]){

    list<char> stk;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='[' or s[i]=='{' or s[i]=='('){
            stk.push_back(s[i]);
        }
        else if(stk.size()!=0 and s[i]==')' ){
            if(stk.back()=='('){
                stk.pop_back();
            }
            else{return false;}
        }
        else if(stk.size()!=0 and s[i]=='}' ){
            if(stk.back()=='{'){
                stk.pop_back();
            }
            else{return false;}
        }
        else if(stk.size()!=0 and s[i]==']' ){
            if(stk.back()=='['){
                stk.pop_back();
            }
            else{return false;}
        }
    }

    if(stk.size()==0){
        return true;
    }
    return false;
}


int main(){
    char s[100];
    cin>>s;

    if(checkBalance(s)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
