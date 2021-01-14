#include<iostream>
#include<stack>
using namespace std;

bool isValidExp(char *s){
    stack<char> stk;

    for(int i=0; s[i]!='\0'; i++){
        char ch = s[i];

        if(ch=='('){
            stk.push(ch);
        }
        else if(ch==')'){
            if(stk.empty() or stk.top()!='('){
                return false;
            }
            stk.pop();
        }
    }
    if(!stk.empty()){
        return false;
    }
    return true;

}

int main(){

    char s[100] = "((a+b)+(c-d+f))";

    if(isValidExp(s)){
        cout<<"Valid Expression"<<endl;
    }
    else{
        cout<<"Not a Valid Expresion"<<endl;
    }

    return 0;
}
